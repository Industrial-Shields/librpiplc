#include <rpiplc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	initPins();

	int pin = I0_0;

	int value = digitalRead(pin);
	printf("Pin %08x value: %u\n", pin, value);

	return 0;
}
