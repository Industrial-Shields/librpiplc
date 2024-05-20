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
	if (initExpandedGPIO(false) < 0) {
		PERROR_WITH_LINE("initExpandedGPIO fail");
	        return -1;
	}

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <io-name> <value>\n", argv[0]);
		return 1;
	}

	int value_to_write;
        try {
		value_to_write = stoi(argv[2]);
	}
	catch (const exception& e) {
		fprintf(stderr, "Error: %s\n", e.what());
		return 3;
	}

	if (value_to_write != 0 && value_to_write != 1) {
		fprintf(stderr, "Out of range: %d\n", value_to_write);
		return 4;
	}

	const pin_name_t* pin = find_pin<namedDigitalOutputs, numNamedDigitalOutputs>(argv[1]);
	if (pin == nullptr) {
		pin = find_pin<namedAnalogOutputs, numNamedAnalogOutputs>(argv[1]);
	}

	if (pin != nullptr) {
		if (digitalWrite(pin->pin, value_to_write) != 0) {
			PERROR_WITH_LINE("digitalWrite fail");
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
