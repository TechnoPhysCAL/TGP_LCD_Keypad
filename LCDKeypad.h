#ifndef LCDKeypad_h
#define LCDKeypad_h

#include "Arduino.h"
//#include "EEPROM.h"

#include "Calibration.h"
#include "LiquidCrystal.h"
#include "BoutonLCD.h"
#include "EcranLCD.h"
#include "Del.h"

#define NB_BOUTONS_LCD 5

 #ifdef ESP_PLATFORM
 #define NAMESPACE_DEFAULT "lcd-keypad"
  #else
#define EEPPROM_ADDRESS_DEFAULT 0
  #endif


#define PIN_SCREEN_RS_DEFAULT 8
#define PIN_SCREEN_EN_DEFAULT 9
#define PIN_SCREEN_D4_DEFAULT 4
#define PIN_SCREEN_D5_DEFAULT 5
#define PIN_SCREEN_D6_DEFAULT 6
#define PIN_SCREEN_D7_DEFAULT 7

#define PIN_SCREEN_BACKLIGHT_DEFAULT 10
#define PIN_KEYPAD_DEFAULT 0

/******************************************************************************
* Definitions
******************************************************************************/
class LCDKeypad
{
public:
  LCDKeypad(
      int rs = PIN_SCREEN_RS_DEFAULT,
      int en = PIN_SCREEN_EN_DEFAULT,
      int d4 = PIN_SCREEN_D4_DEFAULT,
      int d5 = PIN_SCREEN_D5_DEFAULT,
      int d6 = PIN_SCREEN_D6_DEFAULT,
      int d7 = PIN_SCREEN_D7_DEFAULT,
      int bcklight = PIN_SCREEN_BACKLIGHT_DEFAULT,
      int keypad = PIN_KEYPAD_DEFAULT);
  #ifdef ESP_PLATFORM
  void begin(const char * name = NAMESPACE_DEFAULT);
  #else
  void begin(int eepromAddress = EEPPROM_ADDRESS_DEFAULT);
  #endif
  void refresh();

  void setDebounceDelay(unsigned long);
  void setLongPressDelay(unsigned long);
  void setLongPressInterval(unsigned long);

  BoutonLCD gauche, droite, haut, bas, selection;
  EcranLCD ecran;
  Del retro;

private:
  int _pin_keypad;
  Calibration calibration;
};

#endif