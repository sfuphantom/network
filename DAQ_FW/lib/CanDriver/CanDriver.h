#ifndef CAN_LIB
#define CAN_LIB
#include "driver/gpio.h"
#include "driver/can.h"
#include "system_config.h"

namespace CanDriver
{
    void CanInnit();

    void sendCanData(const char *canData, const uint32_t canLen, const uint16_t canID);

    void readCanData();
}

#endif