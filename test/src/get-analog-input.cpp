#include <cstring>
#include <rpiplc.h>

#include "pins_references.h"

//////////////////////////////////////////////////////////////////////////////////////
const pin_name_t* findPin(const char* name){

	for (int i = 0; i < numNamedAnalogInputs; i++) {
		if (strcmp(name, namedAnalogInputs[i].name) == 0) {
			return &namedAnalogInputs[i];
		}
	}
	return nullptr;
}

//////////////////////////////////////////////////////////////////////////////////////
int main (int argc, const char* argv[]) {

	if (argc < 2 ) {
		fprintf(stderr, "Usage: %s <io-name>\n", argv[0]);
		return 1;
	}

	initPins();

	const pin_name_t* pin = findPin(argv[1]);

	if (pin) {
		pinMode(pin->pin, INPUT);
		uint16_t value = analogRead(pin->pin);
		printf("%u\n", value);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
