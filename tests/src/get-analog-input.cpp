#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <string>

using namespace std;

#include <rpiplc.h>

#include "pins-references.hpp"
#include "find-pin.hpp"


int main (int argc, const char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <io-name>\n", argv[0]);
		return 1;
	}

	const pin_name_t* pin = find_pin<namedAnalogInputs, numNamedAnalogInputs>(argv[1]);
	if (pin) {
		initExpandedGPIO();
		pinMode(pin->pin, INPUT);
		uint16_t read_value = analogRead(pin->pin);
		printf("%u\n", read_value);
		return 0;
	}

	return 1;
}
