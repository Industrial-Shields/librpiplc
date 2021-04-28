#include <stdio.h>

#include "rpiplc.h"

#include "ads1015.h"
#include "pca9685.h"

static i2c_t i2c;

////////////////////////////////////////////////////////////////////////////////////////////////////
static int isAddressIntoArray(uint8_t addr, const uint8_t* arr, uint8_t len) {
	while (len--) {
		if (*arr++ == addr) {
			return 1;
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void initPins() {
	i2cInit(&i2c, I2C_BUS);
	for (int i = 0; i < NUM_PCA9685_DEVICES; ++i) {
		if (!pca9685_init(&i2c, pca9685Addresses[i])) {
			fprintf(stderr, "initPins: init PCA9685 (%02x) error\n", pca9685Addresses[i]);
		}
	}
	for (int i = 0; i < NUM_ADS1015_DEVICES; ++i) {
		if (!ads1015_init(&i2c, ads1015Addresses[i])) {
			fprintf(stderr, "initPins, init ADS1015 (%02x) error\n", ads1015Addresses[i]);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void analogWrite(uint32_t pin, int value) {
	uint8_t addr = pinToDeviceAddress(pin);
	uint8_t index = pinToDeviceIndex(pin);

	if (isAddressIntoArray(addr, pca9685Addresses, NUM_PCA9685_DEVICES)) {
		if (!pca9685_set_out_pwm(&i2c, addr, index, value)) {
			fprintf(stderr, "analogWrite: set PCA9685 error\n");
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t analogRead(uint32_t pin) {
	uint8_t addr = pinToDeviceAddress(pin);
	uint8_t index = pinToDeviceIndex(pin);

	if (isAddressIntoArray(addr, ads1015Addresses, NUM_ADS1015_DEVICES)) {
		return ads1015_read(&i2c, addr, index);
	}

	return 0;
}
