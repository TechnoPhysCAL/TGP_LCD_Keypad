#ifndef BoutonLCD_h
#define BoutonLCD_h

#include "BoutonBase.h"

class BoutonLCD : public BoutonBase
{
public:
  BoutonLCD(int min, int max);
  void setKeyValue(int value);
   void setLimits(int min, int max);
protected:
  bool isDetected();

private:
  int _keyValue; //should be static, to do
  int _front;
  int _min;
  int _max;
};

#endif