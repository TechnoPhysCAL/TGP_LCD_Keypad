#include "BoutonACL.h"

BoutonACL::BoutonACL(int min, int max) : BoutonBase()
{
	_min=min;
	_max= max;
	_front =  LOW ;

}

bool Bouton::isDetected()
{
	return  _readValue>=_min && _readValue<_max;
}