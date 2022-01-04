#ifndef __RPIPLC_ARDUINO_H__
#define __RPIPLC_ARDUINO_H__

#include <stdint.h>

#define INPUT  0x0
#define OUTPUT 0x1

#ifdef __cplusplus
extern "C" {
#endif

	void initPins();

	void pinMode(uint32_t pin, uint8_t mode);
	void digitalWrite(uint32_t pin, int value);
	int digitalRead(uint32_t pin);
	void analogWrite(uint32_t pin, int value);
	uint16_t analogRead(uint32_t pin);

	void delay(uint32_t milliseconds);

	void digitalWriteAll(uint8_t addr, uint32_t values);
	uint32_t digitalReadAll(uint8_t addr);
	void analogWriteAll(uint8_t addr, const uint16_t* values);

#ifdef __cplusplus
}
#endif

#endif
