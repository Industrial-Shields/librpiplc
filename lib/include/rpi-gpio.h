#ifndef __RPI_GPIO_H__
#define __RPI_GPIO_H__

#include <stdint.h>
#include <linux/gpio.h>

#define RPI_GPIO_OUTPUT 1
#define RPI_GPIO_INPUT 0

#ifdef __cplusplus
extern "C" {
#endif

        int rpi_gpio_init(void);
        int rpi_gpio_deinit(void);
	int rpi_gpio_set_pin_mode(uint32_t pin, uint8_t mode);
	int rpi_gpio_read(uint32_t pin, uint8_t* value);
	int rpi_gpio_write(uint32_t pin, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif
