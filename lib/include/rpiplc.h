#ifndef __RPIPLC_H__
#define __RPIPLC_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "rpiplc-peripherals.h"

#include "rpiplc-version.h"

#ifndef DONT_IMPORT_MAPPING
#include "rpiplc-mapping.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __ARDUINO_FUNCTIONS__
	int argc;
	const char** argv;

	void setup();
	void loop();

	int main(int _argc, const char** _argv) {
		argc = _argc; argv = _argv;

	        initPins();

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
