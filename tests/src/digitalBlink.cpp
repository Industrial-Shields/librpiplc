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

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"
#include "find-pin.hpp"

int value = 1;

static std::vector<pin_name_t> digitalBlinking;
static size_t digitalBlinkingSize = 0;



void setup() {
	printf("librpiplc version: %s\n", LIB_RPIPLC_VERSION);
	fflush(stdout);

	if (initExpandedGPIO(false) < 0) {
		PERROR_WITH_LINE("initExpandedGPIO failed");
		exit(-1);
	}

	printf("%zu digital outputs: ", numNamedDigitalInputsOutputs + numNamedDigitalOutputs);

	// Init pins that can be inputs or outputs
	for (size_t c = 0; c < numNamedDigitalInputsOutputs; c++) {
		digitalBlinking.push_back(namedDigitalInputsOutputs[c]);

		if (pinMode(namedDigitalInputsOutputs[c].pin, OUTPUT) != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}

		printf("%s ", namedDigitalInputsOutputs[c].name);
	}

	if (numNamedDigitalOutputs > 0) {
		const size_t last_digital = numNamedDigitalOutputs - 1;
		for (size_t c = 0; c < last_digital; c++) {
			digitalBlinking.push_back(namedDigitalOutputs[c]);

			pinMode(namedDigitalOutputs[c].pin, OUTPUT);

			printf("%s ", namedDigitalOutputs[c].name);
		}
		digitalBlinking.push_back(namedDigitalOutputs[last_digital]);
		printf("%s\n", namedDigitalOutputs[last_digital].name);

		digitalBlinkingSize = digitalBlinking.size();
	}
}

void loop() {
	value = value == 0 ? 1 : 0;

	printf("Set value %d\n", value);
	for (size_t p = 0; p < digitalBlinkingSize; p++) {
		if (digitalWrite(digitalBlinking[p].pin, value) != 0) {
			fprintf(stderr, "Pin %s ", digitalBlinking[p].name);
			PERROR_WITH_LINE("digitalWrite fail");
			exit(-1);
		}
	}

	delay(1000);
}
