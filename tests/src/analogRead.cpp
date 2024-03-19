#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

void setup() {
	printf("Number of analog inputs: %zu\n\n", numNamedAnalogInputs);

	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		int ret = pinMode(namedAnalogInputs[i].pin, INPUT);
		if (ret != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}
	}
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
