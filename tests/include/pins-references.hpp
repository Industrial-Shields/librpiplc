#ifndef __PINS_REFERENCES_H__
#define __PINS_REFERENCES_H__

#include <cstdint>
#include <rpiplc.h>

#define __PERROR_WITH_LINE_STRINGIFY_HELPER(x) #x
#define __PERROR_WITH_LINE_STRINGIFY(x) __PERROR_WITH_LINE_STRINGIFY_HELPER(x)
#define PERROR_WITH_LINE(msg) perror(msg " in line " __PERROR_WITH_LINE_STRINGIFY(__LINE__))

typedef struct {
        const char* name;
        uint32_t pin;
} pin_name_t;

#if defined(RPIPLC_V5)
#include "pins-references-v5.hpp"

#elif defined(RPIPLC_V4)
#include "pins-references-v4.hpp"

#elif defined(RPIPLC_V3)
#include "pins-references-v3.hpp"

#else
#error "No selected PLC version"
#endif

#endif // __PINS_REFERENCES_H__
