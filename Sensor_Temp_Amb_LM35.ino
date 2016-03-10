void Temperatura_ambiente() {
   
   temp1 = analogRead(tempPin);
   temp2= analogRead(tempPin);
   temp3= analogRead(tempPin);
   temp4= analogRead(tempPin);
   temp5= analogRead(tempPin);
   temp6= analogRead(tempPin);
   temp7= analogRead(tempPin);
   temp8= analogRead(tempPin);
   temp9= analogRead(tempPin);
   temp10= analogRead(tempPin);
   temp=(temp1+temp2+temp3+temp4+temp5+temp6+temp7+temp8+temp9+temp10)/10;
   
   //temp = temp * 0.48828125;  0.571
   temp = temp * 0.515;
 }
