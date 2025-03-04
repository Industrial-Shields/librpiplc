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
#include <iostream>
#include <string>
#include <cerrno>

using namespace std;

#include <rpiplc.h>

#include "pins-references.hpp"
#include "find-pin.hpp"



int main(int argc, const char* argv[]) {
	int result = initExpandedGPIO(false);
	if (result < 0 || result == PLC_PERIHPERALS_STRUCT_INVALID) {
		PERROR_WITH_LINE("initExpandedGPIO failed");
		exit(-1);
	}
	else if (result > 1) {
		fprintf(stderr, "WARNING: initExpandedGPIO returned %d\n", result);
	}

	if (argc != 3 && argc != 4) {
		fprintf(stderr, "Usage: %s <io-name> <value> OPTIONAL_PWM_FREQ\n", argv[0]);
		return 1;
	}

	int value_to_write;
        try {
		value_to_write = stoi(argv[2]);
	}
	catch (const exception& e) {
		fprintf(stderr, "Error: %s\n", e.what());
		return 2;
	}

	if (value_to_write < 0 || value_to_write > 4095) {
		fprintf(stderr, "Out of range: %d\n", value_to_write);
		return 3;
	}

	int64_t pwm_freq;
	if (argc == 4) {
		try {
			pwm_freq = stoi(argv[3]);
		}
		catch (const exception& e) {
			fprintf(stderr, "Error: %s\n", e.what());
			return 10;
		}
	}
	else {
		pwm_freq = -1;
	}

	const pin_name_t* pin = find_pin<namedPWMOutputs, numNamedPWMOutputs>(argv[1]);

	if (pin != nullptr) {
		pinMode(pin->pin, OUTPUT);

		if (pwm_freq != -1 &&
		    analogWriteSetFrequency(pin->pin, pwm_freq) != 0) {
			if (errno == ERANGE) {
				fprintf(stderr, "PWM frequency not valid\n");
				return 8;
			}
			else {
				PERROR_WITH_LINE("analogWriteSetFrequency fail");
			        return 9;
			}
		}

		if (analogWrite(pin->pin, value_to_write) != 0) {
			PERROR_WITH_LINE("analogWrite fail");
			return 5;
		}

		printf("Pin %s set at %d\n", pin->name, value_to_write);
		return 0;
	}

	else {
		fprintf(stderr, "\"%s\" is an unknown pin\n", argv[1]);
		return 2;
	}
}
