#include <rpiplc.h>

int counter = 0;

void setup() {

}

void loop() {
	printf("%d\n", counter++);
	delay(1000);
}
