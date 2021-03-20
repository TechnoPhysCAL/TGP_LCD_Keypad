#ifndef LCDKeypad_h
#define LCDKeypad_h

#include "Arduino.h"
#include "EEPROM.h"
#include "Bouton.h"
#include "EcranLCD.h"

#define KEY_PIN 0

/******************************************************************************
* Definitions
******************************************************************************/
class LCDKeypad
{
public:
  void begin();
  void refresh();

  void setDebounceDelay(unsigned long);
  void setLongPressDelay(unsigned long);
  void setLongPressInterval(unsigned long);

  Bouton gauche, droite, haut, bas, selection;
  EcranLCD ecran;

private:
  void ajusterValeursBouton(int selection, int gauche, int bas, int haut, int droite);
  void ecrireEEPROM(); // Devrait �tre prot�g�

private:
  void lireSignaux();
  int decodeurBouton(int ADCout);
  void lireEEPROM();

  int getIndexEEPROM(int occurence);
};

#endif