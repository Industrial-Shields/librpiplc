#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"
#include "find-pin.hpp"

int value = 1;

void setup() {
	printf("Number of digital outputs: %zu\n", numDigitalOutputs);

	for (size_t i = 0; i < numDigitalOutputs; i++) {
		pinMode(digitalOutputs[i], OUTPUT);
	}
}

void loop() {
	value = value == 0 ? 1 : 0;

	printf("Set value %d\n", value);
	for (size_t i = 0; i < numDigitalOutputs; i++) {
		digitalWrite(digitalOutputs[i], value);
	}

	delay(1000);
}
