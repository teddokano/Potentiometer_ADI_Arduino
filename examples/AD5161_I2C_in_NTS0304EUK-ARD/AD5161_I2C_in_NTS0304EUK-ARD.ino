#include "AD5161.h"
#include "BusInOut.h"

AD5161_I2C dp;

BusInOut setting(5, A3, A2);
BusInOut ldo1(0, 1, 4);
BusInOut ldo2(2, 3);

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Hello, AD5161");

  setting.config(OUTPUT);
  ldo1.config(OUTPUT);
  ldo2.config(OUTPUT);
  setting = 0b100;
  ldo1 = 3;
  ldo2 = 2;

  Wire.begin();
}

void loop() {
  uint8_t read_value;

  for (int i = 0; i < 256; i++) {
    dp = i;
    //read_value = dp;
    Serial.println(i);
    delay(10);
  }
}
