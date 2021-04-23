#ifndef __RPIPLC_H__
#define __RPIPLC_H__

#include "rpiplc-mapping.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void initPins();
void analogWrite(uint32_t pin, int value);

#ifdef __cplusplus
}
#endif

#endif
