/* All timer related functions
 * Timer 0 used for all purposes
 */

/* Initialises Timer0 for delay counting
 * @param: None
 * @return: <void> None
 */
void initTimer() {
	T0CTCR = 0;					// Reset Timer0 to deactivate counting
	T0MR0 = 499999;			// Limit count calculation for 100 ms
	T0MCR = 4;					// Stop timer when T0TC = T0MR0
	T0TCR = 2;					// Reset timer
}

/* Introduces a delay of given time in seconds
 * @param time: <int> Time to delay execution of further instructions for, in seconds
 * @return: <void> None
 */
void delay(int time) {	
	T0TCR = 2;									// Reset Timer
	T0TCR = 1;									// Start timer
	while(T0TC != T0MR0);				// Delay
	T0TC = 0;										// Reset counted value
	T0TCR = 2;									// Disable timer	
}	
