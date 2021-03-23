#ifndef BoutonLCD_h
#define BoutonLCD_h

#include "BoutonBase.h"

class BoutonLCD : public BoutonBase
{
public:
  BoutonLCD(uint16_t min, uint16_t max);
  void setKeyValue(uint16_t value);
  void setLimits(uint16_t min, uint16_t max);

protected:
  bool isDetected();

private:
  int _front;
  uint16_t _keyValue; //should be static, to do
  uint16_t _min;
  uint16_t _max;
};

#endif