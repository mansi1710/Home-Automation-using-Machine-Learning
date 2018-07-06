int sensorPin1 = A0,sensorPin2 = A1,sensorPin3 = A2,sensorPin4 = A3,sensorPin5 = A4,sensorPin6 = A5; // select the input pin for LDR
int sensorValue1 = 0,sensorValue2 = 0,sensorValue3 = 0,sensorValue4 = 0,sensorValue5 = 0,sensorValue6 = 0; // variable to store the value coming from the sensor

void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
Serial.begin(9600); // the bigger number the better
  
Serial.println("CLEARDATA"); //clears up any data left from previous projects

Serial.println("LABEL,Acolumn,Bcolumn,Ccolumn,Dcolumn,Ecolumn,Fcolumn"); //always write LABEL, so excel knows the next things will be the names of the columns (instead of Acolumn you could write Time for instance)

Serial.println("RESETTIMER"); //resets timer to 0

}

void loop() {
 
for(int i=0;i<32;i++)
{
  int a[5]={0},j=i,k=0;
  while(j)
  {
    a[k]=j%2;
    j/=2;
    if(a[k]==1)
    digitalWrite((k+2),HIGH);
    else
    digitalWrite((k+2), LOW);
    k++;
  }
 
 Serial.print("DATA,TIME,"); //writes the time in the first column A and the time since the measurements started in column B
 Serial.print(digitalRead(2));
 Serial.print(",");
 Serial.print(digitalRead(3));
 Serial.print(",");
 Serial.print(digitalRead(4));
Serial.print(",");
 Serial.print(digitalRead(5));
 Serial.print(",");
 Serial.print(digitalRead(6));
 Serial.print(",");
 sensorValue1 = analogRead(sensorPin1); // read the value from the sensor
 sensorValue2 = analogRead(sensorPin2);
 sensorValue3 = analogRead(sensorPin3);
 sensorValue4 = analogRead(sensorPin4);
 sensorValue5 = analogRead(sensorPin5);
 sensorValue6 = analogRead(sensorPin6);
 Serial.print(sensorValue1); //prints the values coming from the sensor on the screen
 Serial.print(",");
 Serial.print(sensorValue2);
 Serial.print(",");
 Serial.print(sensorValue3);
 Serial.print(",");
 Serial.print(sensorValue4);
 Serial.print(",");
 Serial.print(sensorValue5);
 Serial.print(",");
 Serial.print(sensorValue6);
Serial.println(); //be sure to add println to the last command so it knows to go into the next row on the second run
delay(3000); //add a delay
}
}
