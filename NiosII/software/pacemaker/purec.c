/*
 * purec.c
 *
 *  Created on: 3/10/2023
 *      Author: hmue642
 */

#include "purec.h"
#include "timing.h"
#include "system.h"
#include <stdbool.h>
#include <stdio.h>
#include <sys/alt_alarm.h>

extern bool AS;
extern bool VS;
extern bool AP;
extern bool VP;

bool StartSensingAS = true;
bool StartSensingVS = true;


static int AVICount = 0;
static int PVARPCount = 0;
static int VRPCount = 0;
static int AEICount = 0;
static int LRICount = 0;
static int URICount = 0;

static bool initial = true;
//static bool extendAVI = false;
static bool ASensed = false;
static bool VSensed = false;
//static bool fixPlease = false;

static bool AVITimerExpired = false;
static bool PVARPTimerExpired = false;
static bool VRPTimerExpired = false;
static bool AEITimerExpired = false;
static bool LRITimerExpired = false;
static bool URITimerExpired = true;

static bool AVIRunning = false;
static bool PVARPRunning = false;
static bool VRPRunning = false;
static bool AEIRunning = false;
static bool LRIRunning = false;
static bool URIRunning = false;

alt_alarm AVI_TIMER;
alt_alarm PVARP_TIMER;
alt_alarm VRP_TIMER;
alt_alarm AEI_TIMER;
alt_alarm LRI_TIMER;
alt_alarm URI_TIMER;

void* AVIContext = (void*) &AVICount;
void* PVARPContext = (void*) &PVARPCount;
void* VRPContext = (void*) &VRPCount;
void* AEIContext = (void*) &AEICount;
void* LRIContext = (void*) &LRICount;
void* URIContext = (void*) &URICount;

typedef enum{
init,
atrialPulseState,
AVIStart,
StartOtherTimers,
StopTimersAfterV,
StopTimersAfterA,
ventriculPulseState,
extendAVITimer,
}paceMakerState;

paceMakerState currentState = init;

alt_u32 AVI_ISR(void* context) {
	AVITimerExpired = true;
	alt_alarm_stop(&AVI_TIMER);
	AVIRunning = false;
	return 0; // the next time out will be AVI VALUE ms
}

alt_u32 PVARP_ISR(void* context) {
	PVARPCount = 0;
	PVARPTimerExpired = true;
	StartSensingAS = true;
	alt_alarm_stop(&PVARP_TIMER);
	PVARPRunning = false;
	return 0;
}

alt_u32 VRP_ISR(void* context) {
	VRPCount = 0;
	VRPTimerExpired = true;
	alt_alarm_stop(&VRP_TIMER);
	StartSensingVS = true;
	VRPRunning = false;
	return 0;
}

alt_u32 AEI_ISR(void* context) {
	AEICount = 0;
	AEITimerExpired = true;
	alt_alarm_stop(&AEI_TIMER);
	AEIRunning = false;
	return 0;
}

alt_u32 LRI_ISR(void* context) {
	LRICount = 0;
	LRITimerExpired = true;
	alt_alarm_stop(&LRI_TIMER);
	LRIRunning = false;
	return 0;
}

alt_u32 URI_ISR(void* context) {
	URICount = 0;
	URITimerExpired = true;
	alt_alarm_stop(&URI_TIMER);
	URIRunning = false;
	return 0;
}

void startAVITimer(){
	//start the timer, with timeout of AVI_VALUE in ms
	AVITimerExpired = false;
	AVICount = 0;
	AVIRunning = true;
	alt_alarm_start(&AVI_TIMER, AVI_VALUE, AVI_ISR, AVIContext);
}

void startPVARPTimer(){
	//start the timer, with timeout of PVARP_VALUE in ms
	PVARPTimerExpired = false;
	PVARPCount = 0;
	StartSensingAS = false;
	PVARPRunning = true;
	alt_alarm_start(&PVARP_TIMER, PVARP_VALUE, PVARP_ISR, PVARPContext);
}

void startVRPTimer(){
	//start the timer, with timeout of VRP_VALUE in ms
	VRPTimerExpired = false;
	StartSensingVS = false;
	VRPCount = 0;
	VRPRunning = true;
	alt_alarm_start(&VRP_TIMER, VRP_VALUE, VRP_ISR, VRPContext);
}


void startAEITimer(){
	//start the timer, with timeout of AEI_VALUE in ms
	AEITimerExpired = false;
	AEICount = 0;
	AEIRunning = true;
	alt_alarm_start(&AEI_TIMER, AEI_VALUE, AEI_ISR, AEIContext);
}

void startLRITimer(){
	//start the timer, with timeout of LRI_VALUE in ms
	LRITimerExpired = false;
	LRICount = 0;
	LRIRunning = true;
	alt_alarm_start(&LRI_TIMER, LRI_VALUE, LRI_ISR, LRIContext);
}

void startURITimer(){
	//start the timer, with timeout of URI_VALUE in ms
	URITimerExpired =false;
	URICount = 0;
	URIRunning = true;
	alt_alarm_start(&URI_TIMER, URI_VALUE, URI_ISR, URIContext);
}

void pacemaker(){
	switch(currentState){
		case init:
			if(StartSensingAS){
				if((AS)&&initial){
					currentState = AVIStart;
					break;
				}
				if(AP||ASensed){
					AP = false;
					ASensed = false;
					currentState = AVIStart;
					break;
				}
			}
			if(StartSensingVS){
				if(initial){
					currentState = init;
					break;
				}else{
					if(VP||VSensed){
					VP = false;
					VSensed = false;
					currentState = StartOtherTimers;
					break;
					}
				}
			}
			break;

		case atrialPulseState:
			if(initial){
				if(StartSensingVS){
					if((AVITimerExpired == true)&&(!VS)){
						initial = false;
						VP = true;
						currentState = StopTimersAfterV;
						break;
					}
					if((AVITimerExpired ==false)&&(VS)){
						initial = false;
						VSensed =true;
						currentState = StopTimersAfterV;
						break;
					}
					currentState = atrialPulseState;
					break;
				}else{
					currentState = atrialPulseState;
					break;
				}
			}else{
				if(StartSensingVS){
					if((URITimerExpired == false)){
						//case where we extend AVITimer is most important so check for Expirey of AVITimer
						//And Not the expirey of URITimer First
						if(AVITimerExpired==true){
							currentState = extendAVITimer;
							break;
						}
						currentState = atrialPulseState;
						break;
					}else{
						if(LRITimerExpired==false){
							if((AVITimerExpired==true)&&(!VS)){
								printf("Im here\r\n");
								VP = true;
								currentState = StopTimersAfterV;
								break;
							}
							if((AVITimerExpired ==false)&&(VS)){
								VSensed =true;
								currentState = StopTimersAfterV;
								break;
							}
						}else{
							VP = true;
							currentState = StopTimersAfterV;
							break;
						}
						currentState = atrialPulseState;
						break;
					}
				}else{
					//loop until we startSensingVS
					currentState = atrialPulseState;
					break;
				}
			}
			break;

		case extendAVITimer:
			if(StartSensingVS){
				if(URITimerExpired == false){
					currentState = extendAVITimer;
					break;
				}else{
					if(!VS){
						VP = true;
						currentState = StopTimersAfterV;
						break;
					}
					if(VS){
						VSensed=true;
						currentState = StopTimersAfterV;
						break;
					}
					currentState = extendAVITimer;
				}
			}else{
				currentState = extendAVITimer;
				break;
			}
			break;

		case AVIStart:
			if(AVIRunning ==false){
				startAVITimer();
			}
			currentState = atrialPulseState;
			break;

		case StartOtherTimers:
			if(AEIRunning == false){
			   startAEITimer();
			}
			if(URIRunning == false){
				startURITimer();
			}
			if(LRIRunning ==false){
				startLRITimer();
			}
			if(VRPRunning ==false){
				startVRPTimer();
			}
			if(PVARPRunning ==false){
				startPVARPTimer();
			}
			currentState = ventriculPulseState;
			break;

		case StopTimersAfterV:

			if(AVIRunning ==true){
				alt_alarm_stop(&AVI_TIMER);
				AVIRunning = false;
				AVITimerExpired=true;
			}

			if(AEIRunning == true){
				alt_alarm_stop(&AEI_TIMER);
				AEIRunning = false;
				AEITimerExpired=true;
			}

			if(URIRunning == true){
				alt_alarm_stop(&URI_TIMER);
				URIRunning = false;
				URITimerExpired=true;
			}

			if(LRIRunning ==true){
				alt_alarm_stop(&LRI_TIMER);
				LRIRunning = false;
				LRITimerExpired=true;
			}
			currentState = init;
			break;

		case StopTimersAfterA:

			if(AEIRunning == true){
				alt_alarm_stop(&AEI_TIMER);
				AEIRunning =false;
				AEITimerExpired=true;
			}
			currentState = init;
			break;

		case ventriculPulseState:
			if(StartSensingAS){
				if(AEITimerExpired==true){
					if(!AS){
						AP = true;
						currentState = StopTimersAfterA;
						break;
					}
				}else{
					if(AS){
						ASensed = true;
						currentState = StopTimersAfterA;
						break;
					}
				}
			}else{
				currentState = ventriculPulseState;
				break;
			}
			break;
	}
}
