#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cerrno>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"



void setup() {
	if (initExpandedGPIO(false) != 0 && errno != EALREADY) {
		PERROR_WITH_LINE("initExpandedGPIO failed");
		exit(-1);
	}

	printf("Number of analog inputs: %zu\n\n", numNamedAnalogInputs);
}

void loop() {
	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		int value = analogRead(namedAnalogInputs[i].pin);
		printf("  Pin %s value: %4u\n", namedAnalogInputs[i].name, value);
	}

	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		printf("\033[A");
	}

	delay(1000);
}
