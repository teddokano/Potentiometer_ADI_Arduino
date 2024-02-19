/** PCA9617ADP-ARD demo sample
 *
 *  Simple sample to operate two LDOs to try signal voltage convination
 *  All possible convination is demonstrated with 0.8V, 1.8V, 2.5V, 3.3V, 4.96V at LDO1 and 
 *  2.5V, 3.0V, 3.3V, 4.96V at LDO2 except condition of "LDO1=4.96 and LDO2=2.5V". 
 *  
 *  To perform sample I2C transfer, it uses M24C02 class library which is defined in "MUX_SW_NXP_Arduino" library. 
 *
 *  @author  Tedd OKANO
 *
 *  Released under the MIT license License
 *
 *  About PCA9617A:
 *    https://www.nxp.com/products/interfaces/ic-spi-i3c-interface-devices/ic-bus-repeaters-hubs-extenders/level-translating-fm-plus-ic-bus-repeater:PCA9617A
 */

#include "AD5161.h"
#include "BusInOut.h"

//#define I2C_SETTING
#define SERIAL_OUT_DISABLE

#ifdef I2C_SETTING
AD5161_I2C dp;
#else
AD5161_SPI dp;
#endif // I2C_SETTING

BusInOut setting(5, A3, A2);
BusInOut ldo1(0, 1, 4);
BusInOut ldo2(2, 3);

void setup() {
#ifndef SERIAL_OUT_DISABLE
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Hello, BusInOUt");
  Serial.println( "\"D0\" and \"D1\" pins are disabled with \"Serial\" feature because those pins are shared");
#endif

  setting.config(OUTPUT);
  ldo1.config(OUTPUT);
  ldo2.config(OUTPUT);

#ifdef I2C_SETTING
  setting = 0b100;
  Wire.begin();
#else
  setting = 0b001;
  SPI.begin();
#endif // I2C_SETTING

  ldo1 = 3;
  ldo2 = 2;
}

void loop() {
  for (int i = 0; i < 256; i++) {
    dp.value(i);
    Serial.println(i);
    delay(10);
  }
}
