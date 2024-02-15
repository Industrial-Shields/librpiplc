#ifndef __PERIPHERAL_LTC2309_H__
#define __PERIPHERAL_LTC2309_H__

#include <stdint.h>
#include "i2c.h"

#define LTC2309_INPUT 0

#ifdef __cplusplus
extern "C" {
#endif

	int ltc2309_init(i2c_t* i2c, uint8_t addr);
	uint16_t ltc2309_read(i2c_t* i2c, uint8_t addr, uint8_t index);

#ifdef __cplusplus
}
#endif

#endif
