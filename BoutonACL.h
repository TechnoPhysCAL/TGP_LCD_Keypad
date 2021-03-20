#ifndef BoutonACL_h
#define BoutonACL_h

#include "BoutonBase.h"

class BoutonACL : public BoutonBase
{
  public:
   BoutonACL(int min, int max);
	
  protected:
   bool isDetected();
	
  private:
    static int _keyValue;
    int _min;
    int _max;
  	
};
#endif