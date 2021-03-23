#ifndef Calibration_h
#define Calibration_h

#include "Arduino.h"
#include "LiquidCrystal.h"
#include "EEPROM.h"

#ifdef ESP_PLATFORM
#include "Preferences.h"
#define MAX_ANALOG 4095
#define SEUIL_BAS 120
#define SEUIL_HAUT 4000
#else
#define MAX_ANALOG 1023
#define SEUIL_BAS 30
#define SEUIL_HAUT 1000
#endif

class Calibration
{
public:
  Calibration();
#ifdef ESP_PLATFORM
  uint16_t *calibrer(int pin, LiquidCrystal *lcd, const char *name);
#else
  uint16_t *calibrer(int pin, LiquidCrystal *lcd, int eepromAdress);
#endif

private:
  uint16_t _keys_values[5];
#ifdef ESP_PLATFORM
  Preferences preferences;
  void lireEEPROM(const char *location);
  void ecrireEEPROM(const char *location);
#else
  void lireEEPROM(int location);
  void ecrireEEPROM(int location);
#endif
};

#endif