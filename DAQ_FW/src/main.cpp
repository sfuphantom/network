#include "IADCSensor.h"
#include "CanDriver.h"
#include "driver/gpio.h"
#include "driver/can.h" // required to resolve #define conflicts

void setup()
{

  Logger::Start();

  CanDriver::CanInnit();

  // setup_can_driver();
}

void loop()
{
  const char *canMsg = "Test";

  // send string "Test" with ID 0xAAA
  CanDriver::sendCanData(canMsg, strlen(canMsg), 0xAAA);

  // Will recieve it's own message through the hardware layer
  // Tested to work with another ESP32
  CanDriver::readCanData();

  delay(1000);
}