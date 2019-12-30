/*!
 *  This is a library for M62429/FM62429 Serial data control dual electronics volume chips.
 *
 *  Written by CGrassin.
 */

#ifndef M62429_H
#define M62429_H

#include "Arduino.h"

class M62429 {
public:
  M62429(uint8_t pin_data, uint8_t pin_clk);
  void setVolumeBoth(uint8_t attenuation);
  void setVolumeCh1 (uint8_t attenuation);
  void setVolumeCh2 (uint8_t attenuation);
  
private:
  uint8_t _pin_data, _pin_clk;
  void _setVolume(uint8_t attenuation, uint8_t channel, uint8_t both);
};

#endif
