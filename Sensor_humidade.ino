void Sensor_Humidade() {
 
 if ( 0 < Hr && Hr < 24) {
   
   if( currentMillis < 20000) {
     
    lcd.clear();                                 
    lcd.print(F("REGA EM..."));
    Serial.print(F("REGA EM..."));
    lcd.setCursor(0, 1);                         
    lcd.print(F("...MODO AUTO!"));
    delay(1000);
    Serial.print(F("...MODO AUTO!"));
    Serial.print(F(" \n"));
    Serial.print(F("  \n"));
    digitalWrite(RL1WSRpowerPin, LOW);
    delay (10000);                            
    digitalWrite(RL1WSRpowerPin, HIGH);
   
   currentMillis = millis();
   }   
   
   //if ( H > 9 && H < 10 && currentMillis + 72000000 <= millis()){          //20 horas passadas
   if ( H == 9 ){          //20 horas passadas
    
    lcd.clear();                                 
    lcd.print(F("REGA EM..."));
    Serial.print(F("REGA EM..."));
    lcd.setCursor(0, 1);                         
    lcd.print(F("...MODO AUTO!"));
    delay(1000);
    Serial.print(F("...MODO AUTO!"));
    Serial.print(F(" \n"));
    Serial.print(F("  \n"));
    digitalWrite(RL1WSRpowerPin, LOW);
    delay (1800000);                            
    digitalWrite(RL1WSRpowerPin, HIGH); 
   
   currentMillis = millis();
   }
   
  else { 
   digitalWrite(RL1WSRpowerPin, HIGH);
  }

    }
    
    if ( H == 18 ){          //20 horas passadas
    
    lcd.clear();                                 
    lcd.print(F("REGA EM..."));
    Serial.print(F("REGA EM..."));
    lcd.setCursor(0, 1);                         
    lcd.print(F("...MODO AUTO!"));
    delay(1000);
    Serial.print(F("...MODO AUTO!"));
    Serial.print(F(" \n"));
    Serial.print(F("  \n"));
    digitalWrite(RL1WSRpowerPin, LOW);
    delay (1800000);                            
    digitalWrite(RL1WSRpowerPin, HIGH); 
   
   currentMillis = millis();
   }
   
  else { 
   digitalWrite(RL1WSRpowerPin, HIGH);
  } 
    
  
}
