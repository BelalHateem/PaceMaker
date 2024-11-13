/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <system.h>
#include <stdbool.h>
#include "sys/alt_alarm.h"
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_uart_regs.h>
#include <sys/alt_irq.h>
#include <alt_types.h>

#include "purec.h"
#include "sccharts.h"

bool AS;
bool VS;

bool AP;
bool VP;

static bool APout = false;
static bool VPout = false;

static char mode; // 1 is buttons, 2 is UART 		-- based on switch 0

static TickData td;

void reset_AP();
void reset_VP();

void init_purec();
void start_purec();
void stop_purec();

void init_sccharts();

static alt_u32 timer_tick_ms(void* context);

static volatile bool ASint = false;
static volatile bool VSint = false;

void uart_com(void* context, alt_u32 id)
{
	char inchar = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);

	ASint = false;
	VSint = false;

	if (inchar == 'A') {
		ASint = true;
		printf("got A\n");
	}

	if (inchar == 'V') {
		VSint = true;
		printf("got V\n");
	}
}

int asr = 0;
int vsr = 0;
int main()
{
	void* uart_con; // cast before passing to ISR
	alt_irq_register(UART_IRQ, uart_con, uart_com);

	printf("Hello from Nios II!\n");

	uint keys;
	uint switches;

	bool key0;
	bool key1;
	bool sw0;
	bool sw1;

	bool bsccharts = false;
	alt_alarm one_ms_timer;
	void* timerContext;

	init_sccharts();
	init_purec();

	while(true) {

		switches = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
		sw0 = ((switches & ( 1 << 0 )) >> 0);
		sw1 = ((switches & ( 1 << 1 )) >> 1);

		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, sw0 | (sw1 << 1));

		// LED0 off
		if (sw0 == 0) {
			mode = 1;
		// LED) on
		} else {
			mode = 2;
		}


		if (mode == 1) {
			keys = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			key0 = !((keys & ( 1 << 0 )) >> 0);
			key1 = !((keys & ( 1 << 1 )) >> 1);

			AS = key0;
			VS = key1;
		} else if (mode == 2) {
			AS = ASint;
			VS = VSint;
		}

		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, AS | (VS << 1) | (APout << 2) | (VPout << 3));


		// 0 is SCCharts, 1 is pure c	-- based on swtich 1
		if (sw1 == 0) {
			stop_purec();

			if (!bsccharts) {
				init_sccharts();
				alt_alarm_start(&one_ms_timer, 1, timer_tick_ms, timerContext);
				bsccharts = true;
			}
		} else {
			bsccharts = false;
			alt_alarm_stop(&one_ms_timer);
			pacemaker();
		}


		// sending AP and VP over UART
		if (mode == 2) {
			if (AP) {
				IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, 'A');
			}

			if (VP) {
				IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, 'V');
			}
		}


		// LED reseting
		if(!APout) { APout = AP; }
		if(!VPout) { VPout = VP; }

		if (APout) { reset_AP(); }
		if (VPout) { reset_VP(); }

		int COUNTR = 2000;
		if (ASint) {
			if (asr++ > COUNTR) {
				asr = 0;
				ASint = false;
			}
		}
		if (VSint) {
			if (vsr++ > COUNTR) {
				vsr = 0;
				VSint = false;
			}
		}
	}

	return 0;
}

void start_purec() {
	APout = true;
	VPout = true;
}

void stop_purec() {

}

void init_purec() {

}

alt_u32 timer_tick_ms(void* context) {
	td.AS = AS;
	td.VS = VS;

	tick(&td);

	AP = td.AP;
	VP = td.VP;

	return 1; // the next time out will be 1 milli-seconds
}

void init_sccharts() {
	reset(&td);
	td.deltaT = 1.0;
}

static const uint RESET_TIME = 4000;
static int VPclk = 0;
void reset_VP() {
	if (VPclk > RESET_TIME) {
		VPclk = 0;
		VPout = false;
	}
	VPclk++;
}

static int APclk = 0;
void reset_AP() {
	if (APclk > RESET_TIME) {
		APclk = 0;
		APout = false;
	}
	APclk++;
}
