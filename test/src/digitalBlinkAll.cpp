#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins_references.hpp"

uint32_t value = 0xFFFFFFFF;

void setup() {
	printf("Number of digital outputs: %zu\n", numDigitalOutputs);

	for (size_t i = 0; i < numDigitalOutputs; i++) {
		pinMode(digitalOutputs[i], OUTPUT);
	}
}

void loop() {
	value = value == 0 ? 0xFFFFFFFF : 0;

	printf("Set value 0x%0X\n", value);

	for (ssize_t i = 0; i < rpiplc_num_mcp23008; i++) {
		digitalWriteAll(rpiplc_mcp23008[i], value);
	}
	for (ssize_t i = 0; i < rpiplc_num_pca9685; i++) {
		digitalWriteAll(rpiplc_pca9685[i], value);
	}

	delay(1000);
}
