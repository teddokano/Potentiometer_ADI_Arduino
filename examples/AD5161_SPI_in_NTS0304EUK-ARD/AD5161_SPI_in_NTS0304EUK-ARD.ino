#include "AD5161.h"
#include "BusInOut.h"

AD5161_SPI dp;

BusInOut setting(5, A3, A2);
BusInOut ldo1(0, 1, 4);
BusInOut ldo2(2, 3);

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Hello, AD5161");
  Serial.println("\"D0\" and \"D1\" pins are disabled with \"Serial\" feature because those pins are shared");

  setting.config(OUTPUT);
  ldo1.config(OUTPUT);
  ldo2.config(OUTPUT);
  setting = 0b001;
  ldo1 = 3;
  ldo2 = 2;

  SPI.begin();
}

void loop() {
  uint8_t read_value;

  for (int i = 0; i < 256; i++) {
    dp = i;
    read_value = dp;
    Serial.println(read_value);
    delay(10);
  }
}
