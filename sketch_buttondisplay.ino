#define GIO_USE_ARDUINO     // отключить быстрые функции (заменить на стандартные)
#define GIO_NO_MASK         // отключить быстрый IO на основе маски для AVR (в классе PinIO и всех shift)

#define EB_DEB_TIME 1    // таймаут гашения дребезга кнопки 
#define EB_CLICK_TIME 10   // таймаут ожидания кликов 
#define EB_HOLD_TIME 600    // таймаут удержания 

#include <GyverOLED.h>
#include <GyverIO_SPI.h>
#include <EncButton.h>
#include <stdio.h>


GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

Button btnt(2); //кнопка на пине D2

int buff=0;

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
}

void setup() 
{
  oled.init();        // инициализация
  oled.setScale(3);   // масштаб текста (1..4)
  clear_screen();
  Wire.setClock(700000L); //разгоняю дисплейчик
}

void loop() 
{
  clear_screen();
  set_text(buff);
  btnt.tick(); //считывание
  if (btnt.click()) buff++;
  if (btnt.hold()) buff=0;
}