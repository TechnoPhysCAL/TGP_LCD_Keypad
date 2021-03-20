#ifndef LCDKeypad.h
#define LCDKeypad_h

#include "Arduino.h"
#include "BoutonACL.h"


#define PIN_KEYPAD 


/******************************************************************************
* Definitions
******************************************************************************/
class ProtoTGP
{
public:
    ProtoTGP();

    void begin();
    void refresh();

    void setDebounceDelay(unsigned long);
	void setLongPressDelay(unsigned long);
	void setLongPressInterval(unsigned long);

    Bouton gauche, droite, haut, bas, selection;
    Del rouge, verte;
    Ecran ecran;

private:
};
#endif
