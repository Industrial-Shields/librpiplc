#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <string>

using namespace std;

#include <rpiplc.h>

#include "pins_references.hpp"
#include "find_pin.hpp"


int main (int argc, const char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <io-name>\n", argv[0]);
		return 1;
	}

	const pin_name_t* pin = find_pin<namedDigitalInputs, numNamedDigitalInputs>(argv[1]);
	if (pin) {
		initPins();
		pinMode(pin->pin, INPUT);
		uint16_t read_value = digitalRead(pin->pin);
		printf("%u\n", read_value);
		return 0;
	}

	return 1;
}
