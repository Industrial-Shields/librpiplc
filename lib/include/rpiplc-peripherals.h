#ifndef __RPIPLC_PERIPHERALS__
#define __RPIPLC_PERIPHERALS__

#include <stdint.h>

#include "ads1015.h"
#include "mcp23008.h"
#include "pca9685.h"
#include "ltc2309.h"

#define I2C_BUS	1

#define pinToDeviceAddress(pin) (((pin) >> 8) & 0xff)
#define pinToDeviceIndex(pin) ((pin) & 0xff)

extern const uint8_t rpiplc_mcp23008[];
extern const int rpiplc_num_mcp23008;
extern const uint8_t rpiplc_ads1015[];
extern const int rpiplc_num_ads1015;
extern const uint8_t rpiplc_pca9685[];
extern const int rpiplc_num_pca9685;
extern const uint8_t rpiplc_ltc2309[];
extern const int rpiplc_num_ltc2309;

#endif
