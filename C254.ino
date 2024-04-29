#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT , &Wire , -1);

int mouth_radius = 5;
int change = 1;

void setup()   
{
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("Failed"); 
    while(1);
  }

  display.clearDisplay();
}

void loop() 
{

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(2, SCREEN_HEIGHT / 2);
  display.println("WOW");

  display.drawCircle((SCREEN_WIDTH / 2) + 10 , SCREEN_HEIGHT / 2 , 30 , WHITE);

  display.drawCircle(65 , 17 , 5 , WHITE);
  
  display.drawCircle(83 , 17 , 5 , WHITE);
  
  display.drawCircle(74 , 45 , mouth_radius , WHITE);

  display.display();
  delay(50);

  if (mouth_radius  ==  15)
  {
    change = -1;
    delay(500);
  }

  else if (mouth_radius  ==  5)
  {
    change = 1;
    delay(500);
  }

  mouth_radius = mouth_radius + change;
  
}
