#include <rpiplc.h>

int counter = 0;

void setup() {

}

void loop() {
	printf("%d\n", counter++);
	delay(1000);
}

int main(int argc, char* argv[]) {
	initPins();

	setup();

	while (1) {
		loop();
	}

	return 0;
}
