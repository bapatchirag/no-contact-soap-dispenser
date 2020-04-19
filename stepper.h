/* Activate Stepper Motor for soap dispensing actuation
 * Single stepper motor used to press and release the dispenser
 * Connected to P0.16 to P0.19
 */
 
#define STEPS 50

/* Actuate clockwise rotation of stepper to push down tap
 * @param: None
 * @return: <void> None
 */
void dispense() {
	IO0DIR |= 0xF0000;						// Set P0.16 to P0.19 as output
	int step_count = STEPS;
	
	while(1) {
		int i, to_shift = 1;		
		for(i = 0; i < 4 && --step_count; i++) {
			IO0CLR = 0xF0000;				// Clear all concerned pin values
			IO0SET = to_shift << 16;			// Sets appropriate direction pin
			to_shift *= 2;
		}
		
		if(!(--step_count))
			break;
	}
	
	IO0CLR = 0xF0000;						// Resets all concerned pins
}

/* Actuate anti-clockwise rotation of stepper to release tap
 * @param: None
 * @return: <void> None
 */
void release() {
	IO0DIR |= 0xF0000;						// Set P0.16 to P0.19 as output
	int step_count = STEPS;
	
	while(1) {
		int i, to_shift = 8;		
		for(i = 0; i < 4 && --step_count; i++) {
			IO0CLR = 0xF0000;				// Clear all concerned pin values
			IO0SET = to_shift << 16;			// Sets appropriate direction pin
			to_shift /= 2;
		}
		
		if(!(--step_count))
			break;
	}
	
	IO0CLR = 0xF0000;						// Resets all concerned pins
}
