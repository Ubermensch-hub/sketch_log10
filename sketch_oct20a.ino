#include <GyverOLED.h>
#include <math.h>
#include <stdio.h>

GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

void setup() {
  oled.init();        // инициализация
  oled.clear();       // очистка
  oled.setScale(3);   // масштаб текста (1..4)
  oled.home();        // курсор в 0,0
}

void loop() 
{
    for (int i=0; i!=10; ++i)
    {
      oled.print("lg = ");
      oled.setCursor(0, 4);
      oled.print(log10(i));
      delay(1500);
      oled.clear();
      oled.home();
    }

    for (int i=10; i != 0; --i)
    {
      oled.print("lg = ");
      oled.setCursor(0, 4);
      oled.print(log10(i));
      delay(1500);
      oled.clear();
      oled.home();
    }
}