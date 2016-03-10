void Print_values() {
 
//--- SENSOR HUMIDADE tronco
  lcd.clear();                           //Situamos o cursor no caracter 0, linha 0
  Serial.print(F("HUMIDADE MADEIRA (%):"));
  lcd.print(F("HUMD. MADEIRA:"));
  lcd.setCursor(0, 1);
  Serial.print(HM_value);
  lcd.print(HM_value);
   lcd.print(F("   (%)"));
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  delay(3500);
   
//---SENSOR TEMPERATURA Tronco
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  Serial.print(F("TEMPERATURA MADEIRA (C.):"));
  lcd.print(F("TEMP. MADEIRA:"));
  lcd.setCursor(0, 1);
  Serial.print(TPA_value);
  lcd.print(TPA_value);
  lcd.print(F("   (C.)"));
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  delay(3500);
  
  //---SENSOR TEMPERATURA ambiente
  lcd.clear();   
  Serial.print(F("TEMP. AMBIENTE (C):"));
  lcd.print(F("TEMP. AMBIENTE:"));
  lcd.setCursor(0, 1);
  Serial.print(temp);
  lcd.print(temp);
  lcd.print(F("  (C.)"));
  Serial.print(F("\n"));
  Serial.print(F("  \n"));
  delay(3500);

    
    
  }
