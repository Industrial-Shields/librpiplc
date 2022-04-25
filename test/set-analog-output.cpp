#include <cstring>
#include <rpiplc.h>
#include "pins_reference.h"

//////////////////////////////////////////////////////////////////////////////////////
const pin_t* findPin(const char* name){

	for (int i = 0; i < numAnalogOutputs; i++) {
		if (strcmp(name, analogOutputs[i].name) == 0) {
			return &analogOutputs[i];
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

	float value = atof(argv[2]);
	const pin_t* pin = findPin(argv[1]);

	if (pin) {
//		printf("Pin: %s %04x\n", pin->name, pin->pin);
		pinMode(pin->pin, OUTPUT);
		analogWrite(pin->pin, value);
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////
