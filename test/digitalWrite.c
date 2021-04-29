#include <rpiplc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	initPins();

	int pin = Q0_0;
	int value = 1;

	if (argc > 1) {
		value = atoi(argv[1]) ? 1 : 0;
	}

	printf("Set pin %08x to %d\n", pin, value);
	digitalWrite(pin, value);

	return 0;
}
