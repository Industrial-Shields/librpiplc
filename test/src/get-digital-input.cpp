#include <cstring>
#include <rpiplc.h>

#include "pins_references.h"

//////////////////////////////////////////////////////////////////////////////////////
const pin_name_t* findPin(const char* name){

	for (int i = 0; i < numNamedDigitalInputs; i++) {
		if (strcmp(name, namedDigitalInputs[i].name) == 0) {
			return &namedDigitalInputs[i];
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
		uint8_t value = digitalRead(pin->pin);
		printf("%u\n", value);
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////
