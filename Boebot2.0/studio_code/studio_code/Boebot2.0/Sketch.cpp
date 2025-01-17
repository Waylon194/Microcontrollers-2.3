﻿/*  Version: 1.0
 *	Made by: Waylon Lodder
 *  Microcontrollers assesment 2020
 */

//Includes
#include <Arduino.h>

//Motors
const int RLmotor = 6;			//Rear left motor
const int RRmotor = 7;			//Rear right motor
const int FRmotor = 8;			//Front right motor
const int FLmotor = 1;			//Front left motor
//LED
const int firstRedLed = 4;		//Brake light
const int secondRedLed = 5;		//Brake light
const int firstWhiteLed = 2;	//Headlight
const int secondWhiteLed = 3;	//Headlight
const int leftBlinkerLed = 0;	//Left blinker
const int rightBlinkerLed = 0;	//Right blinker
const int fistPowerPin = 34;	//First led for power indication
const int secondPowerPin = 36;	//Second led for power indication
const int thirdPowerPin = 38;	//Third led for power indication
const int fourthPowerPin = 40;	//Fourth led for power indication
const int fifthPowerPin = 42;	//Fifth led for power indication
const int sixthPowerPin = 44;	//Sixth led for power indication
const int seventhPowerPin = 46;	//Seventh led for power indication
const int eightPowerPin = 48;	//Eight led for power indication
const int ninthPowerPin = 50;	//Ninth led for power indication
const int tenthPowerPin = 52;	//Tenth led for power indication
//Extra
const int servoPin = 6;			//Pin for front servo
const int irPin = 0;			//Pin for IR receiver
const int hornPin = 24;			//Pin for piezo speaker (used as horn)
//Input variables
const int irInput = 0;
//Test
bool hasRun = false;			//Boolean used to toggle test method

//Note: const has been added, since that was a requirement in the tutorial of uploading to a Arduino (Mega).

//Set all pins as output
void setup() {
	pinMode(RLmotor, OUTPUT);
	pinMode(RRmotor, OUTPUT);
	pinMode(FRmotor, OUTPUT);
	pinMode(FLmotor, OUTPUT);
	pinMode(firstRedLed, OUTPUT);
	pinMode(secondRedLed, OUTPUT);
	pinMode(firstWhiteLed, OUTPUT);
	pinMode(secondWhiteLed, OUTPUT);
	pinMode(leftBlinkerLed, OUTPUT);
	pinMode(rightBlinkerLed, OUTPUT);
	pinMode(servoPin, OUTPUT);
	pinMode(irPin, INPUT);
	pinMode(hornPin, OUTPUT);
	pinMode(fistPowerPin, OUTPUT);
	pinMode(secondPowerPin, OUTPUT);
	pinMode(thirdPowerPin, OUTPUT);
	pinMode(fourthPowerPin, OUTPUT);
	pinMode(fifthPowerPin, OUTPUT);
	pinMode(sixthPowerPin, OUTPUT);
	pinMode(seventhPowerPin, OUTPUT);
	pinMode(eightPowerPin, OUTPUT);
	pinMode(ninthPowerPin, OUTPUT);
	pinMode(tenthPowerPin, OUTPUT);
}

/*
	Movement
*/

//Go forward at given speed
void forward(int speed){
	//Front wheels
	analogWrite(FLmotor, speed);
	analogWrite(FRmotor, speed);
	//Rear wheels
	analogWrite(RRmotor, speed);
	analogWrite(RLmotor, speed);
}

//Go backwards at given speed
void backwards(int speed){
	LightBrakeLights()
	//Front wheels
	analogWrite(FLmotor, speed);
	analogWrite(FRmotor, speed);
	//Rear wheels
	analogWrite(RRmotor, speed);
	analogWrite(RLmotor, speed);
	dimBrakeLights();
}

void turn45right(){
	flashRightBlinker();
	//Move these wheels forward
	analogWrite(FRmotor, 255);
	analogWrite(RRmotor, 255);
	//Move these wheels backwards
	analogWrite(RLmotor, 0);
	analogWrite(FLmotor, 0);
	//TODO: Calculate how long wheels need to run
	//Wait for x seconds
	delay(1);
	turnAllMotorsLow();
}

void turn90right(){
	turn45right();
	turn45right();
}

void turn180right(){
	turn90right();
	turn90right();
}

void turn45left(){
	flashLeftBlinker();
	//Move these wheels forward
	analogWrite(FRmotor, 255);
	analogWrite(RRmotor, 255);
	//Move these wheels backwards
	analogWrite(RLmotor, 1);
	analogWrite(FLmotor, 1);
	//TODO: Calculate how long wheels need to run
	//Wait for x seconds
	delay(1);
	turnAllMotorsLow();
}

void turn90left(){
	turn45left();
	turn45left();
}

void turn180left(){
	turn90left();
	turn90left();
}

/*
	End movement
*/

/*
	Utility
*/

//Turn both headlights ON
void lightHeadLights(){
	digitalWrite(firstWhiteLed, 1);
	digitalWrite(secondWhiteLed, 1);
}

//Turn both headlights OFF
void dimHeadLights(){
	digitalWrite(firstWhiteLed, 0);
	digitalWrite(secondWhiteLed, 0);
}

//Turn both brakelights ON
void LightBrakeLights(){
	digitalWrite(firstRedLed, 1);
	digitalWrite(secondRedLed, 1);
}

//Turn both brakelights OFF
void dimBrakeLights(){
	digitalWrite(firstRedLed, 0);
	digitalWrite(secondRedLed, 0);
}

//Stop all motors
void turnAllMotorsLow(){
	analogWrite(FRmotor, 0);
	analogWrite(RRmotor, 0);
	analogWrite(RLmotor, 0);
	analogWrite(FLmotor, 0);
}

/*
	End utility
*/

/*
	Visual
*/

//Flash front leds
void flashheadlights(){
	lightHeadLights();
	delay(50);
	dimHeadLights();
}

//Flash brake leds
void flashbrakelights(){
	LightBrakeLights();
	delay(50);
	dimBrakeLights();
}

//Flash the left turn signal
void flashLeftBlinker(){
	digitalWrite(leftBlinkerLed, 1);
	delay(50);
	digitalWrite(leftBlinkerLed, 0);
}

//Flash the right turn signal
void flashRightBlinker(){
	digitalWrite(rightBlinkerLed, 1);
	delay(50);
	digitalWrite(rightBlinkerLed, 0);
}

//Method to show power on the segment display
void displayPower(int speed){
	if (speed == 25){
		digitalWrite(fistPowerPin, 1);
	}
	else if (speed == 50){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
	}
	else if (speed == 75){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
		digitalWrite(thirdPowerPin, 1);
	}
	else if (speed == 100){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
		digitalWrite(thirdPowerPin, 1);
		digitalWrite(fourthPowerPin, 1);
	}
	else if (speed == 125){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
		digitalWrite(thirdPowerPin, 1);
		digitalWrite(fourthPowerPin, 1);
		digitalWrite(fifthPowerPin, 1);
	}
	else if (speed == 150){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
		digitalWrite(thirdPowerPin, 1);
		digitalWrite(fourthPowerPin, 1);
		digitalWrite(fifthPowerPin, 1);
		digitalWrite(sixthPowerPin, 1);
	}
	else if (speed == 175){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
		digitalWrite(thirdPowerPin, 1);
		digitalWrite(fourthPowerPin, 1);
		digitalWrite(fifthPowerPin, 1);
		digitalWrite(sixthPowerPin, 1);
		digitalWrite(seventhPowerPin, 1);
	}
	else if (speed == 200){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
		digitalWrite(thirdPowerPin, 1);
		digitalWrite(fourthPowerPin, 1);
		digitalWrite(fifthPowerPin, 1);
		digitalWrite(sixthPowerPin, 1);
		digitalWrite(seventhPowerPin, 1);
		digitalWrite(eightPowerPin, 1);
	}
	else if (speed == 225){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
		digitalWrite(thirdPowerPin, 1);
		digitalWrite(fourthPowerPin, 1);
		digitalWrite(fifthPowerPin, 1);
		digitalWrite(sixthPowerPin, 1);
		digitalWrite(seventhPowerPin, 1);
		digitalWrite(eightPowerPin, 1);
		digitalWrite(ninthPowerPin, 1);
	}
	else if (speed == 250){
		digitalWrite(fistPowerPin, 1);
		digitalWrite(secondPowerPin, 1);
		digitalWrite(thirdPowerPin, 1);
		digitalWrite(fourthPowerPin, 1);
		digitalWrite(fifthPowerPin, 1);
		digitalWrite(sixthPowerPin, 1);
		digitalWrite(seventhPowerPin, 1);
		digitalWrite(eightPowerPin, 1);
		digitalWrite(ninthPowerPin, 1);
		digitalWrite(tenthPowerPin, 1);
	}
	else {
		digitalWrite(fistPowerPin, 0);
		digitalWrite(secondPowerPin, 0);
		digitalWrite(thirdPowerPin, 0);
		digitalWrite(fourthPowerPin, 0);
		digitalWrite(fifthPowerPin, 0);
		digitalWrite(sixthPowerPin, 0);
		digitalWrite(seventhPowerPin, 0);
		digitalWrite(eightPowerPin, 0);
		digitalWrite(ninthPowerPin, 0);
		digitalWrite(tenthPowerPin, 0);
	}
}

/*
	End visual
*/

/*
	Audio
*/

//Honk for give time (in ms)
void horn(int time){
	tone(hornPin, 261); //Middle C
	delay(time);
	noTone(hornPin); //stop
}

/*
	End audio
*/

void loop() {
	irInput = analogRead(irPin);
	//Implement IR code to handle all the remote input
	case switch (irInput)
	{
	case F:
		forward(255);
		break;
	case B:
		backwards(255);
		break;
	case L:
		turn90left();
		break;
	case R:
		turn90right();
		break;
	}

	//Test code, will only run once
	if (hasRun == false)
	{
		for (int i = 0; i < 250; i+= 25)
		{
			displayPower(i);
			delay(200);
		}
		displayPower(255);
		horn(400);

		//Only add code to test above this comment
		//Keep this flag
		hasRun = true;
	}
}