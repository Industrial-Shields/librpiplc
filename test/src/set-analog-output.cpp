#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <string>

using namespace std;

#include <rpiplc.h>

#include "pins-references.hpp"
#include "find-pin.hpp"


int main (int argc, const char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <io-name> <value>\n", argv[0]);
		return 1;
	}

        const int value_to_write = atoi(argv[2]);

	const pin_name_t* pin = find_pin<namedAnalogOutputs, numNamedAnalogOutputs>(argv[1]);
	if (pin) {
		initPins();
		pinMode(pin->pin, OUTPUT);
		analogWrite(pin->pin, value_to_write);
		return 0;
	}

	return 1;
}
