#ifndef __RPI_GPIO_H__
#define __RPI_GPIO_H__

#include <stdint.h>
#include <linux/gpio.h>

#define RPI_GPIO_OUTPUT 1
#define RPI_GPIO_INPUT 0

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief Initializes the Raspberry Pi GPIO interface.
	 *
	 * This function initializes the GPIO interface by opening the GPIO character device.
	 *
	 * @return 0 if successful, -1 if there was an error. Errnos set by this function
	 *         are those set by the "open" system call.
	 */
        int rpi_gpio_init(void);

	/**
	 * @brief De-initializes the Raspberry Pi GPIO interface.
	 *
	 * This function de-initializes the GPIO interface by closing the GPIO character device.
	 *
	 * @return 0 if successful, -1 if there was an error. Errnos set by this function
	 *         are those set by the "close" system call.
	 */
        int rpi_gpio_deinit(void);

	/**
	 * @brief Sets the pin mode for a specified pin on the Raspberry Pi GPIO interface.
	 *
	 * @param pin The pin number.
	 * @param mode The mode to set (RPI_GPIO_INPUT or RPI_GPIO_OUTPUT).
	 * @return 0 if successful, otherwise a negative value indicating the error.
	 *         Errnos returned by this function are those set by the "close" and "ioctl" system calls.
	 */
	int rpi_gpio_set_pin_mode(uint32_t pin, uint8_t mode);

	/**
	 * @brief Reads the digital value from the specified pin on the Raspberry Pi GPIO interface.
	 *
	 * @param pin The pin number.
	 * @param value Pointer to where the read value will be stored (0 or 1).
	 * @return 0 if successful, otherwise a negative value indicating the error.
	 *         Errnos returned by this function are those set by the "ioctl" system call.
	 */
	int rpi_gpio_read(uint32_t pin, uint8_t* value);

	/**
	 * @brief Writes a digital value to the specified pin on the Raspberry Pi GPIO interface.
	 *
	 * @param pin The pin number.
	 * @param value The digital value to write (0 or 1).
	 * @return 0 if successful, otherwise a negative value indicating the error.
	 *         Errnos returned by this function are those set by the "ioctl" system call.
	 */
	int rpi_gpio_write(uint32_t pin, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif
