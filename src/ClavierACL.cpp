#include "Arduino.h"
#include "ClavierACL.h"

/***************************************************************
// D�claration des variables et constantes priv�es
//***************************************************************/

static int _keys_limits[NB_BOUTONS_ACL] = {882, 623, 418, 236,71};

/***************************************************************
// Constructeur
//***************************************************************/
ClavierACL::ClavierACL():Clavier(NB_BOUTONS_ACL){
	lireEEPROM();
}

/***************************************************************************************
//M�thodes publiques
//***************************************************************************************/

//*********************************************************************
//Routine pour ajuster les niveaux de d�cision pour d�terminer quel
//bouton a �t� appuy�.
//*********************************************************************
void ClavierACL::ajusterValeursBouton(int selection, int gauche, int bas , int haut,int droite) {

	int _keys_values[NB_BOUTONS_ACL];
	_keys_values[B_SELECTION] = selection;
	_keys_values[B_GAUCHE] = gauche;
	_keys_values[B_BAS] = bas;
	_keys_values[B_HAUT] = haut;
	_keys_values[B_DROITE] = droite;

	_keys_limits[0] = (1023+_keys_values[0])>>1;

	for (int i = 1 ; i<NB_BOUTONS_ACL;i++){

		_keys_limits[i] = (_keys_values[i-1] +_keys_values[i])>>1;

	}
	/// DOIT-ON �CRIRE DANS LE EEPROM OU SIMPLEMENT CHANGER LES VALEURS EN M�MOIRE ?
	/// EST-CE SEULEMENT LA CALIBRATION QUI A LE DROIT D'�CRIRE DANS LE EEPROM?
	//ecrireEEPROM();
}

/***************************************************************************************
//M�thodes priv�es
//**************************************************************************************/
void ClavierACL::lireSignaux(){

	int _ADCout = analogRead(KEY_PIN);								//Lit la valeur brute du bouton
	int _keyRead = decodeurBouton(_ADCout);							//D�code le bouton appuy� en fonction de la valeur brute

	if (_keyRead>=0){
			_boutons[_keyRead]->up(); //D�pose dans le registre àd�calage la valeur du bouton lu
		}
}

//*********************************************************************
//Routine pour d�coder le bouton qui a �t� appuy� en fonction de la valeur
//brute � la sortie du convertisseur analogique � num�rique
//*********************************************************************
int ClavierACL::decodeurBouton(int ADCout){
	int key ;
	for(key = B_AUCUN; key<B_DROITE;key++){
		if(_keys_limits[key+1] <= ADCout){
			break;
		}
	}
	return 	key;

}

void ClavierACL::lireEEPROM(){
	int keysFirst[NB_BOUTONS_ACL];
	int keysSecond[NB_BOUTONS_ACL];
	EEPROM.get(getIndexEEPROM(1),keysFirst);
	EEPROM.get(getIndexEEPROM(2),keysSecond);
	
	for (int i=0;i<NB_BOUTONS_ACL;i++){
		
		if (keysFirst[i]!=keysSecond[i] || keysFirst[i]==-1){
				return;
		}
	}
	
	for (int i=0;i<NB_BOUTONS_ACL;i++){
		_keys_limits[i] = keysFirst[i];
	}
	
}

void ClavierACL::ecrireEEPROM(){
	EEPROM.put(getIndexEEPROM(1),_keys_limits);
	EEPROM.put(getIndexEEPROM(2),_keys_limits);
}

int ClavierACL::getIndexEEPROM(int occurence){
	return EEPROM.length()-(sizeof(int)*NB_BOUTONS_ACL*occurence);
}
