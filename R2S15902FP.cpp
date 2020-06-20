#include "R2S15902FP.h"

const boolean input[4][3]={{0,1,0},{1,0,0},{1,1,0},{0,0,0}}; //  Input Selector 
const boolean rec_out[4][2]={{0,0},{0,1},{1,0},{1,1}}; //  REC-Output Gain Control  
const boolean input_att[4][2]={{0,0},{0,1},{1,0},{1,1}};//ADC Input ATT 

const boolean bass_data[15][4]={{1,1,1,1},{1,1,1,0},{1,1,0,1},{1,1,0,0},{1,0,1,1},{1,0,1,0},{1,0,0,1},{1,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1}}; // bass
const boolean treb_data[15][4]={{1,1,1,1},{1,1,1,0},{1,1,0,1},{1,1,0,0},{1,0,1,1},{1,0,1,0},{1,0,0,1},{1,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1}}; // treble
const boolean input_gain_data[8][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};//Input Gain 
const boolean input_control_data[8][3] ={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};//Gain Control  
const boolean volume[100][7]  ={{0,0,0,0,0,0,0},{0,0,0,0,0,0,1},{0,0,0,0,0,1,0},{0,0,0,0,0,1,1},{0,0,0,0,1,0,0},{0,0,0,0,1,0,1},{0,0,0,0,1,1,0},{0,0,0,0,1,1,1},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{0,0,0,1,0,1,0},{0,0,0,1,0,1,1},{0,0,0,1,1,0,0},{0,0,0,1,1,0,1},{0,0,0,1,1,1,0},{0,0,0,1,1,1,1},{0,0,1,0,0,0,0},{0,0,1,0,0,0,1},{0,0,1,0,0,1,0},{0,0,1,0,0,1,1},{0,0,1,0,1,0,0},{0,0,1,0,1,0,1},{0,0,1,0,1,1,0},{0,0,1,0,1,1,1},{0,0,1,1,0,0,0},{0,0,1,1,0,0,1},{0,0,1,1,0,1,0},{0,0,1,1,0,1,1},{0,0,1,1,1,0,0},{0,0,1,1,1,0,1},{0,0,1,1,1,1,0},{0,0,1,1,1,1,1},{0,1,0,0,0,0,0},{0,1,0,0,0,0,1},{0,1,0,0,0,1,0},{0,1,0,0,0,1,1},{0,1,0,0,1,0,0},{0,1,0,0,1,0,1},{0,1,0,0,1,1,0},{0,1,0,0,1,1,1},{0,1,0,1,0,0,0},{0,1,0,1,0,0,1},{0,1,0,1,0,1,0},{0,1,0,1,0,1,1},{0,1,0,1,1,0,0},{0,1,0,1,1,0,1},{0,1,0,1,1,1,0},{0,1,0,1,1,1,1},{0,1,1,0,0,0,0},{0,1,1,0,0,0,1},{0,1,1,0,0,1,0},{0,1,1,0,0,1,1},{0,1,1,0,1,0,0},{0,1,1,0,1,0,1},{0,1,1,0,1,1,0},{0,1,1,0,1,1,1},{0,1,1,1,0,0,0},{0,1,1,1,0,0,1},{0,1,1,1,0,1,0},{0,1,1,1,0,1,1},{0,1,1,1,1,0,0},{0,1,1,1,1,0,1},{0,1,1,1,1,1,0},{0,1,1,1,1,1,1},{1,0,0,0,0,0,0},{1,0,0,0,0,0,1},{1,0,0,0,0,1,0},{1,0,0,0,0,1,1},{1,0,0,0,1,0,0},{1,0,0,0,1,0,1},{1,0,0,0,1,1,0},{1,0,0,0,1,1,1},{1,0,0,1,0,0,0},{1,0,0,1,0,0,1},{1,0,0,1,0,1,0},{1,0,0,1,0,1,1},{1,0,0,1,1,0,0},{1,0,0,1,1,0,1},{1,0,0,1,1,1,0},{1,0,0,1,1,1,1},{1,0,1,0,0,0,0},{1,0,1,0,0,0,1},{1,0,1,0,0,1,0},{1,0,1,0,0,1,1},{1,0,1,0,1,0,0},{1,0,1,0,1,0,1},{1,0,1,0,1,1,0},{1,0,1,0,1,1,1},{1,0,1,1,0,0,0},{1,0,1,1,0,0,1},{1,0,1,1,0,1,0},{1,0,1,1,0,1,1},{1,0,1,1,1,0,0},{1,0,1,1,1,0,1},{1,0,1,1,1,1,0},{1,0,1,1,1,1,1},{1,1,0,0,0,0,0},{1,1,0,0,0,0,1},{1,1,0,0,0,1,0},{1,1,0,0,0,1,1}}; // volume


void Slot1(int in, int out_gain, int att, bool R_L_in, int bass, int treb, int in_gain){
  // input selector  ||  0-2 bit
  for(int i=0;i<3;i++){
    digitalWrite(DATA, input[in][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
  //  REC Output  ||  3 bit
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
  //  REC-Output Gain Control  ||  4-5 bit
  for(int i=0;i<2;i++){
    digitalWrite(DATA, rec_out[out_gain][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
  //  ADC Input ATT  ||  6-7 bit
 for(int i=0;i<2;i++){
    digitalWrite(DATA, input_att[att][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
  //   L/R Input   || 8 bit
    digitalWrite(DATA, R_L_in); // 0 ... 1
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
  // BASS  ||   9 - 12 bit
  for(int i=0;i<4;i++){
    digitalWrite(DATA, bass_data[bass][i]); 
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
  // TREBLE   ||  13 - 16 bit
  for(int i=0;i<4;i++){
    digitalWrite(DATA, treb_data[treb][i]); 
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
  //   SL/ SR/ C/ SW Input  || 17 bit 
    digitalWrite(DATA, HIGH); // 1
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
   // Input Gain  ||  18 - 20 bit
   for(int i=0;i<3;i++){
    digitalWrite(DATA, input_gain_data[in_gain][i]); 
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
    // 21 bit
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 22 bit 
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 23 bit  
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, HIGH);// CLOCK
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW);
}

void Slot2(int gain0, int vol0, int gain1, int vol1){
 // Gain Control 0  ||  0-2 bit
  for(int i=0;i<3;i++){
    digitalWrite(DATA, input_control_data[gain0][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // volume 0  ||  3 - 9 bit
  for(int i=0;i<7;i++){
    digitalWrite(DATA, volume[vol0][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // Gain Control 1  ||  10-12 bit
  for(int i=0;i<3;i++){
    digitalWrite(DATA, input_control_data[gain1][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // volume 1  ||  13 - 19 bit
  for(int i=0;i<7;i++){
    digitalWrite(DATA, volume[vol1][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
    //  20 bit
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    //  21 bit
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 22 bit 
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 23 bit 
    digitalWrite(DATA, HIGH); // 1
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, HIGH); // CLOCK
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW);
}

void Slot3(int gain2, int vol2, int gain3, int vol3){
 // Gain Control 2  ||  0-2 bit
  for(int i=0;i<3;i++){
    digitalWrite(DATA, input_control_data[gain2][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // volume 2  ||  3 - 9 bit
  for(int i=0;i<7;i++){
    digitalWrite(DATA, volume[vol2][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // Gain Control 3  ||  10-12 bit
  for(int i=0;i<3;i++){
    digitalWrite(DATA, input_control_data[gain3][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // volume 3  ||  13 - 19 bit
  for(int i=0;i<7;i++){
    digitalWrite(DATA, volume[vol3][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
    // 20 bit
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    //  21 bit
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 22 bit LOW
    digitalWrite(DATA, HIGH); // 1
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 23 bit  HIGH
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, HIGH); // CLOCK
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW);
}

void Slot4(int gain4, int vol4, int gain5, int vol5){
 // Gain Control 4  ||  0-2 bit
  for(int i=0;i<3;i++){
    digitalWrite(DATA, input_control_data[gain4][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // volume 4  ||  3 - 9 bit
  for(int i=0;i<7;i++){
    digitalWrite(DATA, volume[vol4][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // Gain Control 5  ||  10-12 bit
  for(int i=0;i<3;i++){
    digitalWrite(DATA, input_control_data[gain5][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
 // volume 5  ||  13 - 19 bit
  for(int i=0;i<7;i++){
    digitalWrite(DATA, volume[vol5][i]);
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);}
    // 20 bit
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    //  21 bit
    digitalWrite(DATA, LOW); // 0
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 22 bit LOW
    digitalWrite(DATA, HIGH); // 1
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 23 bit  HIGH
    digitalWrite(DATA, HIGH); // 1
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, HIGH); // CLOCK
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW);
}
