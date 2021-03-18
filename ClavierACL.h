#ifndef ClavierACL_h
#define ClavierACL_h

#include "Arduino.h"
#include <EEPROM.h>
#include "../../Clavier/src/Clavier.h"


#define NB_BOUTONS_ACL 5

#define KEY_PIN 0

#define B_AUCUN -1
#define B_SELECTION 0
#define B_GAUCHE 1
#define B_BAS 2
#define B_HAUT 3
#define B_DROITE 4

class Clavier;
 
class ClavierACL : public Clavier
{
  public:
    ClavierACL();
	void ajusterValeursBouton(int selection, int gauche, int bas , int haut,int droite); 
	void ecrireEEPROM(); // Devrait être protégé

  private:

  
    void lireSignaux();
	int decodeurBouton(int ADCout);
	void lireEEPROM();

	int getIndexEEPROM(int occurence);

	
};
#include "Calibration.h"
#endif