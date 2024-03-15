#include "rpiplc-peripherals.h"
#include "rpi-gpio.h"

#include <stdint.h>
#include <stddef.h>
#include <time.h>
#include <errno.h>

const uint8_t I2C_BUS = 1;

const uint8_t NORMAL_GPIO_INPUT = 0;
const uint8_t NORMAL_GPIO_OUTPUT = 1;

const uint8_t MCP23008[] = {
	0x20, 0x21
};
const size_t NUM_MCP23008 = sizeof(MCP23008) / sizeof(uint8_t);

const uint8_t ADS1015[] = {
	0x48, 0x49, 0x4a, 0x4b,
};
const size_t NUM_ADS1015 = sizeof(ADS1015) / sizeof(uint8_t);

const uint8_t PCA9685[]  = {
	0x40, 0x41,
};
const size_t NUM_PCA9685 = sizeof(PCA9685) / sizeof(uint8_t);

const uint8_t LTC2309[] = {
	0x08, 0x0a, 0x28
};
const size_t NUM_LTC2309 = sizeof(LTC2309) / sizeof(uint8_t);

const uint8_t MCP23017[] = {};
const size_t NUM_MCP23017 = sizeof(MCP23017) / sizeof(uint8_t);

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
