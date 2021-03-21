#include <LCDKeypad.h>
LCDKeypad lcdKeypad;

void setup()
{
  lcdKeypad.begin();
}

void loop()
{
  lcdKeypad.refresh();

  if (lcdKeypad.haut.isPressed() || lcdKeypad.haut.isLongPressed())  //Le bouton HAUT ou BAS est appuyé
  {
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() + 5); //allumer la Del rouge.

  }
  if (lcdKeypad.bas.isPressed() || lcdKeypad.bas.isLongPressed())  //Le bouton HAUT ou BAS est appuyé
  {
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() - 5); //allumer la Del rouge.

  }

  if (lcdKeypad.selection.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.ecrire("Bonjour monde!", 0);
  }
  
  if (lcdKeypad.gauche.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.effacer( 1);
    lcdKeypad.ecran.ecrire("Gauche..", 1);
  }
  
  if (lcdKeypad.droite.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.effacer(1);
    lcdKeypad.ecran.ecrire("        ..Droite!", 1);
  }
}
