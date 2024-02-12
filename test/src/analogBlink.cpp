#include <rpiplc.h>

#include "pins_references.h"

const static uint16_t values[] = {0, 511, 1023, 2047, 4095, 2047, 1023, 511};
const static int numValues = sizeof(values) / sizeof(uint16_t);

void setup() {
	for (int i = 0; i < numAnalogOutputs; ++i) {
		pinMode(analogOutputs[i], OUTPUT);
	}
}

void loop() {
	for (int i = 0; i < numValues; ++i) {
		printf("Set value %d\n", values[i]);

		for (int j = 0; j < numAnalogOutputs; ++j) {
			analogWrite(analogOutputs[j], values[i]);
		}

		delay(1000);
	}
}

int main(int argc, char* argv[]) {
	initPins();

	setup();

	while (1) {
		loop();
	}

	return 0;
}
