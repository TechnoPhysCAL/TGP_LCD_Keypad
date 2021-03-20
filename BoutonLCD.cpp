#include "BoutonLCD.h"

BoutonLCD::BoutonLCD(int min, int max) : BoutonBase()
{
	_min = min;
	_max = max;
	_front = LOW;
}

void BoutonLCD::setLimits(int min, int max)
{
	Serial.println(String(min)+" "+max);
	_min = min;
	_max = max;
}

void BoutonLCD::setKeyValue(int value)
{
	_keyValue = value;
}

bool BoutonLCD::isDetected()
{
	return _keyValue >= _min && _keyValue < _max;
}