#include "pca9685.h"

// Registers
#define MODE1_REGISTER		0x00
#define MODE2_REGISTER		0x01
#define SUBADR1_REGISTER	0x02
#define SUBADR2_REGISTER	0x03
#define SUBADR3_REGISTER	0x04
#define ALLCALLADR_REGISTER	0x05

#define LED_REGISTERS(i)	(0x06 + (i * 4))
#define LED_ON_L(i)			(LED_REGISTERS(i))
#define LED_ON_H(i)			(LED_REGISTERS(i) + 1)
#define LED_OFF_L(i)		(LED_REGISTERS(i) + 2)
#define LED_OFF_H(i)		(LED_REGISTERS(i) + 3)

#define PRE_SCALE_REGISTER	0xfe

// Registers values and masks
#define MODE1_ALLCALL		0x01
#define MODE1_SUB3			0x02
#define MODE1_SUB2			0x04
#define MODE1_SUB1			0x08
#define MODE1_SLEEP			0x10
#define MODE1_AI			0x20
#define MODE1_EXTCLK		0x40
#define MODE1_RESTART		0x80

#define MODE2_OUTNE_1		0x01
#define MODE2_OUTNE_Z		0x02
#define MODE2_OUTDRV		0x04
#define MODE2_OCH			0x08
#define MODE2_INVRT			0x10

static uint8_t buffer[5];

static int write_regs(i2c_t* i2c, uint8_t addr, uint8_t len) {
	return i2cWrite(i2c, addr, buffer, len) == len;
}

static int set_led(i2c_t* i2c, uint8_t addr,  uint8_t index,
		uint8_t on_l, uint8_t on_h, uint8_t off_l, uint8_t off_h) {

	uint8_t* ptr = buffer;
	*ptr++ = LED_REGISTERS(index);
	*ptr++ = on_l;
	*ptr++ = on_h;
	*ptr++ = off_l;
	*ptr++ = off_h;

	return write_regs(i2c, addr, ptr - buffer);
}

int pca9685_init(i2c_t* i2c, uint8_t addr) {
	uint8_t* ptr = buffer;

	*ptr++ = MODE1_REGISTER;
	*ptr++ = MODE1_SLEEP | MODE1_AI;
	if (!write_regs(i2c, addr, ptr - buffer)) {
		return 0;
	}

	ptr = buffer;
	*ptr++ = PRE_SCALE_REGISTER;
	*ptr++ = 11; // PWM frequency 500Hz
	if (!write_regs(i2c, addr, ptr - buffer)) {
		return 0;
	}

	ptr = buffer;
	*ptr++ = MODE1_REGISTER;
	*ptr++ = MODE1_AI;
	if (!write_regs(i2c, addr, ptr - buffer)) {
		return 0;
	}

	return 1;
}

int pca9685_set_out_on(i2c_t* i2c, uint8_t addr, uint8_t index) {
	return set_led(i2c, addr, index, 0x00, 0x10, 0x00, 0x00);
}

int pca9685_set_out_off(i2c_t* i2c, uint8_t addr, uint8_t index) {
	return set_led(i2c, addr, index, 0x00, 0x00, 0x00, 0x10);
}

int pca9685_set_out_pwm(i2c_t* i2c, uint8_t addr, uint8_t index, uint16_t value) {
	return set_led(i2c, addr, index, 0x00, 0x00, value & 0xff, (value >> 8) & 0x0f);
}
