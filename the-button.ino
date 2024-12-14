#include "Keyboard.h"
#include "EEPROM.h"
#include "christmasMode.h"

int LEDPin = 17;
int buttonPin = 14;
bool latch = false;
int debounce = 0;
int selectedKey = ' ';
#define DEBOUNCE_MS 16

void setup()
{
	pinMode(LEDPin, OUTPUT);
	pinMode(buttonPin, INPUT_PULLUP);

	selectedKey = EEPROM[0];

	Serial.begin(9600);
	Keyboard.begin();

	if (digitalRead(buttonPin) == LOW)
	{
		StartChristmasMode();
		latch = true;
	}
}

void ButtonPressed()
{
	debounce = millis();
	Keyboard.press(selectedKey);
	StopChristmasMode();
}

void ButtonReleased()
{
	debounce = millis();
	Keyboard.release(selectedKey);
}

bool welcome = false;

void loop()
{
	if (Serial && !welcome)
	{
		welcome = true;
		Serial.println("Connected successfully!");
		Serial.println("Enter a key to set the default key for the button");
	}

	if (Serial.available() > 0)
	{
		int c = Serial.read();
		if (c != '\r' && c != '\n')
		{
			selectedKey = c;
			EEPROM.write(0, c);
			Serial.print("New key set to '");
			Serial.print((char)c);
			Serial.println("'");
		}
	}

	if (millis() - debounce > DEBOUNCE_MS)
	{
		if (digitalRead(buttonPin) == LOW)
		{
			if (!latch)
				ButtonPressed();
			latch = true;
		}
		else
		{
			if (latch)
				ButtonReleased();
			latch = false;
		}
	}

	SnowFall();

	digitalWrite(LEDPin, ((millis() % 1000) > 500 ? HIGH : LOW));
}
