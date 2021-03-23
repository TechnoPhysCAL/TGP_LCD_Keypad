#include "BoutonLCD.h"

BoutonLCD::BoutonLCD(uint16_t min, uint16_t max) : BoutonBase()
{
	_min = min;
	_max = max;
	_front = LOW;
}

void BoutonLCD::setLimits(uint16_t min, uint16_t max)
{
	_min = min;
	_max = max;
}

void BoutonLCD::setKeyValue(uint16_t value)
{
	_keyValue = value;
}

bool BoutonLCD::isDetected()
{
	return _keyValue >= _min && _keyValue < _max;
}