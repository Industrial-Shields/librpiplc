#ifndef __RPIPLC_MAPPING_H__
#define __RPIPLC_MAPPING_H__

#include <stdint.h>

// TODO remap

#define PIN_Q0_0 0x00004000
#define PIN_Q0_0 0x00004000
#define PIN_Q0_1 0x00004001
#define PIN_Q0_2 0x00004002
#define PIN_Q0_3 0x00004003
#define PIN_Q0_4 0x00004004
#define PIN_Q0_5 0x00004005
#define PIN_Q0_6 0x00004006
#define PIN_Q0_7 0x00004007

static const uint32_t Q0_1 = PIN_Q0_1;
static const uint32_t Q0_2 = PIN_Q0_2;
static const uint32_t Q0_3 = PIN_Q0_3;
static const uint32_t Q0_4 = PIN_Q0_4;
static const uint32_t Q0_5 = PIN_Q0_5;
static const uint32_t Q0_6 = PIN_Q0_6;
static const uint32_t Q0_7 = PIN_Q0_7;

static const uint32_t A0_5 = PIN_Q0_5;
static const uint32_t A0_6 = PIN_Q0_6;
static const uint32_t A0_7 = PIN_Q0_7;

#define PIN_Q1_0 0x00004008
#define PIN_Q1_1 0x00004009
#define PIN_Q1_2 0x0000400a
#define PIN_Q1_3 0x0000400b
#define PIN_Q1_4 0x0000400c
#define PIN_Q1_5 0x0000400d
#define PIN_Q1_6 0x0000400e
#define PIN_Q1_7 0x0000400f

static const uint32_t Q1_0 = PIN_Q1_0;
static const uint32_t Q1_1 = PIN_Q1_1;
static const uint32_t Q1_2 = PIN_Q1_2;
static const uint32_t Q1_3 = PIN_Q1_3;
static const uint32_t Q1_4 = PIN_Q1_4;
static const uint32_t Q1_5 = PIN_Q1_5;
static const uint32_t Q1_6 = PIN_Q1_6;
static const uint32_t Q1_7 = PIN_Q1_7;

static const uint32_t A1_5 = PIN_Q1_5;
static const uint32_t A1_6 = PIN_Q1_6;
static const uint32_t A1_7 = PIN_Q1_7;

#define PIN_Q2_0 0x00004100
#define PIN_Q2_1 0x00004101
#define PIN_Q2_2 0x00004102
#define PIN_Q2_3 0x00004103
#define PIN_Q2_4 0x00004104
#define PIN_Q2_5 0x00004105
#define PIN_Q2_6 0x00004106
#define PIN_Q2_7 0x00004107

static const uint32_t Q2_0 = PIN_Q2_0;
static const uint32_t Q2_1 = PIN_Q2_1;
static const uint32_t Q2_2 = PIN_Q2_2;
static const uint32_t Q2_3 = PIN_Q2_3;
static const uint32_t Q2_4 = PIN_Q2_4;
static const uint32_t Q2_5 = PIN_Q2_5;
static const uint32_t Q2_6 = PIN_Q2_6;
static const uint32_t Q2_7 = PIN_Q2_7;

static const uint32_t A2_5 = PIN_Q2_5;
static const uint32_t A2_6 = PIN_Q2_6;
static const uint32_t A2_7 = PIN_Q2_7;

static const uint8_t pca9685Addresses[] = {
	0x40,
	0x41,
};
#define NUM_PCA9685_DEVICES (sizeof(pca9685Addresses) / sizeof(uint8_t))

#define pinToDeviceAddress(pin) (((pin) >> 8) & 0xff)
#define pinToDeviceIndex(pin) ((pin) & 0xff)

#endif
