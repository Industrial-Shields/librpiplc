/*
 * Copyright (c) 2024 Industrial Shields. All rights reserved
 *
 * This file is part of librpiplc.
 *
 * librpiplc is free software: you can redistribute
 * it and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either version
 * 3 of the License, or (at your option) any later version.
 *
 * librpiplc is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RPIPLC_PERIPHERALS_H__
#define __RPIPLC_PERIPHERALS_H__

#include "plc-peripherals.h"

#ifdef UPSAFEPI_V6
const int I2C_BUS = PERIPHERALS_NO_I2C_BUS;
#else
// All I2C devices are connected at /dev/i2c-1
const int I2C_BUS = 1;
#endif

const uint8_t ARRAY_MCP23008[] = {
	0x20, 0x21
};
const size_t NUM_ARRAY_MCP23008 = sizeof(ARRAY_MCP23008) / sizeof(uint8_t);

const uint8_t ARRAY_ADS1015[] = {
#ifdef RPIPLC_V3
	0x48, 0x49, 0x4a, 0x4b,
#endif
};
const size_t NUM_ARRAY_ADS1015 = sizeof(ARRAY_ADS1015) / sizeof(uint8_t);

const uint8_t ARRAY_PCA9685[]  = {
	0x40, 0x41,
};
const size_t NUM_ARRAY_PCA9685 = sizeof(ARRAY_PCA9685) / sizeof(uint8_t);

const uint8_t ARRAY_LTC2309[] = {
	0x08, 0x0a, 0x28
};
const size_t NUM_ARRAY_LTC2309 = sizeof(ARRAY_LTC2309) / sizeof(uint8_t);

const uint8_t ARRAY_MCP23017[] = {};
const size_t NUM_ARRAY_MCP23017 = sizeof(ARRAY_MCP23017) / sizeof(uint8_t);

#endif // __RPIPLC_PERIPHERALS_H__
