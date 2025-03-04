/**
 * Copyright (c) 2024 Industrial Shields. All rights reserved
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cerrno>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

uint32_t value = 0xFFFFFFFF;



void setup() {
	printf("librpiplc version: %s\n", LIB_RPIPLC_VERSION);
	fflush(stdout);

	int result = initExpandedGPIO(false);
	if (result < 0 || result == PLC_PERIHPERALS_STRUCT_INVALID) {
		PERROR_WITH_LINE("initExpandedGPIO failed");
		exit(-1);
	}
	else if (result > 1) {
		fprintf(stderr, "WARNING: initExpandedGPIO returned %d\n", result);
	}

	printf("Number of digital outputs: %zu\n", numDigitalOutputs);

	// TODO: digitalWriteAll doesn't work with direct pins

	for (size_t c = 0; c < numDigitalOutputs; c++) {
		pinMode(digitalOutputs[c], OUTPUT);
	}
}

void loop() {
	value = value == 0 ? 0xFFFFFFFF : 0;

	printf("Set value 0x%0X\n", value);

	int ret;
	for (size_t i = 0; i < NUM_ARRAY_MCP23008; i++) {
		ret = digitalWriteAll(ARRAY_MCP23008[i], value);
		if (ret != 0) {
			PERROR_WITH_LINE("digitalWriteAll fail");
			exit(-1);
		}
	}
	for (size_t i = 0; i < NUM_ARRAY_PCA9685; i++) {
		ret = digitalWriteAll(ARRAY_PCA9685[i], value);
		if (ret != 0) {
			PERROR_WITH_LINE("digitalWriteAll fail");
			exit(-1);
		}
	}

	delay(1000);
}
