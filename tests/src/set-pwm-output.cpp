#include <cstdint>
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

#include <rpiplc.h>

#include "pins-references.hpp"
#include "find-pin.hpp"



int main(int argc, const char* argv[]) {
	if (argc != 3 && argc != 4) {
		fprintf(stderr, "Usage: %s <io-name> <value> OPTIONAL_PWM_FREQ\n", argv[0]);
		return -2;
	}

	int value_to_write;
        try {
		value_to_write = stoi(argv[2]);
	}
	catch (const exception& e) {
		fprintf(stderr, "Error: %s\n", e.what());
		return -3;
	}

	if (value_to_write < 0 || value_to_write > 4095) {
		fprintf(stderr, "Out of range: %d\n", value_to_write);
		return -4;
	}

	int64_t pwm_freq;
	if (argc == 4) {
		try {
			pwm_freq = stoi(argv[3]);
		}
		catch (const exception& e) {
			fprintf(stderr, "Error: %s\n", e.what());
			return -5;
		}
	}
	else {
		pwm_freq = -1;
	}

	const pin_name_t* pin = find_pin<namedPWMOutputs, numNamedPWMOutputs>(argv[1]);

	if (pin != nullptr) {
		int ret;
		ret = initExpandedGPIO(false);
		if (ret != 0) {
			PERROR_WITH_LINE("initExpandedGPIO fail");
			exit(-1);
		}

		ret = pinMode(pin->pin, OUTPUT);
		if (ret != 0) {
			PERROR_WITH_LINE("pinMode fail");
			exit(-1);
		}

		if (pwm_freq != -1) {
			ret = analogWriteSetFrequency(pin->pin, pwm_freq);
			if (ret != 0) {
				if (errno == ERANGE) {
					fprintf(stderr, "PWM frequency not valid\n");
					return -6;
				}
				else {
					PERROR_WITH_LINE("analogWriteSetFrequency fail");
					exit(-1);
				}
			}
		}

		ret = analogWrite(pin->pin, value_to_write);
		ret = pinMode(pin->pin, OUTPUT);
		if (ret != 0) {
			PERROR_WITH_LINE("analogWrite fail");
			exit(-1);
		}

		printf("Pin %s set at %d\n", pin->name, value_to_write);
		return 0;
	}
	else {
		fprintf(stderr, "\"%s\" is an unknown pin\n", argv[1]);
		return -1;
	}
}
