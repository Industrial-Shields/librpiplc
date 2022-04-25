#include <unistd.h>
#include <stdio.h>

#include "rpiplc-arduino.h"
#include "ltc2309.h"

// Registers
#define SD_SINGLE 0x80
#define SD_DIFF   0x00
#define OS_ODD    0x40
#define OS_SIGN   0x00
#define S_CH0     0x00
#define S_CH1     0x00
#define S_CH2     0x01
#define S_CH3     0x01
#define S_CH4     0x02
#define S_CH5     0x02
#define S_CH6     0x03
#define S_CH7     0x03
#define SO_UNIP   0x00

#define	CH0 0b10001000
#define	CH1 0b11001000
#define	CH2 0b10011000
#define	CH3 0b11011000
#define	CH4 0b10101000
#define	CH5 0b11101000
#define	CH6 0b10111000
#define CH7 0b11111000


int ltc2309_init(i2c_t* i2c, uint8_t addr) {
	return 1;
}

uint16_t ltc2309_read(i2c_t* i2c, uint8_t addr, uint8_t index) {
	uint8_t mux = 0;
	switch (index) {
		case 0:
			mux = CH0;
			break;
		case 1:
			mux = CH1;
			break;
		case 2:
			mux = CH2;
			break;
		case 3:
			mux = CH3;
			break;
		case 4:
			mux = CH4;
			break;
		case 5:
			mux = CH5;
			break;
		case 6:
			mux = CH6;
			break;
		case 7:
			mux = CH7;
			break;

//		case 0:
//			mux = SD_SINGLE | OS_SIGN | S_CH0 | SO_UNIP;
//			break;
//		case 1:
//			mux = SD_SINGLE | OS_ODD | S_CH1 | SO_UNIP;
//			break;
//
//		case 2:
//			mux = SD_SINGLE | OS_SIGN | S_CH2 | SO_UNIP;
//			break;
//
//		case 3:
//			mux = SD_SINGLE | OS_ODD | S_CH3 | SO_UNIP ;
//			break;
//
//		case 4:
//			mux = SD_SINGLE | OS_SIGN | S_CH4 | SO_UNIP;
//			break;
//
//		case 5:
//			mux = SD_SINGLE | OS_ODD | S_CH5 | SO_UNIP;
//			break;
//
//		case 6:
//			mux = SD_SINGLE | OS_SIGN | S_CH6 | SO_UNIP;
//			break;
//
//		case 7:
//			mux = SD_SINGLE | OS_ODD | S_CH7 | SO_UNIP;
//			break;
	}

	if (i2c_write(i2c, addr, &mux, 1) != 1) {
		return 0;
	}

	delayMicroseconds(10);

	uint8_t buffer[2];

	if (i2c_read(i2c, addr, mux, buffer, 2) != 2) {
		return 0;
	}

	uint16_t res = (uint16_t)((uint16_t)(buffer[0]<<4)+(uint16_t)(buffer[1]>>4));
	return res;
}
