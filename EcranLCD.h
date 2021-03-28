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
    EcranLCD(int rs, int en, int d4, int d5, int d6, int d7);
    void begin();
    void refresh();
    size_t write(uint8_t c);

    void ecrire(const char *str, int x = 0, int y = 0, int largeur = 0);
    void ecrire(String str, int x = 0, int y = 0, int largeur = 0);
    void effacer(int x = -1, int y = -1, int largeur = -1);

private:
    uint8_t _utf8;
    bool _utf8_error;
    unsigned int _unicode;
    uint8_t mapUnicodeToExtASCII(unsigned int _unicode);
    void writeFromBeginning(const char *str, int x, int y, int largeur);
    void writeFromBeginning(String str, int x, int y, int largeur);
};
#endif
