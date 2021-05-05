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

static int write_reg(i2c_t* i2c, uint8_t addr, uint8_t reg, uint8_t value) {
	const uint8_t buff[] = { reg, value };
	return i2cWrite(i2c, addr, buff, sizeof(buff)) == sizeof(buff);
}

int mcp23008_init(i2c_t* i2c, uint8_t addr) {
	if (!write_reg(i2c, addr, IODIR_REGISTER, 0xff)) {
		return 0;
	}

	if (!write_reg(i2c, addr, IOCON_REGISTER, IOCON_SEQOP | IOCON_ODR)) {
		return 0;
	}

	if (!write_reg(i2c, addr, GPPU_REGISTER, 0x00)) {
		return 0;
	}

	return 1;
}

uint8_t mcp23008_read(i2c_t* i2c, uint8_t addr, uint8_t index) {
	uint8_t value = 0x00;
	if (i2cRead(i2c, addr, GPIO_REGISTER, &value, 1) != 1) {
		return 0;
	}

	return (value >> index) & 1;
}
