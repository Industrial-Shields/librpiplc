#include <stdio.h>

#include "pca9685.h"

// Registers
#define MODE1_REGISTER		0x00
#define MODE2_REGISTER		0x01
#define SUBADR1_REGISTER	0x02
#define SUBADR2_REGISTER	0x03
#define SUBADR3_REGISTER	0x04
#define ALLCALLADR_REGISTER	0x05

#define LED_REGISTERS(i)	(0x06 + (i * 4))
#define LED_ON_L(i)		(LED_REGISTERS(i))
#define LED_ON_H(i)		(LED_REGISTERS(i) + 1)
#define LED_OFF_L(i)		(LED_REGISTERS(i) + 2)
#define LED_OFF_H(i)		(LED_REGISTERS(i) + 3)

#define PRE_SCALE_REGISTER	0xfe

// Registers values and masks
#define MODE1_ALLCALL		0x01
#define MODE1_SUB3		0x02
#define MODE1_SUB2		0x04
#define MODE1_SUB1		0x08
#define MODE1_SLEEP		0x10
#define MODE1_AI		0x20
#define MODE1_EXTCLK		0x40
#define MODE1_RESTART		0x80

#define MODE2_OUTNE_1		0x01
#define MODE2_OUTNE_Z		0x02
#define MODE2_OUTDRV		0x04
#define MODE2_OCH		0x08
#define MODE2_INVRT		0x10

static uint8_t buffer[1 + (4 * PCA9685_NUM_OUTPUTS)];

static int write_regs(i2c_t* i2c, uint8_t addr, uint8_t len) {
	if (i2c_write(i2c, addr, buffer, len) != len) {
		fprintf(stderr, "write_regs error (%02x, %d)\n", addr, len);
		return 0;
	}

	return 1;
}

static int set_led(i2c_t* i2c, uint8_t addr,  uint8_t index,
		uint8_t on_l, uint8_t on_h, uint8_t off_l, uint8_t off_h) {

	// Prevent MODE1 and MODE2 uncontrolled overwrite
	uint8_t* ptr = buffer;
	ptr = buffer;
	*ptr++ = MODE1_REGISTER;
	*ptr++ = MODE1_AI;
	*ptr++ = MODE2_OUTDRV;
	if (!write_regs(i2c, addr, ptr - buffer)) {
		return 0;
	}

	ptr = buffer;
	*ptr++ = LED_REGISTERS(index);
	*ptr++ = on_l;
	*ptr++ = on_h;
	*ptr++ = off_l;
	*ptr++ = off_h;

	return write_regs(i2c, addr, ptr - buffer);
}

int pca9685_init(i2c_t* i2c, uint8_t addr) {
	uint8_t* ptr = buffer;
	uint8_t mode1, mode2, prescale;
	mode1 = mode2 = prescale = 0x00;

	i2c_read(i2c, addr, MODE1_REGISTER, &mode1, 1);
	i2c_read(i2c, addr, MODE2_REGISTER, &mode2, 1);
	i2c_read(i2c, addr, PRE_SCALE_REGISTER, &prescale, 1);

	if ( (mode1 == MODE1_AI) && (mode2 == MODE2_OUTDRV) && (prescale == 11) ) {
		return 1;
	}

	*ptr++ = MODE1_REGISTER;
	*ptr++ = MODE1_SLEEP | MODE1_AI;
	if (!write_regs(i2c, addr, ptr - buffer)) {
		return 0;
	}

	ptr = buffer;
	*ptr++ = MODE2_REGISTER;
	*ptr++ = MODE2_OUTDRV;
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

int pca9685_set_all_digital(i2c_t* i2c, uint8_t addr, uint16_t values) {
	uint8_t* ptr = buffer;
	*ptr++ = LED_REGISTERS(0);

	for (int i = 0; i < PCA9685_NUM_OUTPUTS; ++i) {
		*ptr++ = 0x00;
		*ptr++ = (values & (1 << i)) ? 0x10 : 0x00;
		*ptr++ = 0x00;
		*ptr++ = (values & (1 << i)) ? 0x00 : 0x10;
	}

	return write_regs(i2c, addr, ptr - buffer);
}

int pca9685_set_all_analog(i2c_t* i2c, uint8_t addr, const uint16_t* values) {
	uint8_t* ptr = buffer;
	*ptr++ = LED_REGISTERS(0);

	for (int i = 0; i < PCA9685_NUM_OUTPUTS; ++i) {
		*ptr++ = 0x00;
		*ptr++ = 0x00;
		*ptr++ = values[i] & 0xff;
		*ptr++ = (values[i] >> 8) & 0x0f;
	}

	return write_regs(i2c, addr, ptr - buffer);
}
