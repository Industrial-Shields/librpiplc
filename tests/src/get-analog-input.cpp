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
	if (initExpandedGPIO(false) != 0 && errno != EALREADY) {
		PERROR_WITH_LINE("initExpandedGPIO fail");
	        return -1;
	}

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <io-name>\n", argv[0]);
		return 1;
	}

        const pin_name_t* pin = find_pin<namedAnalogInputs, numNamedAnalogInputs>(argv[1]);

	if (pin != nullptr) {
		printf("%u\n", analogRead(pin->pin));
		return 0;
	}
	else {
		fprintf(stderr, "\"%s\" is an unknown analog pin\n", argv[1]);
		return 2;
	}
}
