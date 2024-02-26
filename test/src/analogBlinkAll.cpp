#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins_references.hpp"

const static uint16_t values[] = {0, 511, 1023, 2047, 4095, 2047, 1023, 511};
const static int numValues = sizeof(values) / sizeof(uint16_t);

void setup() {
  	printf("Number of analog outputs: %zu\n", numAnalogOutputs);

	for (size_t i = 0; i < numAnalogOutputs; i++) {
		pinMode(analogOutputs[i], OUTPUT);
	}
}

void loop() {
	for (size_t i = 0; i < numValues; i++) {
		printf("Set value %d\n", values[i]);

		uint16_t analogValues[PCA9685_NUM_OUTPUTS];
		for (size_t j = 0; j < PCA9685_NUM_OUTPUTS; j++) {
			analogValues[j] = values[i];
		}
		for (ssize_t j = 0; j < rpiplc_num_pca9685; j++) {
			analogWriteAll(rpiplc_pca9685[j], analogValues);
		}

		delay(1000);
	}
}
