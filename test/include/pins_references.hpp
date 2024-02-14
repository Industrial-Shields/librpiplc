#ifndef __PINS_REFERENCES_H__
#define __PINS_REFERENCES_H__

#include <cstdint>
#include <rpiplc.h>

typedef struct {
        const char* name;
        uint32_t pin;
} pin_name_t;


#if defined(RPIPLC_V3)
#include "pins_references_v3.hpp"
#elif defined(RPIPLC_V4)
#include "pins_references_v4.hpp"
#endif

#endif // __PINS_REFERENCES_H__
