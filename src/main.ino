#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define BTN 5

void setup()
{
  Serial.begin(115200);
  Serial.println("Pushbutton Counter");
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop()
{
  static int count = 0;
  static int lastState = HIGH;
  int state = digitalRead(PIN_BUTTON);
  if (state != lastState)
  {
    if (state == LOW)
    {
      count++;
      Serial.print("Button pressed ");
      Serial.print(count);
      Serial.println(" times");
    }
    lastState = state;
  }
  vTaskDelay(10 / portTICK_PERIOD_MS);
}
