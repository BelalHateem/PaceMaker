# Pacemaker

## Overview

This project is a digital pacemaker simulation implemented in both **SCCharts** and **C**, designed to mimic the key functionalities of a real-world pacemaker. The system controls atrial and ventricular pacing, ensuring accurate timing intervals based on various physiological events. Both implementations were tested on an FPGA to validate real-time performance.

## Project Structure

The project includes the following components:

- **SCCharts Implementation:** A model built with SCCharts, which defines the pacemaker’s timing and pacing behavior using state-based logic.
- **C Implementation:** A low-level implementation in C, generated from SCCharts, optimized for hardware and tested on an FPGA.
- **FPGA Testing:** Both implementations were tested on an FPGA to ensure accurate timing and reliable performance.

## Key Components and Functionality

### Inputs and Outputs

- **Inputs:**
  - `AS` - Atrial Sense: Detects an atrial event.
  - `VS` - Ventricular Sense: Detects a ventricular event.

- **Outputs:**
  - `AP` - Atrial Pace: Signals an atrial pacing event.
  - `VP` - Ventricular Pace: Signals a ventricular pacing event.

### Timing Intervals

The pacemaker relies on various timing intervals to manage pacing and refractory periods, simulating realistic heart-pacing conditions:

- **AVI (Atrioventricular Interval):** Delay between an atrial event and a ventricular pacing event.
- **AEI (Atrial Escape Interval):** Time before an atrial pacing event is triggered if no atrial activity is detected.
- **PVARP (Post Ventricular Atrial Refractory Period):** Prevents atrial sensing shortly after a ventricular event.
- **VRP (Ventricular Refractory Period):** Prevents ventricular sensing immediately after a ventricular event.
- **LRI (Lower Rate Interval):** Ensures a minimum heart rate by timing atrial events.
- **URI (Upper Rate Interval):** Limits the maximum pacing rate for the ventricles.

## Implementation Details

### SCCharts Implementation

The SCCharts model defines regions for each timing interval, including AVI, AEI, PVARP, VRP, LRI, and URI. Each region includes its own clock and state machine to handle specific transitions based on input events:

- **rAVI Region:** Manages timing for the atrioventricular interval, ensuring ventricular pacing occurs after an atrial event based on the AVI timer.
- **rPVARP and rVRP Regions:** Control refractory periods, preventing immediate sensing after pacing events.
- **rAEI, rLRI, and rURI Regions:** Manage timing intervals to ensure appropriate pacing rates, including upper and lower rate limits.

### C Implementation

The C implementation was generated from the SCCharts model and optimized for FPGA testing. It uses conditional statements and timing variables to emulate the SCCharts logic:

- **logic() Function:** Handles all state transitions and timing checks for each interval.
- **reset() Function:** Initializes timing intervals and state variables for consistent operation.
- **tick() Function:** Advances the pacemaker’s state based on input events and timing, allowing real-time responses on the FPGA.

This implementation is highly efficient, allowing precise timing and control in an embedded environment.

## Project Files

- **SCCharts Implementation:** `Pacemaker.sccharts`
- **C Implementation:** `pacemaker.c`
- **Timing Library:** `timing.h` - Manages timing intervals in the C code.

## FPGA Testing

Both the SCCharts and C implementations were tested on an FPGA to confirm their real-time capabilities and accurate timing. FPGA testing ensures reliable operation for each pacing event by validating the pacemaker's response to simulated atrial and ventricular inputs.

## Usage

1. **Configure Timing Intervals:**
   - Set values for `AVI_VALUE`, `AEI_VALUE`, `PVARP_VALUE`, `VRP_VALUE`, `LRI_VALUE`, and `URI_VALUE` in `timing.h`.

2. **Compile and Load:**
   - For SCCharts: Synthesize the SCCharts model and load it onto the FPGA.
   - For C: Compile the C code and load it onto the FPGA.

3. **Simulate Inputs:**
   - Provide test inputs for `AS` and `VS` to simulate atrial and ventricular events.

4. **Monitor Outputs:**
   - Observe the `AP` and `VP` signals to confirm correct pacing responses.

## Requirements

- **FPGA Board:** Supports both SCCharts and C implementations.
- **SCCharts Toolchain:** Required for synthesizing SCCharts.
- **C Compiler:** Required for compiling the C code.
- **Timing Library (`timing.h`):** Manages timing intervals for the C implementation.

## Future Improvements

- **Extended Testing:** Additional tests with diverse heart signal patterns to ensure robustness across various heart rhythms.
- **Code Optimization:** Further optimize the C code to reduce power consumption and increase efficiency on the FPGA.
- **Real-Time Monitoring Interface:** Add a user interface for visualizing pacemaker state transitions in real-time.
