#ifndef __RPI_GPIO_H__
#define __RPI_GPIO_H__

#include <stdint.h>
#include <linux/gpio.h>

#define RPI_GPIO_OUTPUT GPIOHANDLE_REQUEST_OUTPUT
#define RPI_GPIO_INPUT GPIOHANDLE_REQUEST_INPUT

#ifdef __cplusplus
extern "C" {
#endif

	uint8_t rpi_gpio_init();
	uint8_t rpi_gpio_deinit();
	uint8_t rpi_gpio_set_pin_mode(uint32_t pin, uint32_t mode);
	uint8_t rpi_gpio_read(uint32_t pin);
	uint8_t rpi_gpio_write(uint32_t pin, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif
