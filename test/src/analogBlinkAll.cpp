#include <rpiplc.h>

#include "pins_references.h"

const static uint16_t values[] = {0, 511, 1023, 2047, 4095, 2047, 1023, 511};
const static int numValues = sizeof(values) / sizeof(uint16_t);

uint16_t analogValues[16];

void setup() {
	for (int i = 0; i < numAnalogOutputs; ++i) {
		pinMode(analogOutputs[i], OUTPUT);
	}
}

void loop() {
	for (int i = 0; i < numValues; ++i) {
		printf("Set value %d\n", values[i]);

		for (int j = 0; j < PCA9685_NUM_OUTPUTS; ++j) {
			analogValues[j] = values[i];
		}
		for (int j = 0; j < rpiplc_num_pca9685; ++j) {
			analogWriteAll(rpiplc_pca9685[j], analogValues);
		}

		delay(1000);
	}
}

int main(int argc, char* argv[]) {
	initPins();

	setup();

	while (1) {
		loop();
	}

	return 0;
}
