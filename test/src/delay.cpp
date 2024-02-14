#include <cstdint>
#include <cstddef>
#include <cstdio>

#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>

int counter = 0;

void setup() {}

void loop() {
	printf("%d\n", counter++);
	delay(1000);
}
