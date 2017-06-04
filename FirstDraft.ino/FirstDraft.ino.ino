#include <SoftwareSerial.h>
#define rxPin 8
#define txPin 6

SoftwareSerial sSerial(rxPin, txPin);
int data;

void setup() {
  Serial.begin(9600);
  Serial.println("RFID READ TEST");
  sSerial.begin(9600); //used same baud rate for both. The baud rate is the rate of impulses per second data is transmitted.
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
}

void clearCard(){
    
}

void loop() {
  sSerial.write(byte("!RW"));
  sSerial.write(byte(0x02));
  sSerial.write(byte(32));
  if (sSerial.available() > 0) {
    data = sSerial.read();
    if (data != 1) {} //since the first byte read is a status code where 1 means the read was successful if the data is anything other than that the data is corrupted and useless

    if (sSerial.available() > 0) {
      Serial.print(" 1st:  ");
      Serial.print(sSerial.read(), HEX); //Prints first byte read
    }

    if (sSerial.available() > 0) {
      Serial.print(" 2nd:  ");
      Serial.print(sSerial.read(), HEX); //Prints second byte read
    }

    if (sSerial.available() > 0) {
      Serial.print(" 3rd:  ");
      Serial.print(sSerial.read(), HEX); //Prints third byte read
    }

    if (sSerial.available() > 0) {
      Serial.print(" 4th:  ");
      Serial.println(sSerial.read(), HEX); //Prints fourth byte read
      Serial.println("EOF");
    }
  }

  delay(750);
}
