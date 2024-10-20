#include <GyverOLED.h>
#include <math.h>
#include <stdio.h>

GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

void clear_screen()
{
  oled.clear();       // очистка
  oled.home();        // курсор в 0,0
}

void set_text(int arg)
{
      oled.print("res = ");
      oled.setCursor(0, 4);
      oled.print(arg);
      delay(1500);
}

void setup() 
{
  oled.init();        // инициализация
  oled.setScale(3);   // масштаб текста (1..4)
  clear_screen();
}

void loop() 
{
    for (int i=0; i!=10; ++i)
    {
      set_text(log10(i));
      clear_screen();
    }

    for (int i=10; i != 0; --i)
    {
      set_text(log10(i));
      clear_screen();
    }
}