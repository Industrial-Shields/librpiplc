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

const size_t numDigitals  = numNamedDigitalInputs + numNamedAnalogInputs;



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

	printf("Number of digital inputs: %zu\n\n", numDigitals);

	for (size_t c = 0; c < numDigitalInputs; c++) {
		pinMode(digitalInputs[c], INPUT);
	}
	for (size_t c = 0; c < numAnalogInputs; c++) {
		pinMode(analogInputs[c], INPUT);
	}
}

void loop() {
	for (size_t i = 0; i < numNamedDigitalInputs; i++) {
		int value = digitalRead(namedDigitalInputs[i].pin);
		printf("  Pin %s value: %u\n", namedDigitalInputs[i].name, value);
	}
	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		int value = digitalRead(namedAnalogInputs[i].pin);
		printf("  Pin %s value: %u\n", namedAnalogInputs[i].name, value);
	}

	for (size_t i = 0; i < numDigitals; i++) {
		printf("\033[A");
	}

	delay(1000);
}
