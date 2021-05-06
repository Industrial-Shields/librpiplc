#include "i2c.h"

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
int i2c_init(i2c_t* i2c, uint8_t bus) {
	if (i2c == NULL) {
		fprintf(stderr, "i2c_init: invalid i2c\n");
		return 1;
	}

	char i2cFileName[50];
	sprintf(i2cFileName, "/dev/i2c-%d", bus);
	i2c->fd = open(i2cFileName, O_RDWR);
	if (i2c->fd < 0) {
		perror("i2c_init");
		return 1;
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void i2c_deinit(i2c_t* i2c) {
	if ((i2c != NULL) && (i2c->fd >= 0)) {
		close(i2c->fd);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t i2c_write(i2c_t* i2c, uint8_t addr, const void* buff, size_t len) {
	if ((i2c == NULL) || (i2c->fd < 0) || (buff == NULL) || (len == 0)) {
		fprintf(stderr, "i2c_write: invalid i2c\n");
		return 0;
	}

	if (ioctl(i2c->fd, I2C_SLAVE, addr) < 0) {
		perror("i2c_write");
		return 0;
	}

	size_t wLen = write(i2c->fd, buff, len);
	if (wLen != len) {
		perror("i2c_write");
		fprintf(stderr, "i2c_write: invalid len (%u != %u)\n", (unsigned int) wLen, (unsigned int) len);
		return 0;
	}

	return len;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t i2c_read(i2c_t* i2c, uint8_t addr, uint8_t reg, void* buff, size_t len) {
	if ((i2c == NULL) || (i2c->fd < 0) || (buff == NULL) || (len == 0)) {
		fprintf(stderr, "i2cInit: invalid i2c\n");
		return 0;
	}

	struct i2c_msg msgs[2];
	struct i2c_rdwr_ioctl_data data[1];

	msgs[0].addr = addr;
	msgs[0].flags = 0;
	msgs[0].len = 1;
	msgs[0].buf = &reg;

	msgs[1].addr = addr;
	msgs[1].flags = I2C_M_RD | I2C_M_NOSTART;
	msgs[1].len = len;
	msgs[1].buf = (uint8_t*) buff;

	data[0].msgs = msgs;
	data[0].nmsgs = 2;

	if (ioctl(i2c->fd, I2C_RDWR, &data) < 0) {
		perror("i2c_read");
		return 0;
	}

	return len;
}
