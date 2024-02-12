#include <rpiplc.h>

#include "pins_references.h"

uint32_t value = 0;

void setup() {
	printf("Num digital outputs: %d\n", numDigitalOutputs);

	for (int i = 0; i < numDigitalOutputs; ++i) {
		pinMode(digitalOutputs[i], OUTPUT);
	}
}

void loop() {
	value = value == 0 ? 0xffffffff : 0;

	for (int i = 0; i < rpiplc_num_mcp23008; ++i) {
		digitalWriteAll(rpiplc_mcp23008[i], value);
	}
	for (int i = 0; i < rpiplc_num_pca9685; ++i) {
		digitalWriteAll(rpiplc_pca9685[i], value);
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
