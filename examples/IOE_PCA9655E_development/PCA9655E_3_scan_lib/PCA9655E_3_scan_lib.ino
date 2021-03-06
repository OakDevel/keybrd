/* PCA9655E_3_scan_lib.ino
does same as PCA9655E_2_scan.ino, but using keybrd library classes
pictures in PCA9655E_2_scan/

set port 1 pins
read and print value of port 0
measure port 1 pin voltages with a multimeter

DESTINATION  PIN PIN_NUMBER  PIN   DESTINATION
       x     INT  1      24  VDD   Teensy LC 3.3V
      SCL    AD1  2      23  SDA   Teensy LC 18
      GND    AD2  3      22  SCL   Teensy LC 19
      GND  IO0_0  4      21  AD0   SCL
      GND  IO0_1  5      20  IO1_6  x
     IO1_1 IO0_2  6      19  IO1_5  x
      GND  IO0_3  7      18  IO1_4  x
      GND  IO0_4  8      17  IO1_4  x
      GND  IO0_5  9      16  IO1_3  x
       x   IO0_6 10      15  IO1_2  x
       x   IO0_7 11      14  IO1_1 IO0_2 strobe pin
      GND    VSS 12      13  IO1_0  x
*/
#include <Port_PCA9655E.h>
#include <Scanner_IOE.h>

const uint8_t ADDR  = 0x18;                     //I2C address with AD2=GND AD1=SCL AD0=SCL

Port_PCA9655E port0(ADDR, 0, ~0);               //read all pins
Port_PCA9655E port1(ADDR, 1, 0);                //for strobe

Scanner_IOE scanner_R(HIGH, port1, port0);

void setup()
{
    delay(6000);
    Keyboard.print("PCA9655E_3_scan.ino");

    scanner_R.begin();

    Keyboard.print("  port0_val= ");
    uint8_t port0_val = scanner_R.scan(1<<1);   //strobe pin 1
    Keyboard.print(port0_val, BIN);             //expect xx000100
}

void loop() { }
