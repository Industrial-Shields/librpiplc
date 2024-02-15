#ifndef __PERIPHERAL_ADS1015_H__
#define __PERIPHERAL_ADS1015_H__

#include <stdint.h>

#include "i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

	int ads1015_init(i2c_t* i2c, uint8_t addr);
	uint16_t ads1015_read(i2c_t* i2c, uint8_t addr, uint8_t index);

#ifdef __cplusplus
}
#endif

#endif
