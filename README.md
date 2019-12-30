# M62429 Arduino Library

A simple and very light Arduino library for the FM62429 or M62429P/FP serial data control dual electronics volume chip.

To install it, download the content of the repository in ZIP, open the Arduino IDE, open "Sketch" > "Include Library" > "Add .ZIP Library" and select the ZIP file.

To get started, open the "VolumeSweep" example, included in this library.

## Detailed functions

Three functions can be called on a M62429 object:
* `setVolumeBoth(uint8_t attenuation)`: sets the volume of both channels
* `setVolumeCh1 (uint8_t attenuation)`: only sets the volume of channel 1
* `setVolumeCh2 (uint8_t attenuation)`: only sets the volume of channel 2

**attenuation** is an integer between 0 and 83, in decibels. 0 is the maximum volume and 83 is the minimum.

## License

This library's license is MIT: licensed works, modifications, and larger works may be distributed under different terms and without source code.