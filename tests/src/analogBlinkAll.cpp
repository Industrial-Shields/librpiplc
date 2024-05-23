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

const static uint16_t values[] = {0, 511, 1023, 2047, 4095, 2047, 1023, 511};
const static int numValues = sizeof(values) / sizeof(uint16_t);



void setup() {
	printf("librpiplc version: %s\n", LIB_RPIPLC_VERSION);
	fflush(stdout);

	if (initExpandedGPIO(false) < 0) {
		PERROR_WITH_LINE("initExpandedGPIO failed");
		exit(-1);
	}

	printf("%zu analog outputs: ", /*numNamedDigitalInputsOutputs +*/ numNamedAnalogOutputs);

	/* TODO: Currently PWM in direct GPIOs are not supported. And also analogWriteAll doesn't work
	 * with direct pins
	 */
}

static bool is_output_analog(uint8_t addr, uint8_t index) {
	uint32_t pin = ((addr << 8) | index);
	for (size_t c = 0; c < numAnalogOutputs; c++) {
		if (pin == analogOutputs[c]) {
			pinMode(pin, OUTPUT);

			return true;
		}
	}

	return false;
}

void loop() {
	for (size_t val = 0; val < numValues; val++) {
		printf("Set value %d\n", values[val]);

		for (size_t pca = 0; pca < NUM_ARRAY_PCA9685; pca++) {
			uint16_t analogValues[PCA9685_NUM_OUTPUTS];
			for (size_t ch = 0; ch < PCA9685_NUM_OUTPUTS; ch++) {
				if (is_output_analog(ARRAY_PCA9685[pca], ch)) {
					analogValues[ch] = values[val];
				}
				else {
					analogValues[ch] = 0;
				}
			}
			int ret = analogWriteAll(ARRAY_PCA9685[pca], analogValues);
		        if (ret != 0) {
				PERROR_WITH_LINE("analogWrite fail");
				exit(-1);
			}
		}

		delay(1000);
	}
}
