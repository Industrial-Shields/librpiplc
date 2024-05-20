/*
 * Copyright (c) 2024 Industrial Shields. All rights reserved
 *
 * This file is part of librpiplc.
 *
 * librpiplc is free software: you can redistribute
 * it and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either version
 * 3 of the License, or (at your option) any later version.
 *
 * librpiplc is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "rpiplc-peripherals.h"
#include "rpi-gpio.h"

#include <stdint.h>
#include <stddef.h>
#include <time.h>
#include <errno.h>


// All I2C devices are connected at /dev/i2c-1
const int I2C_BUS = 1;

const uint8_t NORMAL_GPIO_INPUT = 0;
const uint8_t NORMAL_GPIO_OUTPUT = 1;

const uint8_t ARRAY_MCP23008[] = {
	0x20, 0x21
};
const size_t NUM_ARRAY_MCP23008 = sizeof(ARRAY_MCP23008) / sizeof(uint8_t);

const uint8_t ARRAY_ADS1015[] = {
#ifdef RPIPLC_V3
	0x48, 0x49, 0x4a, 0x4b,
#endif
};
const size_t NUM_ARRAY_ADS1015 = sizeof(ARRAY_ADS1015) / sizeof(uint8_t);

const uint8_t ARRAY_PCA9685[]  = {
	0x40, 0x41,
};
const size_t NUM_ARRAY_PCA9685 = sizeof(ARRAY_PCA9685) / sizeof(uint8_t);

const uint8_t ARRAY_LTC2309[] = {
	0x08, 0x0a, 0x28
};
const size_t NUM_ARRAY_LTC2309 = sizeof(ARRAY_LTC2309) / sizeof(uint8_t);

const uint8_t ARRAY_MCP23017[] = {};
const size_t NUM_ARRAY_MCP23017 = sizeof(ARRAY_MCP23017) / sizeof(uint8_t);

int normal_gpio_init(void) {
	return rpi_gpio_init();
}

int normal_gpio_deinit(void) {
	return rpi_gpio_deinit();
}

int normal_gpio_set_pin_mode(uint32_t pin, uint8_t mode) {
	return rpi_gpio_set_pin_mode(pin, mode);
}

int normal_gpio_write(uint32_t pin, uint8_t value) {
	return rpi_gpio_write(pin, value);
}

int normal_gpio_pwm_frequency(uint32_t pin, uint32_t freq) {
	errno = ENOTSUP;
	return -1;
}

int normal_gpio_pwm_write(uint32_t pin, uint16_t value) {
	errno = ENOTSUP;
	return -1;
}

int normal_gpio_read(uint32_t pin, uint8_t* read) {
	return rpi_gpio_read(pin, read);
}

int normal_gpio_analog_read(uint32_t pin, uint16_t* read) {
	errno = ENOTSUP;
	return -1;
}

void delay(uint32_t milliseconds) {
    struct timespec req = {
        .tv_sec = milliseconds / 1000,
        .tv_nsec = (milliseconds % 1000) * 1000000
    };
    nanosleep(&req, NULL);
}

void delayMicroseconds(uint32_t micros) {
    struct timespec req = {
        .tv_sec = micros / 1000000,
        .tv_nsec = (micros % 1000000) * 1000
    };
    nanosleep(&req, NULL);
}
