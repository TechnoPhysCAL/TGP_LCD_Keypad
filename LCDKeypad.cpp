#include "LCDKeypad.h"

/***************************************************************
// Déclaration des variables et constantes privées
//***************************************************************/

static int _keys_limits[NB_BOUTONS_LCD] = {49, 176, 331, 523, 830};

/***************************************************************
// Constructeur
//***************************************************************/
LCDKeypad::LCDKeypad() : droite(0, _keys_limits[0]),
						 haut(_keys_limits[0], _keys_limits[1]),
						 bas(_keys_limits[1], _keys_limits[2]),
						 gauche(_keys_limits[2], _keys_limits[3]),
						 selection(_keys_limits[3], _keys_limits[4]),
						 ecran(),
						 retro(10),
						 calibration()
{
	pinMode(PIN_KEYPAD, INPUT);
}

/***************************************************************************************
//Méthodes publiques
//***************************************************************************************/

void LCDKeypad::setDebounceDelay(unsigned long delay)
{
	gauche.setDebounceDelay(delay);
	droite.setDebounceDelay(delay);
	haut.setDebounceDelay(delay);
	bas.setDebounceDelay(delay);
	selection.setDebounceDelay(delay);
}
void LCDKeypad::setLongPressDelay(unsigned long delay)
{
	gauche.setLongPressDelay(delay);
	droite.setLongPressDelay(delay);
	haut.setLongPressDelay(delay);
	bas.setLongPressDelay(delay);
	selection.setLongPressDelay(delay);
}
void LCDKeypad::setLongPressInterval(unsigned long interval)
{
	gauche.setLongPressInterval(interval);
	droite.setLongPressInterval(interval);
	haut.setLongPressInterval(interval);
	bas.setLongPressInterval(interval);
	selection.setLongPressInterval(interval);
}

void LCDKeypad::begin(int eepromAddress)
{
	ecran.begin();
	retro.on();
	retro.refresh();
	int * key_values = calibration.calibrer(&ecran, eepromAddress);

	selection.setLimits((key_values[1]+key_values[0])/2, (key_values[0]+1023)/2);
	gauche.setLimits((key_values[2]+key_values[1])/2,(key_values[1]+key_values[0])/2);
	bas.setLimits((key_values[3]+key_values[2])/2,(key_values[2]+key_values[1])/2);
	haut.setLimits((key_values[4]+key_values[3])/2, (key_values[3]+key_values[2])/2);
	droite.setLimits(0, (key_values[4]+key_values[3])/2);
}
void LCDKeypad::refresh()
{
	retro.refresh();
	//ecran.refresh();
	int value = analogRead(PIN_KEYPAD);

	gauche.setKeyValue(value);
	droite.setKeyValue(value);
	haut.setKeyValue(value);
	bas.setKeyValue(value);
	selection.setKeyValue(value);

	gauche.refresh();
	droite.refresh();
	haut.refresh();
	bas.refresh();
	selection.refresh();
}
