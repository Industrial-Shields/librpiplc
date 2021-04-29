#include "mcp23008.h"

// Registers
#define IODIR_REGISTER		0x00
#define IPOL_REGISTER		0x01
#define GPINTEN_REGISTER	0x02
#define DEFVAL_REGISTER		0x03
#define INTCON_REGISTER		0x04
#define IOCON_REGISTER		0x05
#define GPPU_REGISTER		0x06
#define INTF_REGISTER		0x07
#define INTCAP_REGISTER		0x08
#define GPIO_REGISTER		0x09
#define OLAT_REGISTER		0x0a

// Registers values and masks
#define IOCON_INTPOL		0x02
#define IOCON_ODR			0x04
#define IOCON_DISSLW		0x10
#define IOCON_SEQOP			0x20

static uint8_t buffer[2];

static int write_reg(i2c_t* i2c, uint8_t addr, uint8_t len) {
	return i2cWrite(i2c, addr, buffer, len) == len;
}

int mcp23008_init(i2c_t* i2c, uint8_t addr) {
	uint8_t* ptr = buffer;

	*ptr++ = IODIR_REGISTER;
	*ptr++ = 0xff; // Inputs
	if (!write_reg(i2c, addr, ptr - buffer)) {
		return 0;
	}

	*ptr++ = IOCON_REGISTER;
	*ptr++ = IOCON_SEQOP | IOCON_ODR;
	if (!write_reg(i2c, addr, ptr - buffer)) {
		return 0;
	}

	ptr = buffer;
	*ptr++ = GPPU_REGISTER;
	*ptr++ = 0x00; // No pull-ups
	if (!write_reg(i2c, addr, ptr - buffer)) {
		return 0;
	}

	return 1;
}

uint8_t mcp23008_read(i2c_t* i2c, uint8_t addr, uint8_t index) {
	uint8_t* ptr = buffer;

	*ptr++ = GPIO_REGISTER;
	if (i2cWrite(i2c, addr, buffer, 1) != 1) {
		return 0;
	}

	if (i2cRead(i2c, addr, buffer, 1) != 1) {
		return 0;
	}

	return (buffer[0] >> index) & 1;
}
