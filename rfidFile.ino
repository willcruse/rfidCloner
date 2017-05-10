#include <SoftwareSerial.h>

//txPin is 6
//rxPin is 8

SoftwareSerial mySerial(6, 8); // makes a SoftwareSerial object called mySerial on pins 6 and 8
char bytes[11]; // makes an array to hold the data from the tags

bool recieve() { //function to recieve the data
  for (int i = 0 ; i < 11;) { // loops so that each byte is added to the array bytes
    bytes[i] = mySerial.read();
    ++i;
  }
  Serial.println("Recieved data");
  for (int i = 0; i < 11, i++;) { //loops to print the data to the terminal for debugging purposes
    Serial.println(bytes[i]);
  }
  return true; // returns a bool as required by the function I did this so that the loop would have to wait for this to be executed before looping again
}

bool transmit() { //function used to transmit the data to a new tag
  int count = 0; //variable count used to kepp track of which array position to use
  while (count < 11) {
    mySerial.write(bytes[count]); //writes to a tag the data held in the bytes array
    ++count;//increments count
  }
  Serial.println("Sent Data"); // prints to the console that the data has been sent
  return true; // returns true for the same reason as stated above
}

void setup() {
  pinMode(6, OUTPUT); //sets the txPin(pin 6) to output mode
  pinMode(8, INPUT); //sets the rxPin(pin 8) to input mode
  mySerial.begin(9600); //begins the software serial at rate 9600
  Serial.begin(9600);
}

void loop() {
  if (mySerial.available() > 0) { //checks to see if there is a card present and if that card contains data
    bool x = recieve(); // calls the recieve function
    delay(1000); //waits 1 second to allow the card to be written to once so the card will be complete
  } else if (mySerial.available() <= 0) { // checks to see if a card is present and it is empty
    bool y = transmit();
    delay(1000);
  }
}
