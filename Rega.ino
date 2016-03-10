void Rega () {
 
  DateTime myRTC = RTC.now();
  Hr = (myRTC.hour());
  H = (myRTC.hour()); 
  
 if (H >= X && H <= Y && currentMillisSM == 0) {                            // REGA AS 7:00
      lcd.clear();
      Serial.print(F("A REGAR..."));
      lcd.print(F("A REGAR..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL1WSRpowerPin, LOW);
      delay(180000);
      digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
      currentMillisSM = millis();
      } 
      
     if (H >= X && H <= Y && currentMillisSM + 72000000 <= millis()){        // REGA AS 7:00 DO DIA SEGUINTE - 20 HORAS DEPOIS
      lcd.clear();
      Serial.print(F("A REGAR..."));
      lcd.print(F("A REGAR..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL1WSRpowerPin, LOW);
      delay(180000);
      digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
      currentMillisSM = millis();     
  } 
       
      if (H >= U && H <= V && currentMillisM == 0){                          // REGA AO 12:00
      lcd.clear();
      Serial.print(F("A REGAR..."));
      lcd.print(F("A REGAR..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL1WSRpowerPin, LOW);
      delay(180000);
      digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
      currentMillisM = millis();     
  }

  if (H >= U && H <= V && currentMillisM + 72000000 <= millis()){            // REGA AO 12:00 DO DIA SEGUINTE - 20 HORAS DEPOIS
        lcd.clear();
        Serial.print(F("A REGAR..."));
        lcd.print(F("A REGAR..."));
        Serial.print(F("\n"));
        Serial.print(F("  \n"));
        digitalWrite(RL1WSRpowerPin, LOW);
        delay(180000);
        digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
        currentMillisM = millis();     
    }        
   
   if (Hr >= W && Hr <= Z && currentMillis == 0) {                          // REGA AS 20:00
      lcd.clear();
      Serial.print(F("A REGAR..."));
      lcd.print(F("A REGAR..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL1WSRpowerPin, LOW);
      delay(180000);
      digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
      currentMillis = millis();
      }       
      
      if (Hr >= W && Hr <= Z && currentMillis + 72000000 <= millis()){        // REGA AS 20:00 DO DIA SEGUINTE - 20 HORAS DEPOIS
      lcd.clear();
      Serial.print(F("A REGAR..."));
      lcd.print(F("A REGAR..."));
      Serial.print(F("\n"));
      Serial.print(F("  \n"));
      digitalWrite(RL1WSRpowerPin, LOW);
      delay(180000);
      digitalWrite(RL1WSRpowerPin,HIGH);    // turn off Rega
      currentMillis = millis(); 
  }  
 
}
