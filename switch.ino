#include "switch.h"
unsigned int counter = 0;
int pressed = 0;

void interrupt_0()
{
  if(digitalRead(TASTER) == 0 && pressed == 0)
  {
    delay(50);
    if(digitalRead(TASTER) == 0 && pressed == 0)
    {
     counter++;
     delay(50);
     pressed = 1;
    }

  }
}
