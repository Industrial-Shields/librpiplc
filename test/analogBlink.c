#include <rpiplc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const static uint16_t values[] = {0, 511, 1023, 2047, 4095, 2047, 1023, 511};
const static int numValues = sizeof(values) / sizeof(uint16_t);

int main(int argc, char* argv[]) {
	initPins();

	int pin = A0_5;
	int value = 1023;

	while (1) {
		for (int i = 0; i < numValues; ++i) {
			printf("Set value %d\n", values[i]);
			analogWrite(pin, values[i]);
			sleep(1);
		}
	}

	return 0;
}
