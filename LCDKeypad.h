#ifndef LCDKeypad_h
#define LCDKeypad_h

#include "Arduino.h"
//#include "EEPROM.h"

#include "Calibration.h"
#include "LiquidCrystal.h"
#include "BoutonLCD.h"
#include "EcranLCD.h"
#include "Del.h"


#define PIN_KEYPAD 0
#define NB_BOUTONS_LCD 5
#define DEFAULT_EEPPROM_ADDRESS 0

/******************************************************************************
* Definitions
******************************************************************************/
class LCDKeypad
{
public:
  LCDKeypad();
  void begin(int eepromAddress=DEFAULT_EEPPROM_ADDRESS);
  void refresh();

  void setDebounceDelay(unsigned long);
  void setLongPressDelay(unsigned long);
  void setLongPressInterval(unsigned long);

  BoutonLCD gauche, droite, haut, bas, selection;
  EcranLCD ecran;
  Del retro;

private:
  Calibration calibration;
};

#endif