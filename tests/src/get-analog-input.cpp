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
		return -2;
	}

        const pin_name_t* pin = find_pin<namedAnalogInputs, numNamedAnalogInputs>(argv[1]);

	if (pin != nullptr) {
		int ret;
		ret = initExpandedGPIO(false);
		if (ret != 0) {
			PERROR_WITH_LINE("initExpandedGPIO fail");
			exit(-1);
		}

		ret = pinMode(pin->pin, INPUT);
		if (ret != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}

		printf("%u\n", analogRead(pin->pin));
		return 0;
	}
	else {
		fprintf(stderr, "\"%s\" is an unknown analog pin\n", argv[1]);
		return -1;
	}
}
