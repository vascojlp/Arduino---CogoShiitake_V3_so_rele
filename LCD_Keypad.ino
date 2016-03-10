void Keypad() 
{
  
 
adc_key_in =0;
adc_key_in = analogRead(ManualPin);    // read the value from the sensor 
Serial.print(adc_key_in);
Serial.print(F("\n"));
Serial.print(F("  \n"));

 if (adc_key_in < 1020){
   lcd.clear(); 
   lcd.print(F("REGA..."));
   lcd.setCursor(0, 1);
   lcd.print(F("MODO MANUAL!"));
   digitalWrite(RL1WSRpowerPin, LOW); 
   delay(180000);                        //5 minutos
   digitalWrite(RL1WSRpowerPin, HIGH); 
 }
 
 }
