#include "i2c.h"

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
int i2cInit(i2c_t* i2c, uint8_t bus) {
	if (i2c == NULL) {
		return 1;
	}

	char i2cFileName[50];
	sprintf(i2cFileName, "/dev/i2c-%d", bus);
	i2c->fd = open(i2cFileName, O_RDWR);
	if (i2c->fd < 0) {
		return 1;
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void i2cDeinit(i2c_t* i2c) {
	if ((i2c != NULL) && (i2c->fd >= 0)) {
		close(i2c->fd);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t i2cWrite(i2c_t* i2c, uint8_t addr, const void* buff, size_t len) {
	if ((i2c == NULL) || (i2c->fd < 0) || (buff == NULL) || (len == 0)) {
		return 0;
	}

	if (ioctl(i2c->fd, I2C_SLAVE, addr) < 0) {
		return 1;
	}

	return write(i2c->fd, buff, len);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t i2cRead(i2c_t* i2c, uint8_t addr, void* buff, size_t len) {
	if ((i2c == NULL) || (i2c->fd < 0) || (buff == NULL) || (len == 0)) {
		return 0;
	}

	if (ioctl(i2c->fd, I2C_SLAVE, addr) < 0) {
		return 1;
	}

	return read(i2c->fd, buff, len);
}
