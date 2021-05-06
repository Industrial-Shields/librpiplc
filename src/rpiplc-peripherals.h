#ifndef __RPIPLC_PERIPHERALS__
#define __RPIPLC_PERIPHERALS__

#define I2C_BUS	1

#define pinToDeviceAddress(pin) (((pin) >> 8) & 0xff)
#define pinToDeviceIndex(pin) ((pin) & 0xff)

static const uint8_t rpiplc_mcp23008[] = {
	0x20, 0x21,
};
static const int rpiplc_num_mcp23008 = sizeof(rpiplc_mcp23008) / sizeof(uint8_t);

static const uint8_t rpiplc_ads1015[] = {
	0x48, 0x49, 0x4a, 0x4b,
};
static const int rpiplc_num_ads1015 = sizeof(rpiplc_ads1015) / sizeof(uint8_t);

static const uint8_t rpiplc_pca9685[] = {
	0x40, 0x41,
};
static const int rpiplc_num_pca9685 = sizeof(rpiplc_pca9685) / sizeof(uint8_t);

#endif
