#include "U8glib.h"
#include <StopWatch.h>

int analogPin0 = 0;
int analogPin1 = 1;
int val0 = 600;
int val1 = 0;
int val2 = 0;

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0); // I2C / TWI
StopWatch MySW;

void draw(void) {
  u8g.setFont(u8g_font_unifont);
  u8g.setScale2x2();
  u8g.setPrintPos(0, 20); 
  u8g.print(MySW.value());
  u8g.print(" MS");
}

void setup()
{
}

void loop()
{
  val0 = analogRead(analogPin0);
  val1 = analogRead(analogPin1);
  
  if (val0 < 300) {
    MySW.start();
    }

    if (val1 > 100) {
      elapsed();  
    }
}
void elapsed() 
{
   MySW.stop();
   u8g.firstPage();  
   do {
   draw();
   } 
   while( u8g.nextPage() );
   draw();
   delay (1000000);
   MySW.reset();
  }




