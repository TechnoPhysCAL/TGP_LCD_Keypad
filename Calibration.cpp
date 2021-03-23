#include "Calibration.h"

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

#ifdef ESP_PLATFORM
uint16_t *Calibration::calibrer(int pin, LiquidCrystal *lcd, const char *location)
#else
uint16_t *Calibration::calibrer(int pin, LiquidCrystal *lcd, int location)
#endif

{
	const int Nb_Boutons = 5;
	String boutonNames[] = {"SELECT", "LEFT  ", "DOWN  ", "UP   ", "RIGHT "};

	lireEEPROM(location);
	if (analogRead(pin) < SEUIL_BAS)
	{
		lcd->clear();
		lcd->print("Calibration");
		for (int i = 0; i < Nb_Boutons; i++)
		{
			while (analogRead(pin) < SEUIL_HAUT)
			{
			}
			lcd->setCursor(0, 0);
			lcd->print("Appuie sur ");
			lcd->print(boutonNames[i]);
			while (analogRead(pin) > SEUIL_HAUT)
			{
			}
			delay(100);
			_keys_values[i] = analogRead(pin);
			lcd->setCursor(0, 1);
			lcd->print(_keys_values[i]);
			lcd->print("    ");
			lcd->setCursor(0, 0);
			lcd->print("APPUYE          ");
			while (analogRead(pin) < SEUIL_HAUT)
			{
			}
			delay(100);
		}
		lcd->clear();
		lcd->print("OK.");
		ecrireEEPROM(location);
		delay(500);

		lcd->clear();
	}
	return _keys_values;
}

#ifdef ESP_PLATFORM
void Calibration::lireEEPROM(const char *location)
{
	preferences.begin(location, true);
	_keys_values[0] = preferences.getUShort("s", MAX_ANALOG * 0.8);
	_keys_values[1] = preferences.getUShort("l", MAX_ANALOG * 0.5);
	_keys_values[2] = preferences.getUShort("d", MAX_ANALOG * 0.3);
	_keys_values[3] = preferences.getUShort("u", MAX_ANALOG * 0.1);
	_keys_values[4] = preferences.getUShort("r", MAX_ANALOG * 0.0);
	preferences.end();
}
void Calibration::ecrireEEPROM(const char *location)
{
	preferences.begin(location, false);
	preferences.putUShort("s", _keys_values[0]);
	preferences.putUShort("l", _keys_values[1]);
	preferences.putUShort("d", _keys_values[2]);
	preferences.putUShort("u", _keys_values[3]);
	preferences.putUShort("r", _keys_values[4]);
	preferences.end();
}

#else
void Calibration::lireEEPROM(int location)
{
	EEPROM.get(location, _keys_values);
}
void Calibration::ecrireEEPROM(int location)
{
	EEPROM.put(location, _keys_values);
}
#endif
