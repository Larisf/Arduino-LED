#include "led.h"

void colorWipe(uint32_t c, uint8_t wait)
{
  int i;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void setLauflicht(uint32_t c, uint8_t wait)
{
  int i;
  for (i = 0; i < strip.numPixels() + 1; i++)
  {
    if (counter != 0)
    {
      strip.setPixelColor(i - 1, 0);
      break;
    }
    delay(wait);
    strip.setPixelColor(i, c);
    strip.setPixelColor(i - 1, 0);
    strip.show();
    Serial.println(counter);
  }
  for (i = strip.numPixels() + 1; i >= 0 ; i--)
  {
    if (counter != 0)
    {
      strip.setPixelColor(i, 0);
      break;
    }
    delay(wait);
    strip.setPixelColor(i, 0);
    strip.setPixelColor(i - 1, c);
    strip.show();
  }
}
void farben()
{
  int d = dimmer();
  colorWipe(Color(255 - d, 0, 0), WAIT); // red fill
  colorWipe(Color(0, 255 - d, 0), WAIT); // green fill
  colorWipe(Color(0, 0, 255 - d), WAIT); // blue fill
}
void lauflicht()
{
  int d = dimmer();
  setLauflicht(Color(255 - d, 0, 255 - d), 1000);
}
void geschaltet()
{
  int r = red();
  int g = green();
  int b = blue();
  int d = dimmer();
  switch (counter)
  {
    case 0:
     lauflicht();
     break;
    case 1:
      colorWipe(Color(255 - d, 0, 0), WAIT); // red fill
      break;
    case 2:
      colorWipe(Color(0, 255 - d, 0), WAIT); // green fill
      break;
    case 3:
      colorWipe(Color(0, 0, 255 - d), WAIT); // blue fill
      break;
    case 4:
      colorWipe(Color(255 - d, 255 - d , 255 - d), WAIT); // white fill
      break;
    case 5:
      colorWipe(Color(r, g , b), WAIT);  // ajustable fill
      break;
    case 6:
      RGBLoop();
      break;
    case 7:
      farben();
      break;
    case 8:
      rainbowCycle(1);
      break;
    case 9:
      colorWipe(Color(0, 0 , 0), WAIT);  // turn off fill
      break;

    default:
      counter = 0;
      break;
  }
}
/* Helper functions */
// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

void rainbowCycle(int SpeedDelay)
{
  int d = dimmer();
  byte *c;
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++)
  {
    for (i = 0; i < N_LEDS; i++)
    {
      c = Wheel(((i * 256 / N_LEDS) + j) & 255);
      strip.setPixelColor(i, *c, *(c + 1), *(c + 2));
    }
    strip.show();
    delay(SpeedDelay);
  }
}

byte * Wheel(byte WheelPos)
{
  static byte c[3];
  if (WheelPos < 85)
  {
    c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  }
  else if (WheelPos < 170)
  {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  }
  else
  {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }
  return c;
}
void RGBLoop()
{
  for(int j = 0; j < 3; j++ ) 
  { 
    // Fade IN
    for(int k = 0; k < 256; k+=2) 
    { 
      switch(j) 
      { 
        case 0: colorWipe(Color(k, 0 , 0), 0); break;
        case 1: colorWipe(Color(0, k , 0), 0); break;
        case 2: colorWipe(Color(0, 0 , k), 0); break;
      }
      strip.show();
     // delay(0.5);
    }
    // Fade OUT
    for(int k = 255; k >= 0; k-=2) 
    { 
      switch(j) 
      { 
        case 0: colorWipe(Color(k, 0 , 0), 0); break;
        case 1: colorWipe(Color(0, k , 0), 0); break;
        case 2: colorWipe(Color(0, 0 , k), 0); break;
      }
      strip.show();
      //delay(0.5);
    }
  }
}
