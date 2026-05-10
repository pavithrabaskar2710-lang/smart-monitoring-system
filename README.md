# Energy Monitoring and Overload Protection System using Arduino

PROJECT DESCRIPTION :
This project is an Arduino-based Energy Monitoring and Overload Protection System designed to measure current, calculate power and energy consumption, and detect overload conditions.The system uses an ACS712 current sensor to measure load current and calculates power consumption using Arduino UNO. When the power exceeds a predefined threshold, the system detects overload and activates protection indication.This project is developed for learning embedded systems, energy monitoring, and electrical protection concepts.

## Components Used
- Arduino UNO
- ACS712 Current Sensor
- Breadboard
- LED
- Resistor
- Jumper Wires
- 9V Battery
- Relay Module (future implementation)

  ## Features

- Current Measurement
- Power Calculation
- Energy Calculation
- Overload Detection
- Serial Monitor Output
- LED Indication for Overload

  ## Working Principle

1. ACS712 measures the current flowing through the load.
2. Arduino reads analog sensor values.
3. Sensor values are converted into current.
4. Power is calculated using:

   Power = Voltage × Current

5. Energy consumption is calculated over time.
6. If power exceeds the overload limit, the system detects overload and turns ON the warning LED.

   ## Future Improvements

- Add LCD Display
- Add Relay-based automatic power cutoff
- IoT-based monitoring
- Mobile App integration
- More accurate RMS current calculation
