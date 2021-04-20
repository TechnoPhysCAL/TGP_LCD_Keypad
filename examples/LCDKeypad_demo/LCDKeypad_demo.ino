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

  if (lcdKeypad.selection.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.ecrire("Bonjour monde!"); //affiche par défaut à la coordonnée (0,0).
  }

  if (lcdKeypad.gauche.isPressed()) //Le bouton Gauche est appuyé
  {
    lcdKeypad.ecran.ecrire("Gauche..", 0, 1, 8); //affiche à la coordonnée (0,1) sur un espace de 8 caractères.
  }

  if (lcdKeypad.droite.isPressed()) //Le bouton Droite est appuyé
  {

    lcdKeypad.ecran.ecrire("...Droite!", 8, 1, 8); //affiche à la coordonnée (8,1) sur un espace de 8 caractères.
  }

  if (lcdKeypad.haut.isPressed() || lcdKeypad.haut.isLongPressed()) //Le bouton HAUT  est appuyé
  {

    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() + 5); //Augmenter la luminosité du rétroéclairage
  }
  if (lcdKeypad.bas.isPressed() || lcdKeypad.bas.isLongPressed()) //Le bouton BAS est appuyé
  {

    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() - 5); //Diminuer la luminosité du rétroéclairage
  }
}