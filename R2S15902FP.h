#include <Arduino.h>

#define DATA 2 // pin DATA
#define CLK  3 // pin CLK

  void Slot1(int in, int out_gain, int att, int bass, int treb, int in_gain); 
           // input selector, REC-Output Gain Control, ADC Input ATT, bass (0=+14dB,8=0dB,15=-14dB), treble (0=+14dB,8=0dB,15=-14dB), Input Gain
  void Slot2(int gain0, int vol0, int gain1, int vol1); // gain0, volume0, gain1, volume1
  void Slot3(int gain2, int vol2, int gain3, int vol3); // gain2, volume2, gain3, volume3
  void Slot4(int gain4, int vol4, int gain5, int vol5); // gain4, volume4, gain5, volume5
