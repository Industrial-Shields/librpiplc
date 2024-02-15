#ifndef __PERIPHERAL_MCP23008_H__
#define __PERIPHERAL_MCP23008_H__

#include <stdint.h>
#include "i2c.h"

#define MCP23008_OUTPUT 0
#define MCP23008_INPUT 1

#ifdef __cplusplus
extern "C" {
#endif

	uint8_t mcp23008_init(i2c_t* i2c, uint8_t addr);
	uint8_t mcp23008_set_pin_mode(i2c_t* i2c, uint8_t addr, uint8_t index, uint8_t mode);
	uint8_t mcp23008_read(i2c_t* i2c, uint8_t addr, uint8_t index);
	uint8_t mcp23008_write(i2c_t* i2c, uint8_t addr, uint8_t index, uint8_t value);
	uint8_t mcp23008_read_all(i2c_t* i2c, uint8_t addr);
	uint8_t mcp23008_write_all(i2c_t* i2c, uint8_t addr, uint8_t value);

#ifdef __cplusplus
}
#endif


#endif
