#ifndef Calibration_h
#define Calibration_h

#include "Arduino.h"
#include "ClavierACL.h"
#include "LiquidCrystal.h"



class Calibration
{
  public:
    Calibration();
	void calibrer(ClavierACL bouton, LiquidCrystal lcd); 

  private:
	int lecture();

	
	
};

#endif