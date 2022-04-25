#include "rpiplc-peripherals.h"

const uint8_t rpiplc_mcp23008[] = {
	0x20, 0x21,
};
const int rpiplc_num_mcp23008 = sizeof(rpiplc_mcp23008) / sizeof(uint8_t);

const uint8_t rpiplc_ads1015[] = {
	0x48, 0x49, 0x4a, 0x4b,
};
const int rpiplc_num_ads1015 = sizeof(rpiplc_ads1015) / sizeof(uint8_t);

const uint8_t rpiplc_pca9685[] = {
	0x40, 0x41,
};
const int rpiplc_num_pca9685 = sizeof(rpiplc_pca9685) / sizeof(uint8_t);

const uint8_t rpiplc_ltc2309[] = {
	0x08, 0x0a, 0x28
};
const int rpiplc_num_ltc2309 = sizeof(rpiplc_ltc2309) / sizeof(uint8_t);
