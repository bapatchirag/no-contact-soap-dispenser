/* All timer related functions
 * Timer 0 used for all purposes
 */

/* Initialises Timer0 for delay counting
 * @param: None
 * @return: <void> None
 */
void initTimer() {
	T0PR = 14;					// PCLK = 15 MHz, clock will tick on every 15th high of PCLK, resultant frequency of clock tick = 15 MHz/15 = 1 MHz
	T0CTCR = 0;					// Reset Timer0 to deactivate counting
	T0MCR = 4;					// Stop timer when T0TC = T0MR0
	T0TCR = 2;					// Reset timer
}

/* Introduces a delay of given time in seconds
 * @param time: <int> Time to delay execution of further instructions for, in seconds
 * @return: <void> None
 */
void delay(int time) {	
	T0MR0 = time * 100000;				// Set time to countdown, factor of 100000 to compensate for resultant frequency of clock tick
	T0TCR = 2;					// Reset Timer
	T0TCR = 1;					// Start timer
	while(T0TC != T0MR0);				// Delay
	T0TC = 0;					// Reset counted value
	T0TCR = 2;					// Reset timer	
}	
