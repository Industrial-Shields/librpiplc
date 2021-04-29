#ifndef __RPIPLC_H__
#define __RPIPLC_H__

#include "rpiplc-mapping.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void initPins();

void digitalWrite(uint32_t pin, int value);
int digitalRead(uint32_t pin);
void analogWrite(uint32_t pin, int value);
uint16_t analogRead(uint32_t pin);

#ifdef __cplusplus
}
#endif

#endif
