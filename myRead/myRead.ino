#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 6

SoftwareSerial sSerial(rxPin, txPin);
int val; 

void setup() {
  
  Serial.begin(9600);
  Serial.println("RFID WRITE TEST");
  sSerial.begin(9600); //used same baud rate for both. The baud rate is the rate of impulses per second data is transmitted.
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
}

void loop() {
    sSerial.print("!RW");
    sSerial.write(byte(0x01));
    sSerial.write(byte(32));
    if(sSerial.available() > 0){
        int data = sSerial.read();
        if(data != 1){
            suppress();
        }
    }
    if(sSerial.available() > 0) {      
    val = sSerial.read();
    Serial.println(val, HEX);
    }

if(sSerial.available() > 0) {        
    val = sSerial.read();
    Serial.println(val, HEX);
    }

if(sSerial.available() > 0) {      
    val = sSerial.read();
    Serial.println(val, HEX);
    }

if(sSerial.available() > 0) {          
    val = sSerial.read();
    Serial.println(val, HEX);
    }  
    delay(500);
}

void suppress(){
    if(sSerial.available() > 0) { 
      sSerial.read();
      suppress();
    }
}



