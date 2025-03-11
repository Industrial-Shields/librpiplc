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

#include <plc-peripherals.h>



#if defined(RPIPLC_V3) || defined(RPIPLC_V4) || defined(RPIPLC_V6)
#define __ARRAY_MCP23008 ((const uint8_t[]){ 0x20, 0x21 })
#else
#define __ARRAY_MCP23008 ((const uint8_t[]){})
#endif

#if defined(RPIPLC_V3)
#define __ARRAY_ADS1015 ((const uint8_t[]){ 0x48, 0x49, 0x4a, 0x4b })
#elif defined(TOUCHBERRY_PI_V1)
#define __ARRAY_ADS1015 ((const uint8_t[]){ 0x49 })
#else
#define __ARRAY_ADS1015 ((const uint8_t[]){})
#endif


#if defined(RPIPLC_V3) || defined(RPIPLC_V4) || defined(RPIPLC_V6)
#define __ARRAY_PCA9685 ((const uint8_t[]){ 0x40, 0x41 })
#else
#define __ARRAY_PCA9685 ((const uint8_t[]){})
#endif


#if defined(RPIPLC_V4) || defined(RPIPLC_V6)
#if defined(RPIPLC_21) || defined(RPIPLC_19R)
#define __ARRAY_LTC2309 ((const uint8_t[]){ 0x08, 0x0a })
#else
#define __ARRAY_LTC2309 ((const uint8_t[]){ 0x08, 0x0a, 0x28 })
#endif
#else
#define __ARRAY_LTC2309 ((const uint8_t[]){})
#endif


#define __ARRAY_MCP23017 ((const uint8_t[]){})



#define initExpandedGPIO(restart) (	  \
	  ARRAY_MCP23008 = __ARRAY_MCP23008, \
	  NUM_ARRAY_MCP23008 = sizeof(__ARRAY_MCP23008) / sizeof(uint8_t), \
	  ARRAY_ADS1015 = __ARRAY_ADS1015, \
	  NUM_ARRAY_ADS1015 = sizeof(__ARRAY_ADS1015) / sizeof(uint8_t), \
	  ARRAY_PCA9685 = __ARRAY_PCA9685, \
	  NUM_ARRAY_PCA9685 = sizeof(__ARRAY_PCA9685) / sizeof(uint8_t), \
	  ARRAY_LTC2309 = __ARRAY_LTC2309, \
	  NUM_ARRAY_LTC2309 = sizeof(__ARRAY_LTC2309) / sizeof(uint8_t), \
	  ARRAY_MCP23017 = __ARRAY_MCP23017, \
	  NUM_ARRAY_MCP23017 = sizeof(__ARRAY_MCP23017) / sizeof(uint8_t), \
	  initExpandedGPIOV2(restart) \
	  )



#endif // __RPIPLC_PERIPHERALS_H__
