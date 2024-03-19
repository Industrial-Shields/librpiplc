#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

const size_t numDigitals  = numNamedDigitalInputs + numNamedAnalogInputs;

void setup() {
	printf("Number of digital inputs: %zu\n\n", numDigitals);

	int ret;
	for (size_t i = 0; i < numNamedDigitalInputs; i++) {
		ret = pinMode(namedDigitalInputs[i].pin, INPUT);
		if (ret != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}
	}
	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		ret = pinMode(namedAnalogInputs[i].pin, INPUT);
		if (ret != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}
	}
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
