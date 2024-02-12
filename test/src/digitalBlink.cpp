#include <rpiplc.h>

#include "pins_references.h"

int value = 0;

void setup() {
	printf("Num digital outputs: %d\n", numDigitalOutputs);

	for (int i = 0; i < numDigitalOutputs; ++i) {
		pinMode(digitalOutputs[i], OUTPUT);
	}
}

void loop() {
	value = value == 0 ? 1 : 0;

	printf("Set value %d\n", value);
	for (int i = 0; i < numDigitalOutputs; ++i) {
		digitalWrite(digitalOutputs[i], value);
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
