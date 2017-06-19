#include "main.h"
Adafruit_WS2801 strip = Adafruit_WS2801(N_LEDS, DATA, CLOCK);
Adafruit_ADS1115 ads(0x48);
void setup()
{
  pinMode(BETRIEB_LED, OUTPUT);
  pinMode(TASTER, INPUT_PULLUP);
  strip.begin();
  strip.show();
  Serial.begin(9600);
  ads.begin();
  attachInterrupt(digitalPinToInterrupt(TASTER), interrupt_0, FALLING);
}

void loop()
{
  //test();
  programm();
}
void programm()
{
  if (counter == 9)
    digitalWrite(BETRIEB_LED, LOW);
  else
    digitalWrite(BETRIEB_LED, HIGH);
    geschaltet();
    pressed = 0;
  
}
void test()
{
  Serial.print("AnalogIn_0: ");
  Serial.println(analogRead(A0));
  Serial.print("AnalogIn_1: ");
  Serial.println(analogRead(A1));
  Serial.print("AnalogIn_2: ");
  Serial.println(analogRead(A2));
  Serial.print("AnalogIn_3: ");
  Serial.println(analogRead(A3));
  Serial.print("Counter: ");
  Serial.println(counter);
  Serial.print("Taster: ");
  Serial.println(digitalRead(TASTER));
  delay(1000);
}






