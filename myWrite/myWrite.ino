#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 6

SoftwareSerial sSerial(rxPin, txPin);

void setup() {
  
  Serial.begin(9600);
  Serial.println("RFID WRITE TEST");
  sSerial.begin(9600); //used same baud rate for both. The baud rate is the rate of impulses per second data is transmitted.
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
}

void loop() {
    int val[] = {9, 16, 25, 36};
    sSerial.print("!RW");
    sSerial.write(byte(0x02));
    sSerial.write(byte(3));
    for (int i = 0; i < 4; i++) {
        sSerial.write(byte(val[i]));
    }
    if(sSerial.available() > 0){
        int data = sSerial.read();
        if(data == 1){
            Serial.println("Written");
            suppress();
        }else{
            suppress();
        }
    }
    delay(250);
}

void suppress(){
    if(sSerial.available() > 0) { 
      sSerial.read();
      suppress();
    }
}
