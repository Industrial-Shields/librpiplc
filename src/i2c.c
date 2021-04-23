#include "i2c.h"

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
int i2cInit(i2c_t* i2c, uint8_t bus) {
	if (i2c == NULL) {
		fprintf(stderr, "i2cInit: invalid i2c\n");
		return 1;
	}

	char i2cFileName[50];
	sprintf(i2cFileName, "/dev/i2c-%d", bus);
	i2c->fd = open(i2cFileName, O_RDWR);
	if (i2c->fd < 0) {
		perror("i2cInit");
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
		fprintf(stderr, "i2cWrite: invalid i2c\n");
		return 0;
	}

	if (ioctl(i2c->fd, I2C_SLAVE, addr) < 0) {
		perror("i2cWrite");
		return 0;
	}

	size_t wLen = write(i2c->fd, buff, len);
	if (wLen != len) {
		perror("i2cWrite");
		fprintf(stderr, "i2cWrite: invalid len (%lu != %lu)\n", wLen, len);
		return 0;
	}

	return len;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t i2cRead(i2c_t* i2c, uint8_t addr, void* buff, size_t len) {
	if ((i2c == NULL) || (i2c->fd < 0) || (buff == NULL) || (len == 0)) {
		fprintf(stderr, "i2cInit: invalid i2c\n");
		return 0;
	}

	if (ioctl(i2c->fd, I2C_SLAVE, addr) < 0) {
		perror("i2cRead");
		return 0;
	}

	if (read(i2c->fd, buff, len) != len) {
		fprintf(stderr, "i2cRead: invalid len\n");
		return 0;
	}

	return len;
}
