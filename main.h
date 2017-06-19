#ifndef MAIN_H_
#define MAIN_H_
#include <Adafruit_WS2801.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <avr/io.h>
#include <avr/interrupt.h>
//Eigene Klassen
#include "switch.h"
#include "ain.h"

//Definitionen
#define N_LEDS 8
#define BITS_LED N_LEDS*3
#define TASTER 2
#define DATA 3
#define CLOCK 4
#define BETRIEB_LED 5
#define WAIT 50
extern Adafruit_WS2801 strip;


#endif
