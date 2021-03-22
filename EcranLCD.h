#ifndef EcranLCD_h
#define EcranLCD_h

#include "Arduino.h"
#include "LiquidCrystal.h" //Pour l'affichage OLED

#define SCREEN_WIDTH 16 // OLED display width, in char
#define SCREEN_HEIGHT 2 // OLED display height, in char

/******************************************************************************
* Definitions
******************************************************************************/
class EcranLCD : public LiquidCrystal
{
public:
    EcranLCD(int rs, int em, int d4, int d5, int d6, int d7);
    void begin();
    void refresh();
    size_t write(uint8_t c);

    void ecrire(const char *str, int line = 0);
    void ecrire(String str, int line = 0);

    void effacer(int line = -1);

private:
    uint8_t _utf8;
    bool _utf8_error;
    unsigned int _unicode;
    uint8_t mapUnicodeToExtASCII(unsigned int _unicode);
    void writeFromBeginning(const char *str, int line);
    void writeFromBeginning(String str, int line);
};
#endif
