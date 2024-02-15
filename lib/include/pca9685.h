#ifndef __PERIPHERAL_PCA9685_H__
#define __PERIPHERAL_PCA9685_H__

#include <stdint.h>
#include "i2c.h"

#define PCA9685_NUM_OUTPUTS 16

#ifdef __cplusplus
extern "C" {
#endif

	int pca9685_init(i2c_t* i2c, uint8_t addr);
	int pca9685_set_out_on(i2c_t* i2c, uint8_t addr, uint8_t index);
	int pca9685_set_out_off(i2c_t* i2c, uint8_t addr, uint8_t index);
	int pca9685_set_out_pwm(i2c_t* i2c, uint8_t addr, uint8_t index, uint16_t value);

	int pca9685_set_all_digital(i2c_t* i2c, uint8_t addr, uint16_t values);
	int pca9685_set_all_analog(i2c_t* i2c, uint8_t addr, const uint16_t* values);

#ifdef __cplusplus
}
#endif

#endif
