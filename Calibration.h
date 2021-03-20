#ifndef Calibration_h
#define Calibration_h

#include "Arduino.h"
#include "LiquidCrystal.h"
#include "EEPROM.h"

class Calibration
{
public:
  Calibration();
  int * calibrer(LiquidCrystal* lcd, int eepromAdress);

private:
  int _keys_values[5];
  int lireAnalog();
  void lireEEPROM(int address);
  void ecrireEEPROM(int address);

};

#endif