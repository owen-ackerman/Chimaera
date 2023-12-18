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
const int MultiplexA = 11;
const int MultiplexB = 12;
const int MultiplexC = 13;
const int StartStopPin = 7;
const int SampleHoldPin = 6;
const int OctaveUP  = 5;
const int OctaveDown = 4;
const int JoystickButton = 3;





void setup() {
  // put your setup code here, to run once:
    //start serial connection

  Serial.begin(38400);
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

   pinMode(MultiplexA, OUTPUT); 
   pinMode(MultiplexB, OUTPUT); 
   pinMode(MultiplexC, OUTPUT); 
   pinMode(StartStopPin,  INPUT);
   pinMode(SampleHoldPin, INPUT );
   pinMode(OctaveUP,    INPUT);
   pinMode(OctaveDown, INPUT );
   pinMode(JoystickButton, INPUT);
  //pinMode(LeftOutApin,  INPUT_PULLUP);
  //pinMode(LeftOutBpin,  INPUT_PULLUP);
digitalWrite(MultiplexA, 0);
digitalWrite(MultiplexB, 0);
digitalWrite(MultiplexC, 0); //000

}


//void LeftRotaryEncoder() {
//  LeftState = digitalRead(LeftOutApin);
//  if (LeftState != LeftLastState) {
//    if (digitalRead(LeftOutBpin) != LeftState) {
//      LeftCounter ++;
//    } else {
//      LeftCounter --;
//    }
//  }
//  LeftLastState = LeftState;
//}

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
  for (byte i = 4; i < 16; ++i) {
  Serial.print(" ");
  Serial.print(analogRead(inputAnalogPins[i]));
  }

digitalWrite(MultiplexA, 0); //000
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[0]));
digitalWrite(MultiplexC, 1); //001
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[0]));
digitalWrite(MultiplexB, 1); //011
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[0]));
digitalWrite(MultiplexC, 0); //010
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[0]));


//digitalWrite(Multiplex1, 0);
//Serial.print(" ");
//Serial.print(analogRead(inputAnalogPins[0]));
//  Serial.println();


//
//  
//  
digitalWrite(MultiplexA, 1);//110
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[0]));
digitalWrite(MultiplexC, 1);//111
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[0]));
digitalWrite(MultiplexB, 0);//101
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[0]));
digitalWrite(MultiplexC, 0);//100
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[0]));
  Serial.print(" ");

Serial.print(analogRead(inputAnalogPins[2]));
Serial.print(" ");
Serial.print(analogRead(inputAnalogPins[3]));
Serial.print(" ");

  Serial.print(digitalRead(StartStopPin));
  Serial.print(" ");
  Serial.print(digitalRead(SampleHoldPin));

  Serial.print(" ");
  Serial.print(digitalRead(OctaveUP));
  Serial.print(" ");
  Serial.print(digitalRead(OctaveDown));
  Serial.print(" ");
  Serial.print(digitalRead(JoystickButton));
  Serial.println();
//
//  // put your main code here, to run repeatedly:
//LeftRotaryEncoder();
//
//Serial.print("Left: ");
//
//Serial.println(LeftCounter);

//Serial.print(digitalRead(LeftOutApin));
//Serial.print(" ");
//Serial.print(digitalRead(LeftOutBpin)); 
//Serial.println();


}


  //for (byte i = 0; i < 1; ++i) {
  //digitalWrite(Multiplex1, i);
  //analogRead(inputAnalogPins[13]);
  //}
  //digitalWrite(Multiplex1, 1);
  //Serial.print(" ");
  //Serial.print(analogRead(inputAnalogPins[13]));
  //Serial.print(" ");
  //Serial.print(analogRead(inputAnalogPins[14]));
  //digitalWrite(Multiplex1, 0);
  //Serial.print(" ");
  //Serial.print(analogRead(inputAnalogPins[13]));
  //Serial.print(" ");
  //Serial.print(analogRead(inputAnalogPins[14]));


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




