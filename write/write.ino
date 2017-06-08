#include <SoftwareSerial.h>

const byte rxPin = 8;
const byte txPin = 6;
SoftwareSerial sSerial(rxPin, txPin);
int val = 0;

void setup() {
  
  Serial.begin(9600);
  Serial.println("RFID WRITE TEST");
  sSerial.begin(9600); //used same baud rate for both. The baud rate is the rate of impulses per second data is transmitted.
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
}

void loop() {
    if(sSerial.available() > 0){
        Serial.println("Already written to!");
        return;
    }
    if (val == 0){
        sSerial.print("!RW");
        sSerial.write(byte(0x02));
        sSerial.write(byte(3));
        val++;
        int myValues[] = {1, 2, 3, 4};
        for(int i = 0; i < 4; i++) {
            sSerial.write(byte(myValues[i]));
        }
        Serial.print("Written Successfully");
    }
}
