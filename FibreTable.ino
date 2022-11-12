/*
 * Created by Kevin Janssens on 08/09/2022.
 * Copyright © 2019 JKelectronics. All rights reserved.
 */

//Fibre Optics Table

/*
 * Wiring: 
 * SIG to analog pin (edit pinnr in code)
 * s0-s4 digital pins (edit pinnr's in code)
 */

 
#include <Adafruit_NeoPixel.h>
#define neoPin 6
#define NumPixels 64
Adafruit_NeoPixel pixels(NumPixels, neoPin, NEO_GRB + NEO_KHZ800);

// thresholdvalue for ir analogReadings
const int thresholdIR = 400;

//control pins mux1
int s0 = 14;
int s1 = 13;
int s2 = 12;
int s3 = 2;

//mux2
int ss0 = 18; // set pins(not yet figured out)
int ss1 = 19;
int ss2 = 20;
int ss3 = 21;

//analog pin
int sigPin = 15; // mux1
int sigPin2 = 22; // mux2 (pin not figured out)


void setup(){
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT);

  pinMode(ss0, OUTPUT);
  pinMode(ss1, OUTPUT);
  pinMode(ss2, OUTPUT);
  pinMode(ss3, OUTPUT);
  
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  digitalWrite(ss0, LOW);
  digitalWrite(ss1, LOW);
  digitalWrite(ss2, LOW);
  digitalWrite(ss3, LOW);
  
  Serial.begin(115200);

  pixels.begin();
}
 
void loop(){

  //Loop through and read all 16 values
  for(int i = 0; i < 16; i ++){
    Serial.print("Value at channel ");
    Serial.print(i);
    Serial.print("is : ");
    Serial.println(readMux(i));
    delay(100);
  }

  for(int j = 0; j < 16; j ++){
    Serial.print("Value at channel ");
    Serial.print(j);
    Serial.print("is : ");
    Serial.println(readMux(j));
    delay(100);
  }
  
  ledSwitching();
}


int readMux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = analogRead(sigPin);

  //return the value
  return val;
}

int readMux2(int channel){
  int controlPin2[] = {ss0, ss1, ss2, ss3};

  int muxChannel2[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin2[i], muxChannel2[channel][i]);
  }

  //read the value at the SIG pin
  int val2 = analogRead(sigPin2);

  //return the value
  return val2;
}

void ledSwitching(){
  
 int val00 = readMux(0);
  if (val00 > thresholdIR){
    pixels.setPixelColor((0),(105), (50), (95));
    pixels.setPixelColor((1), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((0),(0), (0), (0));
    pixels.setPixelColor((1), (0), (0), (0));
    pixels.show();
  }
 int val01 = readMux(1);
  if (val01 > thresholdIR){
    pixels.setPixelColor((2),(105), (50), (95));
    pixels.setPixelColor((3), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((2),(0), (0), (0));
    pixels.setPixelColor((3), (0), (0), (0));
    pixels.show();
  }
 int val02 = readMux(2);
  if (val02 > thresholdIR){
    pixels.setPixelColor((4),(105), (50), (95));
    pixels.setPixelColor((5), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((4),(0), (0), (0));
    pixels.setPixelColor((5), (0), (0), (0));
    pixels.show();
  }
 int val03 = readMux(3);
  if (val03 > thresholdIR){
    pixels.setPixelColor((6),(105), (50), (95));
    pixels.setPixelColor((7), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((6),(0), (0), (0));
    pixels.setPixelColor((7), (0), (0), (0));
    pixels.show();
  }
 int val04 = readMux(4);
  if (val04 > thresholdIR){
    pixels.setPixelColor((8),(105), (50), (95));
    pixels.setPixelColor((9), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((8),(0), (0), (0));
    pixels.setPixelColor((9), (0), (0), (0));
    pixels.show();
  }
 int val05 = readMux(5);
  if (val05 > thresholdIR){
    pixels.setPixelColor((10),(105), (50), (95));
    pixels.setPixelColor((11), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((10),(0), (0), (0));
    pixels.setPixelColor((11), (0), (0), (0));
    pixels.show();
  }
 int val06 = readMux(6);
  if (val06 > thresholdIR){
    pixels.setPixelColor((12),(105), (50), (95));
    pixels.setPixelColor((13), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((12),(0), (0), (0));
    pixels.setPixelColor((13), (0), (0), (0));
    pixels.show();
  }
 int val07 = readMux(7);
  if (val07 > thresholdIR){
    pixels.setPixelColor((14),(105), (50), (95));
    pixels.setPixelColor((15), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((14),(0), (0), (0));
    pixels.setPixelColor((15), (0), (0), (0));
    pixels.show();
  }
 int val08 = readMux(8);
  if (val08 > thresholdIR){
    pixels.setPixelColor((16),(105), (50), (95));
    pixels.setPixelColor((17), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((16),(0), (0), (0));
    pixels.setPixelColor((17), (0), (0), (0));
    pixels.show();
  }
 int val09 = readMux(9);
  if (val09 > thresholdIR){
    pixels.setPixelColor((18),(105), (50), (95));
    pixels.setPixelColor((19), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((18),(0), (0), (0));
    pixels.setPixelColor((19), (0), (0), (0));
    pixels.show();
  }
 int val10 = readMux(10);
  if (val10 > thresholdIR){
    pixels.setPixelColor((20),(105), (50), (95));
    pixels.setPixelColor((21), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((20),(0), (0), (0));
    pixels.setPixelColor((21), (0), (0), (0));
    pixels.show();
  }
 int val11 = readMux(11);
  if (val11 > thresholdIR){
    pixels.setPixelColor((22),(105), (50), (95));
    pixels.setPixelColor((23), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((22),(0), (0), (0));
    pixels.setPixelColor((23), (0), (0), (0));
    pixels.show();
  }
 int val12 = readMux(12);
  if (val12 > thresholdIR){
    pixels.setPixelColor((24),(105), (50), (95));
    pixels.setPixelColor((25), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((24),(0), (0), (0));
    pixels.setPixelColor((25), (0), (0), (0));
    pixels.show();
  }
 int val13 = readMux(13);
  if (val13 > thresholdIR){
    pixels.setPixelColor((26),(105), (50), (95));
    pixels.setPixelColor((27), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((26),(0), (0), (0));
    pixels.setPixelColor((27), (0), (0), (0));
    pixels.show();
  }
 int val14 = readMux(14);
  if (val14 > thresholdIR){
    pixels.setPixelColor((28),(105), (50), (95));
    pixels.setPixelColor((29), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((28),(0), (0), (0));
    pixels.setPixelColor((29), (0), (0), (0));
    pixels.show();
  }
  int val15 = readMux(15);
  if (val15 > thresholdIR){
    pixels.setPixelColor((30),(105), (50), (95));
    pixels.setPixelColor((31), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((30),(0), (0), (0));
    pixels.setPixelColor((31), (0), (0), (0));
    pixels.show();
  }
 
 // mux2 led's 32-63
  int val16 = readMux2(0);
  if (val16 > thresholdIR){
    pixels.setPixelColor((32),(105), (50), (95));
    pixels.setPixelColor((33), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((32),(0), (0), (0));
    pixels.setPixelColor((33), (0), (0), (0));
    pixels.show();
  }
 int val17 = readMux2(1);
  if (val17 > thresholdIR){
    pixels.setPixelColor((34),(105), (50), (95));
    pixels.setPixelColor((35), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((34),(0), (0), (0));
    pixels.setPixelColor((35), (0), (0), (0));
    pixels.show();
  }
 int val18 = readMux2(2);
  if (val18 > thresholdIR){
    pixels.setPixelColor((36),(105), (50), (95));
    pixels.setPixelColor((37), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((36),(0), (0), (0));
    pixels.setPixelColor((37), (0), (0), (0));
    pixels.show();
  }
 int val19 = readMux2(3);
  if (val19 > thresholdIR){
    pixels.setPixelColor((38),(105), (50), (95));
    pixels.setPixelColor((39), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((38),(0), (0), (0));
    pixels.setPixelColor((39), (0), (0), (0));
    pixels.show();
  }
 int val20 = readMux2(4);
  if (val20 > thresholdIR){
    pixels.setPixelColor((40),(105), (50), (95));
    pixels.setPixelColor((41), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((40),(0), (0), (0));
    pixels.setPixelColor((41), (0), (0), (0));
    pixels.show();
  }
 int val21 = readMux2(5);
  if (val21 > thresholdIR){
    pixels.setPixelColor((42),(105), (50), (95));
    pixels.setPixelColor((43), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((42),(0), (0), (0));
    pixels.setPixelColor((43), (0), (0), (0));
    pixels.show();
  }
 int val22 = readMux2(6);
  if (val22 > thresholdIR){
    pixels.setPixelColor((44),(105), (50), (95));
    pixels.setPixelColor((45), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((44),(0), (0), (0));
    pixels.setPixelColor((45), (0), (0), (0));
    pixels.show();
  }
 int val23 = readMux2(7);
  if (val23 > thresholdIR){
    pixels.setPixelColor((46),(105), (50), (95));
    pixels.setPixelColor((47), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((46),(0), (0), (0));
    pixels.setPixelColor((47), (0), (0), (0));
    pixels.show();
  }
 int val24 = readMux2(8);
  if (val24 > thresholdIR){
    pixels.setPixelColor((48),(105), (50), (95));
    pixels.setPixelColor((49), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((48),(0), (0), (0));
    pixels.setPixelColor((49), (0), (0), (0));
    pixels.show();
  }
 int val25 = readMux2(9);
  if (val25 > thresholdIR){
    pixels.setPixelColor((50),(105), (50), (95));
    pixels.setPixelColor((51), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((50),(0), (0), (0));
    pixels.setPixelColor((51), (0), (0), (0));
    pixels.show();
  }
 int val26 = readMux2(10);
  if (val26 > thresholdIR){
    pixels.setPixelColor((52),(105), (50), (95));
    pixels.setPixelColor((53), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((52),(0), (0), (0));
    pixels.setPixelColor((53), (0), (0), (0));
    pixels.show();
  }
 int val27 = readMux2(11);
  if (val27 > thresholdIR){
    pixels.setPixelColor((54),(105), (50), (95));
    pixels.setPixelColor((55), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((54),(0), (0), (0));
    pixels.setPixelColor((55), (0), (0), (0));
    pixels.show();
  }
 int val28 = readMux2(12);
  if (val28 > thresholdIR){
    pixels.setPixelColor((56),(105), (50), (95));
    pixels.setPixelColor((57), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((56),(0), (0), (0));
    pixels.setPixelColor((57), (0), (0), (0));
    pixels.show();
  }
 int val29 = readMux2(13);
  if (val29 > thresholdIR){
    pixels.setPixelColor((58),(105), (50), (95));
    pixels.setPixelColor((59), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((58),(0), (0), (0));
    pixels.setPixelColor((59), (0), (0), (0));
    pixels.show();
  }
 int val30 = readMux2(14);
  if (val30 > thresholdIR){
    pixels.setPixelColor((60),(105), (50), (95));
    pixels.setPixelColor((61), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((60),(0), (0), (0));
    pixels.setPixelColor((61), (0), (0), (0));
    pixels.show();
  }
  int val31 = readMux2(15);
  if (val31 > thresholdIR){
    pixels.setPixelColor((62),(105), (50), (95));
    pixels.setPixelColor((63), (150), (76), (130));
    pixels.show();
}
  else{
    pixels.setPixelColor((62),(0), (0), (0));
    pixels.setPixelColor((63), (0), (0), (0));
    pixels.show();
  }
 
}
