/* 
With this sketch, you can turn on an LED or switch a relay when a magnetic card is passed over the RFID reader.
If the card is recognized, a green LED lights up and the relay switches. Otherwise, a red LED indicates inaccessibility.

PINOUT:
RC522 Module   Uno/Nano
SDA            D10
SCK            D13
MOSI           D11
MISO           D12
IRQ            N/A
GND            GND
RST            D9
3.3V           3.3V

Green LED at Pin 3
Red LED at Pin 4
Relay at Pin 2
*/

#include <SPI.h>
#include <RFID.h>

/* Define PINs of the RFID reader */
#define SDA_DIO 10  // Pin 53 for Arduino Mega
#define RESET_DIO 9
#define delayRead 1000 // Time delay for reading
#define delayLed 2000 // Time delay for LED

#define ledVerde 3
#define ledRosso 4
#define rele 2

/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO); 

// Insert hexadecimal codes of recognized magnetic cards
String authorizedCode1 = "FCA2333B56";
String authorizedCode2 = "EXAMPLE479";
String authorizedCode3 = "EXAMPLE480";

void setup() { 
  Serial.begin(9600);
  /* Enable SPI */
  SPI.begin(); 
  /* Initialize RFID reader */
  RC522.init();
  Serial.println("Setup");
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRosso, OUTPUT);
  pinMode(rele, OUTPUT);
}

void loop() {
  /* Temporary loop counter */
  byte i;
  
  // If a card is detected
  if (RC522.isCard()) {
    // Read its code
    RC522.readCardSerial();
    String readCode = "";
    Serial.println("Card Code Read:");
  
    // Load the card code into a String
    for (i = 0; i <= 4; i++) {
      readCode += String(RC522.serNum[i], HEX);
      readCode.toUpperCase();
    }
    Serial.println(readCode);
    
    if (checkCode(readCode, authorizedCode1) || checkCode(readCode, authorizedCode2) || checkCode(readCode, authorizedCode3)) {
      Serial.println("Authorized Card");
      turnOnLed(ledVerde);
      digitalWrite(rele, HIGH);
      delay(1000); // Time relay is ON
      digitalWrite(rele, LOW);
    } else {
      Serial.println("Unauthorized Card");
      turnOnLed(ledRosso);
    }
    delay(delayRead);  
  }
}

// This function checks if the read code is authorized
boolean checkCode(String readCode, String authorizedCode) {
  if (readCode.equals(authorizedCode)) {
    return true;
  } else {
    return false;
  }  
}    

// This function turns on an LED for a specified period
void turnOnLed(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(delayLed);
  digitalWrite(ledPin, LOW);
}
