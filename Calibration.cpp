#include "Calibration.h"

#define KEY_PIN 0

/***************************************************************
// Constructeur
//***************************************************************/
Calibration::Calibration()
{

}

/***************************************************************************************
//Méthodes publiques
//***************************************************************************************/

//*********************************************************************
//Routine optionnelle de calibration, si la touche RIGHT est enfoncée
//au moment de l'appel de cette fonction
//*********************************************************************
int * Calibration::calibrer(int pin, LiquidCrystal *lcd, int eepromAddress)
{
	const int Nb_Boutons = 5;
	String boutonNames[] = {"SELECT", "LEFT  ", "DOWN  ", "UP   ", "RIGHT "};
	//static int _keys_values[5] = {638, 408, 255, 98, 0};
	lireEEPROM(eepromAddress);
	if (analogRead(pin) < 30)
	{
		lcd->clear();
		lcd->print("Calibration");
		for (int i = 0; i < Nb_Boutons; i++)
		{
			while (analogRead(pin) < 1000)
			{
			}
			lcd->setCursor(0, 0);
			lcd->print("Appuie sur ");
			lcd->print(boutonNames[i]);
			while (analogRead(pin) > 1000)
			{
			}
			delay(100);
			_keys_values[i] = analogRead(pin);
			lcd->setCursor(0, 1);
			lcd->print(_keys_values[i]);
			lcd->print("    ");
			lcd->setCursor(0, 0);
			lcd->print("APPUYE          ");
			while (analogRead(pin) < 1000)
			{
			}
			delay(100);
		}
		lcd->clear();
		lcd->print("OK.");
		ecrireEEPROM(eepromAddress);
		delay(500);

		//bouton.ajusterValeursBouton(_keys_values[0],_keys_values[1],_keys_values[2],_keys_values[3],_keys_values[4]);
		//bouton.ecrireEEPROM();
		lcd->clear();
		return _keys_values;
	}
}

void Calibration::lireEEPROM(int address)
{
	EEPROM.get(address, _keys_values);

}
void Calibration::ecrireEEPROM(int address)
{
	EEPROM.put(address,_keys_values);
}

;