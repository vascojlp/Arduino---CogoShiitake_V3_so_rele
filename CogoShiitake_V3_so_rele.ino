/* VERSAO OK!!!!!! 
*/// SEM RELE

/*********************************************************************************************************************************************
*********************************************************** ABREVIATURAS ********************************************************************/
 /*
 Pins used by LCD & Keypad Shield:
  
    A0: Buttons, analog input from voltage ladder
    D4: LCD bit 4
    D5: LCD bit 5
    D6: LCD bit 6
    D7: LCD bit 7
    D8: LCD RS
    D9: LCD E
    D3: LCD Backlight (high = on, also has pullup high so default is on)
    
    delay(10 * 60 * 60 * 1000);  10 minutos de delay
      
 */ 
/********************************************************************************************************************************************
******************************************************** BIBLIOTECAS *********************************************************************/
#include <LiquidCrystal.h> 
//#include <dht.h>
#include <Timer.h>
#include "Timer.h"
#include <Wire.h>
#include <RTClib.h>  // Credit: Adafruit, library do RTC
#include "Config.h"

/*********************************************************************************************************************************************
******************************************************** DEFINICAO DE PINOS *****************************************************************/
// Analog Pins 
//#define DHT11sensorPin A1       // Input Humidity sensor and Air temperature 
int tempPin = A2;
#define ManualPin A0               // inout triger rega manual

// digital pins
#define RL1WSRpowerPin 2       // power Output to eletrovÃ¡lvula da Reg
#define d_second 1000

// select the pins used on the LCD panel - TENHO DE ALTERAR OS PINOS (O D4 E D5 SAO O sda E scl)

/*Pins used by LCD & Keypad Shield:
  
    A0: Buttons, analog input from voltage ladder
    
    D4: LCD bit 4 --> D11: LCD bit 4
    D5: LCD bit 5 --> D10: LCD bit 5
    D6: LCD bit 6 --> D9: LCD bit 6
    D7: LCD bit 7 --> D8: LCD bit 7
    D8: LCD RS    --> D12: LCD RS
    D9: LCD E     --> D13: LCD E   
    
    D3: LCD Backlight (high = on, also has pullup high so default is on) */
    
//LiquidCrystal lcd(8, 9, 4, 5, 6, 7); (RS,E,DB4,DB5,DB6,DB7)
//LiquidCrystal(rs, rw, enable, d4, d5, d6, d7) - create a new LiquidCrystal object using a 4 bit data bus
//LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) - createa new LiquidCrystal object using an 8 bit data bus
LiquidCrystal lcd(12, 13, 11, 10, 9, 8);
              
//--- Inicializacao dos Sensores 
//dht DHT;                                        //Inicializa o sensor
RTC_DS1307 RTC;
// digital pins  (SDA - A4 || SCL - A5)

//--- RTC - Definicao Chars 
const int DS1307 = 0x68; // Address of DS1307 see data sheets
const char* days[] =
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* months[] =
{"January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};
 
byte second = 0;
byte minute = 0;
byte hour = 0;
byte weekday = 0;
byte monthday = 0;
byte month = 0;
byte year = 0;

/*********************************************************************************************************************************************
************************************************************ VOID SETUP *********************************************************************/
void setup() {
  
  Serial.begin(57600); 
  
  lcd.begin(16, 2);                    // start the library

  // Inicializacao do RTC
  Wire.begin();
  RTC.begin();
     
  //--- BOOT
  Serial.println(F("CogoShiitake V1"));
  Serial.print(F("\n"));
  
  lcd.setCursor(0,0);                  //Situamos o cursor no caracter 0, linha 
  lcd.print(F("BOOTING..."));
  delay(1000); 
  lcd.clear();
  lcd.print(F("BOOTING......"));
  delay(1000); 
  lcd.clear();
  lcd.print(F("BOOTING........."));
  delay(1000);   
  lcd.clear();                  
  lcd.print(F("COGOSHIITAKE 1.0"));
  delay(2000);       
  
  //--- Config values
 Config_values();            
             
  //--- ACERTAR A HORA 
   //Acertar_Hora();
  
  //--- Analog pins
  //pinMode(DHT11sensorPin,INPUT);
  pinMode(ManualPin,INPUT);

  //--- Digital pins
  digitalWrite(RL1WSRpowerPin,HIGH);
  pinMode(RL1WSRpowerPin,OUTPUT);
    
}

/************************************************************* VOID LOOP *********************************************************************/
void loop() {
  
  Keypad(); 
  Data_Print();
  Keypad();
  Read_sensors();
  Keypad();
  Rega ();
  //Print_values();

 //######################## CONTROL SENSOR HUMIDADE ################################
 //Sensor_Humidade();
  
 //######################## CONTROL SENSOR TEMPERATURA #############################
//Temperatura();
 
}
/********************************************************** FIM VOID LOOP *******************************************************************/
 byte decToBcd(byte val) {
  return ((val/10*16) + (val%10));
}
byte bcdToDec(byte val) {
  return ((val/16*10) + (val%16));
}

/******************************************************************************************************************************************/
void setTime() {
 
  Serial.print(F("Please enter the current year, 00-99. - "));
  year = readByte();
  Serial.println(year);
  Serial.print(F("Please enter the current month, 1-12. - "));
  month = readByte();
  Serial.println(months[month-1]);
  Serial.print(F("Please enter the current day of the month, 1-31. - "));
  monthday = readByte();
  Serial.println(monthday);
  Serial.println(F("Please enter the current day of the week, 1-7."));
  Serial.print(F("1 Sun | 2 Mon | 3 Tues | 4 Weds | 5 Thu | 6 Fri | 7 Sat - "));
  weekday = readByte();
  Serial.println(days[weekday-1]);
  Serial.print(F("Please enter the current hour in 24hr format, 0-23. - "));
  hour = readByte();
  Serial.println(hour);
  Serial.print(F("Please enter the current minute, 0-59. - "));
  minute = readByte();
  Serial.println(minute);
  second = 0;
  Serial.println(F("The data has been entered."));
 
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}

byte readByte() {
  while (!Serial.available()) delay(10);
  byte reading = 0;
  byte incomingByte = Serial.read();
  while (incomingByte != '\n') {
    if (incomingByte >= '0' && incomingByte <= '9')
      reading = reading * 10 + (incomingByte - '0');
    else;
    incomingByte = Serial.read();
  }
  Serial.flush();
  return reading;
}

/******************************************************************************************************************************************/
void printTime() {
  char buffer[3];
  readTime();
  Serial.print(days[weekday-1]);
  Serial.print(F(" "));
  Serial.print(months[month-1]);
  Serial.print(F(" "));
  Serial.print(monthday);
  Serial.print(F(", 20"));
  Serial.print(year);
  Serial.print(F(" "));
  /*if (hour > 12) {
    hour -= 12;
    AMPM = " PM";
  }
  else AMPM = " AM";*/
  Serial.print(hour);
  Serial.print(F(":"));
  sprintf(buffer, "%02d", minute);
  Serial.print(buffer);
  //Serial.println(AMPM);
}

/*****************************************************************************************************************************************/
void readTime() {
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.endTransmission();
  Wire.requestFrom(DS1307, 7);
  second = bcdToDec(Wire.read());
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read());
  weekday = bcdToDec(Wire.read());
  monthday = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());
}

/*********************************************************************************************************************************************
************************************************************** FIM  DO PROGRAMA *************************************************************
*********************************************************************************************************************************************/

