#include <rpiplc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	initPins();

	int pin = A0_5;
	int value = 256;

	if (argc >= 2) {
		pin = atoi(argv[1]);
	}
	if (argc >= 3) {
		value = atoi(argv[2]);
	}

	printf("Set pin %08x to %d\n", pin, value);
	analogWrite(pin, value);

	return 0;
}
