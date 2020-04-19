/* Main controller program for handless soap dispenser
 * Dispenses soap upon close proximity to dispenser
 * Stepper motor drives a piston to dispense soap when proximity is achieved
 * Buzzer ring when bottle is empty
 * Buzzer ring when proximity is maintained for too long
 *
 * Author: Chirag Bapat
 * Date of creation: 15th April, 2020
 */

#include <lpc214x.h>
#include "buzzer.h"
#include "proximitypressure.h"
#include "stepper.h"
#include "timing.h"

// Distance and pressure helpers
int isEmpty(void);
int isInRange(void);
int canDispense(void);

// Buzzer helpers
void ringEmpty(void);
void ringTime(void);

// Main function, start of execution
int main() {
	initTimer();
	
	while(1) {
		while(isEmpty())
			ringEmpty();
		
		if(canDispense()) {
			delay(1);
			dispense();
			delay(3);
			release();
			
			while(isInRange())
				ringTime();
		}
	}

	return 0;
}

/* Checks if dispenser bottle is empty
 * @param: None
 * @return: <int> 1 if it is empty, 0 otherwise
 */
int isEmpty() {
	if(getWeight() <= MINWEIGHT)
		return 1;
	return 0;
}

/* Checks if receiver of soap is in range of dispenser
 * @param: None 
 * @return: <int> 1 if in range, 0 otherwise
 */
int isInRange() {
	int cur_distance = getDistance();
	
	if(cur_distance < MAXDISTANCE && cur_distance > MINDISTANCE)
		return 0;
	return 1;
}

/* Checks if conditions are ideal to dispense soap
 * @param: None
 * @return: <int> 1 if dispensing is possible, 0 otherwise
 */
int canDispense() {
	if(!isEmpty() || isInRange())
		return 1;
	return 0;
}

/* Buzzer ring style for empty dispenser bottle signal
 * @param: None
 * @return: <void> None
 */
void ringEmpty() {
	startBuzzer(EMPTYBUZZER);
	delay(2);
	stopBuzzer();
}

/* Buzzer ring style for long duration dispense signal
 * @param: None
 * @return: <void> None
 */
void ringTime() {
	startBuzzer(TIMEBUZZER);
	delay(1);
	stopBuzzer();
}
