/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/10/2023      **********************/
/***************  MC     : Arduino Uno       **********************/
/***************  SWC    : RTC_Slave       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize the LCD(RS,E,D4,D5,D6,D7)

String receivedData = "";// String to store the received characters

void setup() {
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows
  Serial.begin(9600); // Set the baud rate to match the Serial Monitor
  lcd.setCursor(1, 0);
  lcd.print("Received time:");
}

void loop() {

  if (Serial.available()) {
    char receivedChar = Serial.read(); // Read the incoming character
    
    if (receivedChar != '\r') {
      receivedData += receivedChar;
    } else {
      int hrs, min, sec, PM_AM_flag;
      if (sscanf(receivedData.c_str(), "%02d:%02d:%02d:%02d", &hrs, &min, &sec, &PM_AM_flag) == 4) {
        Serial.print("Received time: ");
        Serial.print(receivedData);
        lcd.setCursor(3, 1);
        lcd.print(receivedData);
        lcd.setCursor(11, 1);
        if (!PM_AM_flag) { //check PM_AM_flag
          lcd.print(" PM");
          Serial.println(" PM");
        }
        else {
          lcd.print(" AM");
          Serial.println(" AM");
        }
      }
      receivedData = ""; //empty buffer ro recive new data
    }
  }
}
