#include <rpiplc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	initPins();

	int pin = Q0_0;
	int value = 1;

	while (1) {
		printf("Set value %d\n", value);
		digitalWrite(pin, value);
		sleep(1);

		value = value == 0 ? 1 : 0;
	}

	return 0;
}
