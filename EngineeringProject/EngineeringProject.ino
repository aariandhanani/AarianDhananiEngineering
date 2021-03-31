#include <MD_MAX72xx.h>
#include <SPI.h>

#define SPEED_FROM_ANALOG 0   // optional to use analog input for speed control

#define PRINT(s, v)   // Print a string followed by a value (decimal)
#define PRINTX(s, v)  // Print a string followed by a value (hex)
#define PRINTS(s)     // Print a string

// --------------------
// MD_MAX72xx hardware definitions and object
// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
//
#define HARDWARE_TYPE MD_MAX72XX::DR1CR0RR0_HW
#define MAX_DEVICES 4
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    3  // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);                      // SPI hardware interface
//MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Arbitrary pins


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
