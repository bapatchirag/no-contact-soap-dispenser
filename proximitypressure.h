/* Distance and pressure sensor functions
 * Ultrasonic distance sensor connected to ADC channel AD1.1
 * Pressure sensor connected to ADC channel AD1.2
 */

#define MINPRESSURE 50
#define MINDISTANCE 1000
#define MAXDISTANCE 400

/* Obtain distance from ultrasonic sensor
 * @param: None
 * @return: <int> Distance from tap in the range of 0 to 1023
 */
int getDistance() {
	PINSEL0 |= (3 << 16);													// Select option 3 of P0.8 - AD1.1
	int distance;																	// Distance value from distance sensor
	
	AD1CR = (1 << 1) | (1 << 21) | (1 << 24);			// D1: Select AD1.1; D21: ADC activate; D24: Start of Conversion
	while(!(AD1DR1 & (1u << 31)));								// Obtain values while End of Conversion at D31 is not reached
	distance = (AD1DR1 >> 6) & 0x3FF;							// AD1.1 result
	
	return distance;
}

/* Obtain pressure from pressure sensor
 * @param: None
 * @return: <int> Pressure of soap above the bottom of dispenser
 */
int getPressure() {
	PINSEL0 |= (3 << 20);													// Select option 3 of P0.10 - AD1.2
	int pressure;																	// Pressure value from pressure sensor
	
	AD1CR = (1 << 2) | (1 << 21) | (1 << 24);			// D1: Select AD1.2; D21: ADC activate; D24: Start of Conversion
	while(!(AD1DR2 & (1u << 31)));								// Obtain values while End of Conversion at D31 is not reached
	pressure = (AD1DR2 >> 6) & 0x3FF;							// AD1.2 result
	
	return pressure;
}
