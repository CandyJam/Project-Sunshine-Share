
#include <Servo.h>
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define servoPin  9  
#define setFont_L u8g_font_timB14
#define setFont_M u8g_font_9x15
#define setFont_S u8g_font_fixed_v0r

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);


/*
  font:
  u8g_font_timB18
  u8g_font_timB14
  u8g_font_timB10
  u8g_font_5x7
  u8g_font_6x10
  u8g_font_7x13
  u8g_font_9x15
  u8g_font_unifont
  u8g_font_fixed_v0r
  u8g_font_chikitar
  number:
  u8g_font_freedoomr25n
*/
 
int servoval = 90;
Servo myservo;


/*void draw(void) {
  // graphic commands to redraw the complete screen should be placed here
  u8g.setFont(setFont_L);
  u8g.setPrintPos(0, 30);
  u8g.print(servoval);
/*
  u8g.setFont(setFont_M);
  u8g.setPrintPos(0, 50);
  u8g.print("Font_M:0123");

  u8g.setFont(setFont_S);
  u8g.setPrintPos(0, 60);
  u8g.print("Font_S:0123");
  */



void setup()
{
  //int servoval = 90;

  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  myservo.attach(servoPin);

  u8g2.begin();
  u8g2.enableUTF8Print();

}


void loop()
{
      int val1;
      int val2;

      
      //float x = val1-val2;

      val1=analogRead(A0);   //connect grayscale sensor to Analog 0
      val2=analogRead(A1);   //connect grayscale sensor to Analog 0

      int lightval = val1 - val2 + 30 ;
      if (lightval < -20) {
        if (servoval < 180 && servoval > 0) {
          servoval+=2;
        } else if (servoval = 180){
          servoval = 178;
        }
} else if (lightval > 20) {
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
      
      u8g2.setFont(u8g2_font_freedoomr25_tn);  // use chinese2 for all the glyphs of "你好世界"
      u8g2.setFontDirection(0);
      u8g2.clearBuffer();
      u8g2.setFontPosCenter();
      u8g2.setCursor(0, 40);
      u8g2.print(servoval);
      u8g2.setCursor(70, 47);
      u8g2.setFont(u8g2_font_7x13_me);
      u8g2.print("@TOKYO");   // Chinese "Hello World" 
      u8g2.sendBuffer();
      delay(500);
}
