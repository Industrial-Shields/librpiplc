#include "rpiplc.h"
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
	i2cInit(&i2c, 0);
	for (int i = 0; i < NUM_PCA9685_DEVICES; ++i) {
		pca9685_init(&i2c, pca9685Addresses[i]);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void analogWrite(uint32_t pin, int value) {
	uint8_t addr = pinToDeviceAddress(pin);
	uint8_t index = pinToDeviceIndex(pin);

	if (isAddressIntoArray(addr, pca9685Addresses, NUM_PCA9685_DEVICES)) {
		pca9685_set_out_pwm(&i2c, addr, index, value);
	}
}
