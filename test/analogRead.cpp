#include <rpiplc.h>
#include "common.h"

void setup() {
	for (int i = 0; i < numAnalogInputs; ++i) {
		pinMode(analogInputs[i], INPUT);
	}
}

void loop() {
	for (int i = 0; i < numAnalogInputs; ++i) {
		uint16_t value = analogRead(analogInputs[i]);
		printf("Pin %08x value: %u\n", analogInputs[i], value);
	}

	delay(1000);
}

int main(int argc, char* argv[]) {
	initPins();

	setup();

	while (1) {
		loop();
	}

	return 0;
}
