#ifndef __RPIPLC_H__
#define __RPIPLC_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "rpiplc-peripherals.h"

#include "rpiplc-version.h"

#ifndef DONT_IMPORT_MAPPING
#include "rpiplc-mapping.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __ARDUINO_FUNCTIONS__

	/**
	 * @brief Main function for Arduino compatibility.
	 *
	 * This function initializes the program by calling the "setup" function
	 * provided by the user, then enters a continuous loop calling the "loop"
	 * function repeatedly. It is meant to mimic the behavior of Arduino
	 * sketches.
	 *
	 * In order to use it, you need to define "__ARDUINO_FUNCTIONS__" macro
	 * BEFORE including <rpiplc.h>.
	 *
	 * Since we are in a Linux system, both argc and argv are also provided
	 * to give the possibility of reading arguments given in the shell.
	 *
	 *
	 * @return Always returns 1 (it should never happen, as the while cannot
	 *         be exited).
	 */
	int argc;
	const char** argv;

	void setup();
	void loop();

	int main(int _argc, const char** _argv) {
		argc = _argc; argv = _argv;

		int __attribute__((unused)) _returnInitExpandedGPIO_ = initExpandedGPIO(false);
		assert(_returnInitExpandedGPIO_ == 0);

	        setup();

                while (true) {
	                loop();
                }

                return 1;
        }
#endif // __ARDUINO_FUNCTIONS__


#ifdef __cplusplus
}
#endif


#endif // __RPIPLC_H__
