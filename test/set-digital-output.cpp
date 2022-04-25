#include <cstring>
#include <rpiplc.h>
#include "pins_reference.h"

//////////////////////////////////////////////////////////////////////////////////////
const pin_t* findPin(const char* name){

	for (int i = 0; i < numDigitalOutputs; i++) {
		if (strcmp(name, digitalOutputs[i].name) == 0) {
			return &digitalOutputs[i];
		}
	}
	return nullptr;
}

//////////////////////////////////////////////////////////////////////////////////////
int main (int argc, const char* argv[]) {

	if (argc < 3 ) {
		fprintf(stderr, "Usage: %s <io-name> <value>\n", argv[0]);
		return 1;
	}

	initPins();

	int value = atoi(argv[2]);
	const pin_t* pin = findPin(argv[1]);

	if (pin) {
//		printf("ChipAddrChipIndex: %s %04x\n", pin->name, pin->pin);
		pinMode(pin->pin, OUTPUT);
		digitalWrite(pin->pin, value);
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////



