#ifndef Calibration_h
#define Calibration_h

#include "Arduino.h"
#include "LiquidCrystal.h"
#include "EEPROM.h"

class Calibration
{
public:
  Calibration();
  int * calibrer(int pin, LiquidCrystal* lcd, int eepromAdress);

private:
  int _keys_values[5];
  void lireEEPROM(int address);
  void ecrireEEPROM(int address);

};

#endif