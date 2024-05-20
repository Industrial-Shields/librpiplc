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

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <io-name>\n", argv[0]);
		return 1;
	}

        const pin_name_t* pin = find_pin<namedDigitalInputs, numNamedDigitalInputs>(argv[1]);
	if (pin == nullptr) {
		pin = find_pin<namedAnalogInputs, numNamedAnalogInputs>(argv[1]);
	}

	if (pin != nullptr) {
		printf("%u\n", digitalRead(pin->pin));
		return 0;
	}
	else {
		fprintf(stderr, "\"%s\" is an unknown pin\n", argv[1]);
		return 2;
	}
}
