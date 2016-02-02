/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int incomingByte = 0; 
int tempPin = 1;
float temperatura = 0;
char response[10];
int tempByte= -1;
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  Serial.begin(115200);
}
 
void loop()
{
  while(Serial.available()){
    incomingByte=Serial.read();
  }

  //         ----------------


  Serial.println(incomingByte);
  if(incomingByte==48){
      setColor(0,0,0);
      tempByte=0;
  }else if(incomingByte==49){
    setColor(255, 0, 0);  // red
    tempByte=1;
  }else if(incomingByte==50){
    setColor(0, 255, 255);  // aqua
    tempByte=2;
  }else if(incomingByte==51){
      //Calcula la temperatura usando como referencia 5v
    temperatura = (5.0 * analogRead(tempPin)*100.0)/1023.0;
    delay(500);
    Serial.println (temperatura); //escribe la temperatura en el serial
    Serial.println();
    delay(500);
    /**/
  }else if (incomingByte==52){
    Serial.print(temperatura);
    Serial.print(",");
    Serial.print(tempByte);
    Serial.println();
    delay(1000);
  }
  
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
