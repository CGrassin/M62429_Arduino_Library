/*!
 *  This is a library for M62429/FM62429 Serial data control dual electronics volume chips.
 *
 *  Written by CGrassin.
 */

#include "Arduino.h"
#include "M62429.h"

M62429::M62429 (uint8_t pin_clk, uint8_t pin_data){
	_pin_data = pin_data;
	_pin_clk = pin_clk;
}

/*
 * Sets the volume of one on both channel of the 62429.
 * 
 * Parameters:
 * attenuation, from 0 to 83dB
 * both, 0 (default)=both channels or 1=individual
 * channel, 0=channel 1, 1 = channel 2, no effect if both=0
 */
void M62429::_setVolume(uint8_t attenuation, uint8_t channel, uint8_t both){
  uint16_t data_word = 0x00;

  // Sanity checks on parameters
  if(both>1 || channel>1 || attenuation > 83)
  	return;

  // Convert volume to attenuation
  //uint8_t attenuation = (volume > 100) ? 0 : (((volume * 83) / -100) + 83);


  // Build control word (11 bits)
  data_word |= (channel << 0);				// Channel select: 0=ch1, 1=ch2
  data_word |= (both    << 1); 				// Individual/both select: 0=both, 1=individual
  data_word |= ((21 - (attenuation / 4)) << 2); 	// ATT1: coarse attenuator, steps of -4dB
  data_word |= ((3 -  (attenuation % 4)) << 7);  // ATT2: fine attenuator, steps of -1dB)
  data_word |= (0b11 << 9); 				// 2 last bits must be 1

  // Send control word
  for (uint8_t i = 0; i < 11; i++) {
    delayMicroseconds (2);
    digitalWrite (_pin_data, 0);
    delayMicroseconds (2);
    digitalWrite (_pin_clk, 0);
    delayMicroseconds (2);
    digitalWrite (_pin_data, (data_word >> i) & 0x01);
    delayMicroseconds (2);
    digitalWrite (_pin_clk, 1);
  }
  delayMicroseconds (2);
  digitalWrite (_pin_data, 1);
  delayMicroseconds (2);
  digitalWrite (_pin_clk, 0);
}

void M62429::setVolumeBoth(uint8_t attenuation){
  _setVolume(attenuation, 0, 0);
}

void M62429::setVolumeCh1(uint8_t attenuation){
  _setVolume(attenuation, 0, 1);
}

void M62429::setVolumeCh2(uint8_t attenuation){
  _setVolume(attenuation, 1, 1);
}