#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

void setup() {
	printf("Number of digital inputs: %zu\n", numNamedDigitalInputs);

	for (size_t i = 0; i < numNamedDigitalInputs; i++) {
		pinMode(namedDigitalInputs[i].pin, INPUT);
	}
}

void loop() {
	for (size_t i = 0; i < numNamedDigitalInputs; i++) {
		int value = digitalRead(namedDigitalInputs[i].pin);
		printf("Pin %s value: %u\n", namedDigitalInputs[i].name, value);
	}

	printf("\n");
	delay(1000);
}
