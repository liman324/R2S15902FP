const int CLK = 3;
const int DATA = 2;
int input[3][3]={{0,1,0},{1,0,0},{1,1,0}}; //  Input Selector 
int rec_out[4][2]={{0,0},{0,1},{1,0},{1,1}}; //  REC-Output Gain Control  
int input_att[4][2]={{0,0},{0,1},{1,0},{1,1}};//ADC Input ATT 
int bass_data[15][4]={{1,1,1,1},{1,1,1,0},{1,1,0,1},{1,1,0,0},{1,0,1,1},{1,0,1,0},{1,0,0,1},{1,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1}}; // bass
int treb_data[15][4]={{1,1,1,1},{1,1,1,0},{1,1,0,1},{1,1,0,0},{1,0,1,1},{1,0,1,0},{1,0,0,1},{1,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1}}; // treble
int input_gain_data[8][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};//Input Gain 
int input_control_data[8][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};//Gain Control  
int volume[100][7]={{0,0,0,0,0,0,0},{0,0,0,0,0,0,1},{0,0,0,0,0,1,0},{0,0,0,0,0,1,1},{0,0,0,0,1,0,0},{0,0,0,0,1,0,1},{0,0,0,0,1,1,0},{0,0,0,0,1,1,1},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{0,0,0,1,0,1,0},{0,0,0,1,0,1,1},{0,0,0,1,1,0,0},{0,0,0,1,1,0,1},{0,0,0,1,1,1,0},{0,0,0,1,1,1,1},{0,0,1,0,0,0,0},{0,0,1,0,0,0,1},{0,0,1,0,0,1,0},{0,0,1,0,0,1,1},{0,0,1,0,1,0,0},{0,0,1,0,1,0,1},{0,0,1,0,1,1,0},{0,0,1,0,1,1,1},{0,0,1,1,0,0,0},{0,0,1,1,0,0,1},{0,0,1,1,0,1,0},{0,0,1,1,0,1,1},{0,0,1,1,1,0,0},{0,0,1,1,1,0,1},{0,0,1,1,1,1,0},{0,0,1,1,1,1,1},{0,1,0,0,0,0,0},{0,1,0,0,0,0,1},{0,1,0,0,0,1,0},{0,1,0,0,0,1,1},{0,1,0,0,1,0,0},{0,1,0,0,1,0,1},{0,1,0,0,1,1,0},{0,1,0,0,1,1,1},{0,1,0,1,0,0,0},{0,1,0,1,0,0,1},{0,1,0,1,0,1,0},{0,1,0,1,0,1,1},{0,1,0,1,1,0,0},{0,1,0,1,1,0,1},{0,1,0,1,1,1,0},{0,1,0,1,1,1,1},{0,1,1,0,0,0,0},{0,1,1,0,0,0,1},{0,1,1,0,0,1,0},{0,1,1,0,0,1,1},{0,1,1,0,1,0,0},{0,1,1,0,1,0,1},{0,1,1,0,1,1,0},{0,1,1,0,1,1,1},{0,1,1,1,0,0,0},{0,1,1,1,0,0,1},{0,1,1,1,0,1,0},{0,1,1,1,0,1,1},{0,1,1,1,1,0,0},{0,1,1,1,1,0,1},{0,1,1,1,1,1,0},{0,1,1,1,1,1,1},{1,0,0,0,0,0,0},{1,0,0,0,0,0,1},{1,0,0,0,0,1,0},{1,0,0,0,0,1,1},{1,0,0,0,1,0,0},{1,0,0,0,1,0,1},{1,0,0,0,1,1,0},{1,0,0,0,1,1,1},{1,0,0,1,0,0,0},{1,0,0,1,0,0,1},{1,0,0,1,0,1,0},{1,0,0,1,0,1,1},{1,0,0,1,1,0,0},{1,0,0,1,1,0,1},{1,0,0,1,1,1,0},{1,0,0,1,1,1,1},{1,0,1,0,0,0,0},{1,0,1,0,0,0,1},{1,0,1,0,0,1,0},{1,0,1,0,0,1,1},{1,0,1,0,1,0,0},{1,0,1,0,1,0,1},{1,0,1,0,1,1,0},{1,0,1,0,1,1,1},{1,0,1,1,0,0,0},{1,0,1,1,0,0,1},{1,0,1,1,0,1,0},{1,0,1,1,0,1,1},{1,0,1,1,1,0,0},{1,0,1,1,1,0,1},{1,0,1,1,1,1,0},{1,0,1,1,1,1,1},{1,1,0,0,0,0,0},{1,1,0,0,0,0,1},{1,1,0,0,0,1,0},{1,1,0,0,0,1,1}}; // volume

void setup(){ 
  pinMode(2, OUTPUT); // data
  pinMode(3, OUTPUT); // clk
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(1000);
}


void loop(){
  audio();
  delay(1000);
}

void audio(){
  Slot1(1,1,0,8,8,0); // input selector, REC-Output Gain Control, ADC Input ATT, bass (0=+14dB,8=0dB,15=-14dB), treble (0=+14dB,8=0dB,15=-14dB), Input Gain
  Slot2(0,0,0,0); // gain0, volume0, gain1, volume1
  Slot3(0,0,0,0); // gain2, volume2, gain3, volume3
  Slot4(0,0,0,0); // gain4, volume4, gain5, volume5
}

void Slot1(int in, int out_gain, int att, int bass, int treb, int in_gain){
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
    digitalWrite(DATA, LOW); // 0
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
    digitalWrite(DATA, LOW); // 0
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
    // 22 bit LOW
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(2);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    delayMicroseconds(2);
    // 23 bit  LOW
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(2);
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW);
    delayMicroseconds(2);
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
    
    digitalWrite(DATA, LOW); // 0  || 20 bit
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW); // 0  || 21 bit
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 22 bit LOW
    digitalWrite(DATA, LOW); 
    digitalWrite(CLK, HIGH);
    delayMicroseconds(2);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    delayMicroseconds(2);
    // 23 bit  HIGH
    digitalWrite(DATA, HIGH);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(2);
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW);
    delayMicroseconds(2);   
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
    
    digitalWrite(DATA, LOW); // 0  || 20 bit
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW); // 0  || 21 bit
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 22 bit LOW
    digitalWrite(DATA, LOW); 
    digitalWrite(CLK, HIGH);
    delayMicroseconds(2);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    delayMicroseconds(2);
    // 23 bit  HIGH
    digitalWrite(DATA, HIGH);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(2);
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW);
    delayMicroseconds(2);   
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
    
    digitalWrite(DATA, LOW); // 0  || 20 bit
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW); // 0  || 21 bit
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    // 22 bit LOW
    digitalWrite(DATA, LOW); 
    digitalWrite(CLK, HIGH);
    delayMicroseconds(2);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
    delayMicroseconds(2);
    // 23 bit  HIGH
    digitalWrite(DATA, HIGH);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(2);
    digitalWrite(CLK, LOW);
    digitalWrite(DATA, LOW);
    delayMicroseconds(2);   
}
