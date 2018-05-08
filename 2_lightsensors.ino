
#include <Servo.h>

#define servoPin  9   
int servoval = 90;
Servo myservo;



void setup()
{
  //int servoval = 90;

  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  myservo.attach(servoPin);

}
void loop()
{
      int val1;
      int val2;

      
      //float x = val1-val2;

      val1=analogRead(A0);   //connect grayscale sensor to Analog 0
      val2=analogRead(A1);   //connect grayscale sensor to Analog 0

      int lightval = val1 - val2;
      if (lightval > 20) {
        if (servoval < 180 && servoval > 0) {
          servoval+=2;
        } else if (servoval = 180){
          servoval = 178;
        }
} else if (lightval < -20) {
        if (servoval < 180 && servoval > 0) {
          servoval-=2;
        } }
        myservo.write(servoval);

      
      



      Serial.print(val1);//print the value to serial        
      Serial.print("&&");//print the value to serial        
      Serial.print(val2);//print the value to serial        
      Serial.print("==");//print the value to serial        
      Serial.print(lightval);//print the value to serial    
      Serial.print("  ");//print the value to serial        
      Serial.println(servoval);//print the value to serial    
      delay(500);
}
