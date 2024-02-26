#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

void setup() {
	printf("Number of analog inputs: %zu\n", numNamedAnalogInputs);

	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		pinMode(namedAnalogInputs[i].pin, INPUT);
	}
}

void loop() {
	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		uint16_t value = analogRead(namedAnalogInputs[i].pin);
		printf("Pin %s value: %u\n", namedAnalogInputs[i].name, value);
	}

	printf("\n");
	delay(1000);
}
