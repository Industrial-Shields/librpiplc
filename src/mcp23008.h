#ifndef __PERIPHERAL_MCP23008_H__
#define __PERIPHERAL_MCP23008_H__

#include <stdint.h>

#include "i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

int mcp23008_init(i2c_t* i2c, uint8_t addr);
uint8_t mcp23008_read(i2c_t* i2c, uint8_t addr, uint8_t index);

#ifdef __cplusplus
}
#endif

#endif
