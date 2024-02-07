#include <cstring>
#include <rpiplc.h>
#include "pins_reference.h"

//////////////////////////////////////////////////////////////////////////////////////
const pin_t* findPin(const char* name){

	for (int i = 0; i < numAnalogInputs; i++) {
		if (strcmp(name, analogInputs[i].name) == 0) {
			return &analogInputs[i];
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

	const pin_t* pin = findPin(argv[1]);

	if (pin) {
		pinMode(pin->pin, INPUT);
		uint16_t value = analogRead(pin->pin);
		printf("%u\n", value);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
