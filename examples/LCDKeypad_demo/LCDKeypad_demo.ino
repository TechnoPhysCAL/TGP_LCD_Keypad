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
//LCDKeypad lcdKeypad(8, 9, 4, 5, 6, 7, 10, 0); //Possibiltié de modifier les broches respectives des éléments du blindage

void setup()
{
  Serial.begin(115200);
  lcdKeypad.begin();
  //lcdKeypad.begin(0); //Sur architecture Arduino, spécifie l'espace mémoire dans le EEPROM pour lire/ecrire la calibration des boutons.
  //lcdKeypad.begin("lcd-keypad"); //Sur architecture ESP32, spécifie le nom de l'espace dans Preferences pour lire/ecrire la calibration des boutons.
}

void loop()
{

  lcdKeypad.refresh();

  if (lcdKeypad.haut.isPressed() || lcdKeypad.haut.isLongPressed()) //Le bouton HAUT ou BAS est appuyé
  {
    Serial.println("haut");
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() + 5); //Augmenter la luminosité du rétroéclairage
  }
  if (lcdKeypad.bas.isPressed() || lcdKeypad.bas.isLongPressed()) //Le bouton HAUT ou BAS est appuyé
  {
    Serial.println("bas");
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() - 5); //Diminuer la luminosité du rétroéclairage
  }

  if (lcdKeypad.selection.isPressed()) //Le bouton selection est appuyé
  {
    Serial.println("selection");
    lcdKeypad.ecran.ecrire("Bonjour monde!", 0);
  }

  if (lcdKeypad.gauche.isPressed()) //Le bouton selection est appuyé
  {
    Serial.println("gauche");
    lcdKeypad.ecran.effacer(1);
    lcdKeypad.ecran.ecrire("Gauche..", 1);
  }

  if (lcdKeypad.droite.isPressed()) //Le bouton selection est appuyé
  {
    Serial.println("droite");
    lcdKeypad.ecran.effacer(1);
    lcdKeypad.ecran.ecrire("        ..Droite!", 1);
  }
}