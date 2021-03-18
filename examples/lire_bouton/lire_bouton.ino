/*
  Clavier ACL

 Cet exemple démontre l'utilisation de la librairie
 ClavierACL, qui permet de gérer les boutons
 sur l'affichage à cristaux liquides 2x16 (LCD Keypad Shield)

 créé en 2013
 modifié en août 2017
 par Claude Bouchard
/*

/*
Valeur des boutons :

  B_SELECTION    0
  B_GAUCHE       1
  B_BAS          2
  B_HAUT         3
  B_DROITE       4

Valeur des états :

  RELACHE        0
  RELACHANT      1
  ENFONCE        2
  ENFONCANT      3
  MAINTENU       6
  MAINTENANT     7
*/

#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Clavier.h>
#include <ClavierACL.h>

//Assignation des broches de l'afficheur à cristaux liquides
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

//Déclaration d'une variable clavier du type ACL_bouton (constructeur)
ClavierACL clavier;
Calibration cal;

void setup(){ 

  lcd.begin(16,2);
  
  cal.calibrer(clavier,lcd);
  //Pour utiliser la calibration du clavier, on doit garder enfoncée 
  // la touche RIGHT puis appuyer et relacher une fois la touche RESET
  //Cette facon de calibrer conserve les valeurs en mémoire permanente (EEPROM)
  
  //clavier.ajusterValeursBouton(741, 506, 329, 143, 0);
  //Cette calibration logicielle optionnelle ne conserve pas les valeurs de manière permanente
  
  lcd.clear();
  lcd.setCursor(0,0);
  clavier.ajusterDelaiRebond(5);
  clavier.ajusterLongClic(2000);
  clavier.ajusterRepetition(200);
    
}

void loop(){

  clavier.actualiser();
  
  lcd.setCursor(0,0);
  lcd.print("Boutons : ");

  lcd.setCursor(0,1);
  for(int i=0;i<clavier.getNbBoutons();i++){
    lcd.print(clavier.etatBouton(i));
    lcd.print(" ");
  }

  delay(10);
}
