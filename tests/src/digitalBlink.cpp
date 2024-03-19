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
		int ret = pinMode(digitalOutputs[i], OUTPUT);
		if (ret != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}
	}
}

void loop() {
	value = value == 0 ? 1 : 0;

	printf("Set value %d\n", value);
	for (size_t i = 0; i < numDigitalOutputs; i++) {
		int ret = digitalWrite(digitalOutputs[i], value);
		if (ret != 0) {
			PERROR_WITH_LINE("digitalWrite fail");
			exit(-1);
		}
	}

	delay(1000);
}
