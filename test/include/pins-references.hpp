#ifndef __PINS_REFERENCES_H__
#define __PINS_REFERENCES_H__

#include <cstdint>
#include <rpiplc.h>

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
