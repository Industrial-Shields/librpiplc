#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

#include "pins-references.hpp"

const static uint16_t values[] = {0, 511, 1023, 2047, 4095, 2047, 1023, 511};
const static int numValues = sizeof(values) / sizeof(uint16_t);

void setup() {
  	printf("Number of analog outputs: %zu\n", numAnalogOutputs);

	for (size_t i = 0; i < numAnalogOutputs; i++) {
		int ret = pinMode(analogOutputs[i], OUTPUT);
		if (ret != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}
	}
}

static bool is_output_analog(uint8_t addr, uint8_t index) {
	uint32_t pin = ((addr << 8) | index);
	for (size_t c = 0; c < numAnalogOutputs; c++) {
		if (pin == analogOutputs[c]) {
			return true;
		}
	}

	return false;
}

void loop() {
	for (size_t val = 0; val < numValues; val++) {
		printf("Set value %d\n", values[val]);

		for (size_t pca = 0; pca < NUM_PCA9685; pca++) {
			uint16_t analogValues[PCA9685_NUM_OUTPUTS];
			for (size_t ch = 0; ch < PCA9685_NUM_OUTPUTS; ch++) {
				if (is_output_analog(PCA9685[pca], ch)) {
					analogValues[ch] = values[val];
				}
				else {
					analogValues[ch] = 0;
				}
			}
			int ret = analogWriteAll(PCA9685[pca], analogValues);
		        if (ret != 0) {
				PERROR_WITH_LINE("analogWrite fail");
				exit(-1);
			}
		}

		delay(1000);
	}
}
