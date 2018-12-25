#include <APA102.h>

// Define which pins to use.
const uint8_t dataPin = 4;
const uint8_t clockPin = 0;
const uint8_t BRIGHTNESS_PIN = 3;  // button between this pin and ground
int mode = 0;
int r = 0;
int g = 0;
int b = 0;

// Create an object for writing to the LED strip.
APA102<dataPin, clockPin> ledStrip;

// Set the number of LEDs to control.
const uint16_t ledCount = 5;

// Create a buffer for holding the colors (3 bytes per color).
rgb_color colors[ledCount];

// Set the brightness to use (the maximum is 31).
uint8_t brightness = 1;

void setup()
{
}

void loop()
{
    //check button and change brightness if need be  
    if (digitalRead(BRIGHTNESS_PIN) == 0)
    {
      mode++;
      mode = mode%3;
      delay(10); //debounce delay
    }
    if (mode == 0)
    {
      r = 255;
      g = 0;
      b = 0;
    }
    else if (mode == 1)
    {
      r = 0;
      g = 255;
      b = 0;
    }
    else if (mode == 2)
    {
      r = 0;
      g = 0;
      b = 255;
    }
    

  uint8_t time = millis() >> 2;
  for(uint16_t i = 0; i < ledCount; i++)
  {
    uint8_t x = time - i * 8;
    colors[i].red = r;
    colors[i].green = g;
    colors[i].blue = b;
  }
  ledStrip.write(colors, ledCount, brightness);
}
