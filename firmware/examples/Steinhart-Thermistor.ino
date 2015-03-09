#include "Steinhart-Thermistor/Steinhart-Thermistor.h"

Thermistor Thermistor(A0);

void setup() {
	Serial.begin(9600);
}

void loop() {
	//Always call getResistance() first.
	//It's the only function that read the ADC value.
	//Otherwise you could get a different value for each temperature unit.
	//You can specify a number of samples. Default = 1.
	Thermistor.getResistance();
	Serial.print("Volts: ");
	Serial.println(Thermistor.getVolts();
	Serial.print("Kelvin: ");
	Serial.println(Thermistor.getTempK());
	Serial.print("Celsius: ");
	Serial.println(Thermistor.getTempC());
	Serial.print("Fahrenheit: ");
	Serial.println(Thermistor.getTempF());
	delay(1000);
}
