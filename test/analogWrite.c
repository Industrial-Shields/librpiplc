#include <rpiplc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	initPins();

	int pin = A0_5;
	int value = 1023;

	if (argc >= 2) {
		value = atoi(argv[2]);
	}

	printf("Set pin %08x to %d\n", pin, value);
	analogWrite(pin, value);

	return 0;
}
