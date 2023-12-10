#include <Arduino.h>
//#include <OSCBoards.h>
//#include <SLIPEncodedSerial.h>
//
//#ifdef BOARD_HAS_USB_SERIAL
//SLIPEncodedUSBSerial SLIPSerial( thisBoardsSerialUSB );
//#else
//SLIPEncodedSerial SLIPSerial(Serial); // Change to Serial1 or Serial2 etc. for boards with multiple serial ports that don’t have Serial
//#endif
int num_pins = 25;
const int NumFSRpins = 16;
byte inputAnalogPins[NumFSRpins];
const byte Input0Pin = A0;
const byte Input1Pin = A1;



void setup() {
  // put your setup code here, to run once:
    //start serial connection

  Serial.begin(19200);
  //start a new SLIP Packet
  //SLIPSerial.beginPacket();
  //send the data
 // uint8_t FSRpins[NumFSRpins];
 // FSRpins[] = [A0, A1, A2, A3, A4, A5, A6, A7];
 

  for (byte i = 0; i < NumFSRpins; ++i) {
      inputAnalogPins[i] = A0 + i; // Assuming A0, A1, A2, ..., A15 are sequential
  }

  //configure pin 2 as an input and enable the internal pull-up resistor
  for (int i = 53; i >=27; i--) {
  pinMode(i, INPUT_PULLUP);

  }
}

void loop() {
  //OSCBundle bundle
  uint8_t pin_read[num_pins]; 
  for (int i = 53; i >=28; i--) {
  pin_read[53-i] = !digitalRead(i);
  }
  //create a new OSCMessage and add some data to it
 for (int i = 0; i <= 24; i++) {
 Serial.print(pin_read[i]);
 }

  //for (int i = 0; i <= 8; i++){
  
  for (byte i = 0; i < 16; ++i) {
  Serial.print(" ");
  Serial.print(analogRead(inputAnalogPins[i]));
  }
 //Serial.print(" ");
 //Serial.print(analogRead(A1));
 //Serial.print(" ");
 //Serial.print(analogRead(A2));
 //Serial.print(" ");
 //Serial.print(analogRead(A3));
 //Serial.print(" ");
 //Serial.print(analogRead(A4));
 //Serial.print(" ");
 //Serial.print(analogRead(A5));
 //Serial.print(" ");
 //Serial.print(analogRead(A6));
 //Serial.print(" ");
 //Serial.print(analogRead(A7));
  
  Serial.println();
  //Serial.print(" ");
  //Serial.print(44);
  //Serial.print(" ");
  //Serial.println(399);

  //delay(50);

  //bundle.add("/Piano/0").add(&pin_read,num_pins);

//  bundle.getOSCMessage(0);//returns the OSCMessage with the address "/a".
  //bundle.send(SLIPSerial);
  ////read the pushbutton value into a variable
  //
  //bundle.empty(); 

  ////end the packet
  //SLIPSerial.endPacket();
}



