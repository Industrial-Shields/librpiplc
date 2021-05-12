#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "rpi-gpio.h"

#define MAX_RPI_GPIOS 64

struct rpi_gpio {
	int fd;
	uint32_t pin;
};

static struct rpi_gpio rpi_gpios[MAX_RPI_GPIOS];

static int rpi_gpio_fd = -1;

////////////////////////////////////////////////////////////////////////////////////////////////////
static struct rpi_gpio* find_gpio_by_pin(uint32_t pin) {
	struct rpi_gpio* gpio = rpi_gpios;
	for (int i = 0; i < MAX_RPI_GPIOS; ++i) {
		if (gpio->pin == pin) {
			return gpio;
		}
		++gpio;
	}
	return nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static struct rpi_gpio* find_empty_gpio() {
	struct rpi_gpio* gpio = rpi_gpios;
	for (int i = 0; i < MAX_RPI_GPIOS; ++i) {
		if (gpio->fd < 0) {
			return gpio;
		}
		++gpio;
	}
	return nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rpi_gpio_init() {
	struct rpi_gpio* gpio = rpi_gpios;
	for (int i = 0; i < MAX_RPI_GPIOS; ++i) {
		gpio->fd = -1;
		++gpio;
	}

	rpi_gpio_fd = open("/dev/gpiochip0", O_RDONLY);
	if (rpi_gpio_fd < 0) {
		perror("gpio_init");
		return 0;
	}

	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rpi_gpio_deinit() {
	close(rpi_gpio_fd);

	struct rpi_gpio* gpio = rpi_gpios;
	for (int i = 0; i < MAX_RPI_GPIOS; ++i) {
		if (gpio->fd > 0) {
			close(gpio->fd);
			gpio->fd = -1;
		}
		++gpio;
	}

	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rpi_gpio_set_pin_mode(uint32_t pin, uint32_t mode) {
	struct gpiohandle_request req;

	struct rpi_gpio* gpio = find_gpio_by_pin(pin);
	if (gpio != nullptr) {
		close(gpio->fd);
		gpio->fd = -1;
	}

	gpio = find_empty_gpio();
	if (gpio == nullptr) {
		return 0;
	}

	req.lineoffsets[0] = pin;
	req.lines = 1;
	req.flags = mode;

	if (ioctl(rpi_gpio_fd, GPIO_GET_LINEHANDLE_IOCTL, &req) < 0) {
		perror("rpi_gpioet_pin_mode");
		return 0;
	}

	gpio->fd = req.fd;
	gpio->pin = pin;

	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rpi_gpio_read(uint32_t pin) {
	struct gpiohandle_data data;

	struct rpi_gpio* gpio = find_gpio_by_pin(pin);
	if (gpio == nullptr) {
		return 0;
	}

	if (ioctl(gpio->fd, GPIOHANDLE_GET_LINE_VALUES_IOCTL, &data) < 0) {
		perror("gpio_write");
		return 0;
	}

	return data.values[0];
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rpi_gpio_write(uint32_t pin, uint8_t value) {
	struct gpiohandle_data data;

	struct rpi_gpio* gpio = find_gpio_by_pin(pin);
	if (gpio == nullptr) {
		return 0;
	}

	data.values[0] = value ? 1 : 0;
	if (ioctl(gpio->fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data) < 0) {
		perror("gpio_write");
		return 0;
	}

	return 1;
}
