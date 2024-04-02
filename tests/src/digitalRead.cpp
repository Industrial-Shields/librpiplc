#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cerrno>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

const size_t numDigitals  = numNamedDigitalInputs + numNamedAnalogInputs;



void setup() {
	if (initExpandedGPIO(false) != 0 && errno != EALREADY) {
		PERROR_WITH_LINE("initExpandedGPIO failed");
		exit(-1);
	}

	printf("Number of digital inputs: %zu\n\n", numDigitals);
}

void loop() {
	for (size_t i = 0; i < numNamedDigitalInputs; i++) {
		int value = digitalRead(namedDigitalInputs[i].pin);
		printf("  Pin %s value: %u\n", namedDigitalInputs[i].name, value);
	}
	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		int value = digitalRead(namedAnalogInputs[i].pin);
		printf("  Pin %s value: %u\n", namedAnalogInputs[i].name, value);
	}

	for (size_t i = 0; i < numDigitals; i++) {
		printf("\033[A");
	}

	delay(1000);
}
