#include "ain.h"

int ain0, ain1, ain2, ain3;


int red()
{
  ain0 = analogRead(A0) / 4;
  delay(50);
  return ain0;
}
int green()
{
  ain1 = analogRead(A1) / 4;
  delay(50);
  return ain1;
}
int blue()
{
  ain2 = analogRead(A2) / 4;
  delay(50);

  return ain2;
}
int dimmer()
{
  ain3 = analogRead(A3) / 4;
  delay(50);

  return ain3;
}
