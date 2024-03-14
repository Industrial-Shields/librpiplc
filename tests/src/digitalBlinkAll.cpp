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
		pinMode(digitalOutputs[i], OUTPUT);
	}
}

void loop() {
	value = value == 0 ? 0xFFFFFFFF : 0;

	printf("Set value 0x%0X\n", value);

	for (size_t i = 0; i < NUM_MCP23008; i++) {
		int i2c_ret = digitalWriteAll(MCP23008[i], value);
		if (i2c_ret != 0) {
		        perror("MCP ERROR");
		}
	}
	for (size_t i = 0; i < NUM_PCA9685; i++) {
		digitalWriteAll(PCA9685[i], value);
	}

	delay(1000);
}
