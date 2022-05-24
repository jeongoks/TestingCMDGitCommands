#include <Arduino.h>

/* Pseudo code:	
	Step 1 -> Save an integer named YEAR and assign it a value of the current year.
	Step 2 -> Make an IF statement which checks if the YEAR can be divided(/) with 4 AND NOT (%) with 100.
	Step 3 -> OR Check in the same IF statement if it can be divided(/) with 400.
	Step 4 -> If above are TRUE then PRINT 'Year is a leap year!'.
	Step 5 -> If above is FALSE then PRINT 'Year is not a leap year!'.
*/
const int pinForDiode = 2;
const int year = 1600;

// millis() setup:
unsigned long previousMillis = 0;
const long interval = 1000;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(pinForDiode, OUTPUT);
}

void loop() {
	unsigned long currentMillis = millis();
	if (currentMillis - previousMillis >= interval)
	{
		// checking if the year is a leap year - calculating it.
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400  == 0))
		{
			digitalWrite(pinForDiode, HIGH);
			Serial.println("Your year is a leap year!");
		}
		else
		{
			digitalWrite(pinForDiode, LOW);
			Serial.println("Your year is NOT a leap year.");
		}
		previousMillis = currentMillis;
	}
}
