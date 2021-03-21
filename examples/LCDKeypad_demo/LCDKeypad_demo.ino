/*
     LCDKeypad_demo.ino
     PAR : Claude Bouchard
     Date : mars 2021

     Permet de tester le blindage de type 'LCD Keypad Shield'
     Pour calibrer les boutons, veuillez conserver le bouton 'Droite' enfoncé et appuyez-relachez le bouton 'Reset'.
     Puis, suivez les directives sur l'écran LCD.
*/

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
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() + 5); //Augmenter la luminosité du rétroéclairage

  }
  if (lcdKeypad.bas.isPressed() || lcdKeypad.bas.isLongPressed())  //Le bouton HAUT ou BAS est appuyé
  {
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() - 5); //Diminuer la luminosité du rétroéclairage

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
