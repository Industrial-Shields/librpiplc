#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int fd;
} i2c_t;

int i2cInit(i2c_t* i2c, uint8_t bus);
void i2cDeinit(i2c_t* i2c);
size_t i2cWrite(i2c_t* i2c, uint8_t addr, const void* buff, size_t len);
size_t i2cRead(i2c_t* i2c, uint8_t addr, uint8_t reg, void* buff, size_t len);

#ifdef __cplusplus
}
#endif

#endif
