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

#include "rpi-gpio.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_RPI_GPIOS 64

static int rpi_gpios_fds[MAX_RPI_GPIOS];

static int gpiochip_fd = -1;

int rpi_gpio_init(void) {
	if (gpiochip_fd >= 0) {
		return 1;
	}

	gpiochip_fd = open("/dev/gpiochip0", O_RDONLY);
	if (gpiochip_fd < 0) {
		return gpiochip_fd;
	}

        int* gpio_fd = rpi_gpios_fds;
	for (uint32_t c = 0; c < MAX_RPI_GPIOS; c++) {
		*gpio_fd = -1;
		++gpio_fd;
	}

	return 0;
}

int rpi_gpio_deinit(void) {
	if (gpiochip_fd < 0) {
		return 1;
	}

	int ret = close(gpiochip_fd);
	if (ret != 0) {
		return ret;
	}
	gpiochip_fd = -1;

        int* gpio_fd = rpi_gpios_fds;
	for (size_t c = 0; c < MAX_RPI_GPIOS; c++) {
		if (*gpio_fd >= 0) {
			close(*gpio_fd);
			*gpio_fd = -1;
		}
		++gpio_fd;
	}

	return 0;
}

int rpi_gpio_set_pin_mode(uint32_t pin, uint8_t mode) {
        int* gpio_fd = &rpi_gpios_fds[pin];
        if (*gpio_fd >= 0) {
	        close(*gpio_fd);
	        *gpio_fd = -1;
        }

	switch (mode) {
	case RPI_GPIO_INPUT:
		mode = GPIO_V2_LINE_FLAG_INPUT;
		break;
	case RPI_GPIO_OUTPUT:
		mode = GPIO_V2_LINE_FLAG_OUTPUT;
		break;
	default:
		errno = EINVAL;
		return -1;
	}

        struct gpio_v2_line_request req;
        memset(&req, 0, sizeof(req));

        req.config.num_attrs = 0;
        req.offsets[0] = pin;
        req.num_lines = 1;
        req.config.flags = mode;

        int ret = ioctl(gpiochip_fd, GPIO_V2_GET_LINE_IOCTL, &req);
        if (ret != 0) {
	        return ret;
        }

        *gpio_fd = req.fd;
        return 0;
}

int rpi_gpio_read(uint32_t pin, uint8_t* value) {
        const int* gpio_fd = &rpi_gpios_fds[pin];
	if (*gpio_fd < 0) {
		int ret = rpi_gpio_set_pin_mode(pin, RPI_GPIO_INPUT);
		if (ret != 0) {
			return ret;
		}
	}

	struct gpio_v2_line_values values;
	memset(&values, 0, sizeof(values));
	values.mask = 0b1;

	int ret = ioctl(*gpio_fd, GPIO_V2_LINE_GET_VALUES_IOCTL, &values);
	if (ret == -1) {
		return ret;
	}

	*value = values.bits & 1;
	return 0;
}

int rpi_gpio_write(uint32_t pin, uint8_t value) {
	const int* gpio_fd = &rpi_gpios_fds[pin];
	if (*gpio_fd < 0) {
		int ret = rpi_gpio_set_pin_mode(pin, RPI_GPIO_OUTPUT);
		if (ret != 0) {
			return ret;
		}
	}

	struct gpio_v2_line_values values;
	memset(&values, 0, sizeof(values));
	values.mask = 0b1;
	values.bits = value ? 0b1 : 0;

	int ret = ioctl(*gpio_fd, GPIO_V2_LINE_SET_VALUES_IOCTL, &values);
	if (ret == -1) {
		return ret;
	}

	return 0;
}
