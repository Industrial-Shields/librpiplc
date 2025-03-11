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
#include <vector>
#include <iostream>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

const static uint16_t values[] = {0, 511, 1023, 2047, 4095, 2047, 1023, 511};
const static size_t numValues = sizeof(values) / sizeof(uint16_t);

static std::vector<pin_name_t> analogBlinking;
static size_t analogBlinkingSize = 0;

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

	printf("%zu analog outputs: ", /*numNamedDigitalInputsOutputs +*/ numNamedAnalogOutputs);

	// TODO: Currently PWM in direct GPIOs are not supported
	/*
	// Init pins that can be inputs or outputs
	for (size_t c = 0; c < numNamedDigitalInputsOutputs; c++) {
		analogBlinking.push_back(namedDigitalInputsOutputs[c]);

		if (pinMode(namedDigitalInputsOutputs[c].pin, OUTPUT) != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}

		printf("%s ", namedDigitalInputsOutputs[c].name);
	}
	*/

	if (numNamedAnalogOutputs > 0) {
		const size_t last_analog = numNamedAnalogOutputs - 1;
		for (size_t c = 0; c < last_analog; c++) {
			analogBlinking.push_back(namedAnalogOutputs[c]);

			printf("%s ", namedAnalogOutputs[c].name);

			pinMode(namedAnalogOutputs[c].pin, OUTPUT);
		}
		analogBlinking.push_back(namedAnalogOutputs[last_analog]);
		printf("%s\n", namedAnalogOutputs[last_analog].name);

		analogBlinkingSize = analogBlinking.size();
	}
}

void loop() {
	for (size_t v = 0; v < numValues; v++) {
		printf("Set value %d\n", values[v]);

		for (size_t p = 0; p < analogBlinkingSize; p++) {
			if (analogWrite(analogBlinking[p].pin, values[v]) != 0) {
				fprintf(stderr, "Pin %s ", analogBlinking[p].name);
				PERROR_WITH_LINE("analogWrite fail");
				exit(-1);
			}
		}

		delay(1000);
	}
}
