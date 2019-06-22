#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>

#define THERMISTER_PIN 0

Adafruit_ADS1115 ads(0x48);

void setup() {
	// put your setup code here, to run once:
	Serial.begin(115200);
	ads.begin();
}

void loop() {
	// put your main code here, to run repeatedly:
	int16_t adc0;
	adc0 = ads.readADC_SingleEnded(THERMISTER_PIN);
	// I'm using the value 17480 because that value is close to the voltage
	// reading of 3.3V
	float voltage = adc0 * (3.3 / 17480);

	Serial.print("AIN0: ");
	Serial.print(adc0);
	Serial.print("\tVoltage: ");
	Serial.println(voltage);

	delay(100);
}