# no-contact-soap-dispenser
Implementation of a no contact soap dispenser using an ARM7 LPC2148 microcontroller

## PERIPHERALS USED:
* Stepper motor - Actuating the movement of tap of dispenser
* Ultrasonic sensor - Calculating position of receiver
* Pressure sensor - Calculating amount of soap remaining in dispenser
* Buzzer - Warning alarms

## SETUP:
The stepper motor is to be connected to some mechanism (for example, a rod) which pushes/releases the dispenser tap.

The pressure sensor is to be covered and placed at the bottom of the dispenser container; connecting medium to the LPC2148 also to be covered.

The ultrasonic sensor is to be placed near the tap, to effectively calculate the distance between the receiver and the soap dispenser tap.

The buzzer and the microcontroller itself are to be placed at the back of the dispenser container to prevent any damage to them.

## WORKING:
Upon coming in close proximity to the ultrasonic sensor, the dispenser will automatically dispense soap for a defined period of time (2s).

If soap dispenser is empty, a warning buzzing sound will be heard.

If receiver remains too close to the dispenser for a large period of time, a different warning buzzing sound will be heard.

### ASSUMPTIONS MADE:
1. Number of steps of stepper motor; to be changed according to the mechanism utilised for pushing and releasing the tap of the dispenser.
2. Minimum and maximum distance to be maintained for the dispensing of soap; to be changed according to the specifications of the dispenser.
3. Minium pressure at the bottom of dispenser required to dispense soap; to be changed according to the density of the soap used and the height of the dispenser.
