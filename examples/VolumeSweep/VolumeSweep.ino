/*!
 *  This is a library for M62429/FM62429 Serial data control dual electronics volume chips.
 *
 *  Written by CGrassin.
 */

#include <M62429.h>

/*
Wiring: 
* clock_pin (pin 5 of M62429) to any digital pin of the Arduino
* data_pin  (pin 4 of M62429) to any digital pin of the Arduino

Set the numbers of the pins in the variables
below.
*/

static const uint8_t clock_pin = 4;
static const uint8_t data_pin  = 5;

M62429 chip (clock_pin, data_pin); 

void setup (void){}

void loop (void)
{
	// Function setVolume takes an attenuation 
	// as argument, that ranges between 0 and 83.
	// 0 is max, 83 in minimum volume (-83dB).
	for(int i=0;i<=83;i++) {
		chip.setVolumeBoth(i);
		//chip.setVolumeCh1(i);
		//chip.setVolumeCh2(i);
		delay(10);
	}

	for(int i=83;i>=0;i--) {
		chip.setVolumeBoth(i);
		//chip.setVolumeCh1(i);
		//chip.setVolumeCh2(i);
		delay(10);
	}

}