#include <R2S15902FP.h>
      
void setup(){ Serial.begin(9600);
  pinMode(DATA, OUTPUT); // D2
  pinMode(CLK, OUTPUT);  // D3
  delay(100);
}

void loop(){
  audio();
  delay(1000);
}

void audio(){
  Slot1(0,0,0,0,5,5,0); 
   // input selector  1...4 === int 0...3, in4 === multi in
    //REC-Output Gain Control int 0...6 dB === int 0...3
    //ADC Input ATT 0...-6 dB === int 0...3
    //L/R Input 0 === IN1...3, 1 === IN4 MULTI
    //bass int 0 === +14dB int 8 === 0dB int 15 === -14dB
    //treble int 0 === +14dB int 8 === 0dB int 15 === -14dB
    //Input Gain 0...14 dB === int 0...7
  Slot2(3,10,3,10); // gain0, volume0, gain1, volume1
  Slot3(3,10,3,10); // gain2, volume2, gain3, volume3
  Slot4(3,10,3,10); // gain4, volume4, gain5, volume5
  // gain 0...14 dB === int 0...7
  // volume 0...-99 dB === int 0...99
}
