#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

uint32_t value = 0xFFFFFFFF;

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
	value = value == 0 ? 0xFFFFFFFF : 0;

	printf("Set value 0x%0X\n", value);

	int ret;
	for (size_t i = 0; i < NUM_MCP23008; i++) {
		ret = digitalWriteAll(MCP23008[i], value);
		if (ret != 0) {
			PERROR_WITH_LINE("digitalWriteAll fail");
			exit(-1);
		}
	}
	for (size_t i = 0; i < NUM_PCA9685; i++) {
		ret = digitalWriteAll(PCA9685[i], value);
		if (ret != 0) {
			PERROR_WITH_LINE("digitalWriteAll fail");
			exit(-1);
		}
	}

	delay(1000);
}
