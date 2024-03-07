#include "rpiplc-peripherals.h"
#include "rpi-gpio.h"

#include <stdint.h>
#include <stddef.h>

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
	*read = rpi_gpio_read(pin);
        return 0;
}

void delay(uint32_t milliseconds) {
	struct timeval tv = {
		.tv_sec = (long) (milliseconds / 1000),
		.tv_usec = (long) (milliseconds % 1000) * 1000L,
	};
	select(0, NULL, NULL, NULL, &tv);
}

void delayMicroseconds(uint32_t micros) {
	struct timeval tv = {
		.tv_sec = (long) (micros / 1000000),
		.tv_usec = (long) (micros % 1000000),
	};
	select(0, NULL, NULL, NULL, &tv);
}
