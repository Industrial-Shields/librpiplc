#include <rpiplc.h>

#include "common.h"

void setup() {
	printf("Num digital inputs: %d\n", numDigitalInputs);
	for (int i = 0; i < numDigitalInputs; ++i) {
		pinMode(digitalInputs[i], INPUT);
	}
}

void loop() {
	for (int i = 0; i < numDigitalInputs; ++i) {
		int value = digitalRead(digitalInputs[i]);
		printf("Pin %08x value: %u\n", digitalInputs[i], value);
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
