#include <Arduino.h>
#include "Calibration.h"

/***************************************************************
// Constructeur
//***************************************************************/
Calibration::Calibration(){

}

/***************************************************************************************
//Méthodes publiques
//***************************************************************************************/

//*********************************************************************
//Routine optionnelle de calibration, si la touche RIGHT est enfoncée
//au moment de l'appel de cette fonction
//*********************************************************************
void Calibration::calibrer(ClavierACL bouton,LiquidCrystal lcd){
	int Nb_Boutons = bouton.getNbBoutons();
	String boutonNames[]={"SELECT", "LEFT  ", "DOWN  ", "UP   ", "RIGHT "};
	static int _keys_values[5];
	
	if (lecture()<30){
		lcd.clear();
		lcd.print("Calibration");
		for (int i = 0 ; i<Nb_Boutons;i++){
			while(lecture()<1000){}
			lcd.setCursor(0,0);
			lcd.print("Appuie sur ");
			lcd.print(boutonNames[i]);
			while(lecture()>1000){}
			delay(100);
			_keys_values[i] = lecture();
			lcd.setCursor(0,1);
			lcd.print(_keys_values[i]);
			lcd.print("    ");
			lcd.setCursor(0,0);
			lcd.print("APPUYE          ");
			while(lecture()<1000){}
			delay(100);
		}
			lcd.clear();
			lcd.print("OK.");
			delay(500);

	
	bouton.ajusterValeursBouton(_keys_values[0],_keys_values[1],_keys_values[2],_keys_values[3],_keys_values[4]);
	bouton.ecrireEEPROM();
	lcd.clear();
	}
}

int Calibration::lecture(){
	return analogRead(KEY_PIN);
}
