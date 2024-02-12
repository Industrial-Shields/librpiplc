#ifndef __RPIPLC_MAPPING_H__
#error "Not importing from rpiplc-mapping.h"
#endif


#include <stdint.h>

#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
#define PIN_I0_0	0x00002105
#define PIN_I0_1	0x00002103
#define PIN_I0_2	0x00002102
#define PIN_I0_3	0x00002101
#define PIN_I0_4	0x00002100
#define PIN_I0_5	13
#define PIN_I0_6	12
#define PIN_I0_7	0x00004a00
#define PIN_I0_8	0x00004a01
#define PIN_I0_9	0x00004b00
#define PIN_I0_10	0x00004802
#define PIN_I0_11	0x00004800
#define PIN_I0_12	0x00004801

static const uint32_t I0_0 = PIN_I0_0;
static const uint32_t I0_1 = PIN_I0_1;
static const uint32_t I0_2 = PIN_I0_2;
static const uint32_t I0_3 = PIN_I0_3;
static const uint32_t I0_4 = PIN_I0_4;
static const uint32_t I0_5 = PIN_I0_5;
static const uint32_t I0_6 = PIN_I0_6;
static const uint32_t I0_7 = PIN_I0_7;
static const uint32_t I0_8 = PIN_I0_8;
static const uint32_t I0_9 = PIN_I0_9;
static const uint32_t I0_10 = PIN_I0_10;
static const uint32_t I0_11 = PIN_I0_11;
static const uint32_t I0_12 = PIN_I0_12;

#define PIN_Q0_0	0x0000400f
#define PIN_Q0_1	0x0000400e
#define PIN_Q0_2	0x0000400d
#define PIN_Q0_3	0x0000400c
#define PIN_Q0_4	0x0000400b
#define PIN_Q0_5	0x0000400a
#define PIN_Q0_6	0x00004001
#define PIN_Q0_7	0x00004000

static const uint32_t Q0_0 = PIN_Q0_0;
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

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
#define PIN_I0_0	13
#define PIN_I0_1	12
#define PIN_I0_2	0x00004a00
#define PIN_I0_3	0x00004a01
#define PIN_I0_4	0x00004b00
#define PIN_I0_5	0x00004802

static const uint32_t I0_0 = PIN_I0_0;
static const uint32_t I0_1 = PIN_I0_1;
static const uint32_t I0_2 = PIN_I0_2;
static const uint32_t I0_3 = PIN_I0_3;
static const uint32_t I0_4 = PIN_I0_4;
static const uint32_t I0_5 = PIN_I0_5;

#define PIN_Q0_0	0x0000400a
#define PIN_Q0_1	0x00004001
#define PIN_Q0_2	0x00004000

static const uint32_t Q0_0 = PIN_Q0_0;
static const uint32_t Q0_1 = PIN_Q0_1;
static const uint32_t Q0_2 = PIN_Q0_2;

static const uint32_t A0_0 = PIN_Q0_0;
static const uint32_t A0_1 = PIN_Q0_1;
static const uint32_t A0_2 = PIN_Q0_2;

#define PIN_R0_1	0x00002103
#define PIN_R0_2	0x00002105
#define PIN_R0_3	0x00002101
#define PIN_R0_4	0x00002102
#define PIN_R0_5	0x0000400b
#define PIN_R0_6	0x0000400c
#define PIN_R0_7	0x0000400d
#define PIN_R0_8	0x0000400e

static const uint32_t R0_1 = PIN_R0_1;
static const uint32_t R0_2 = PIN_R0_2;
static const uint32_t R0_3 = PIN_R0_3;
static const uint32_t R0_4 = PIN_R0_4;
static const uint32_t R0_5 = PIN_R0_5;
static const uint32_t R0_6 = PIN_R0_6;
static const uint32_t R0_7 = PIN_R0_7;
static const uint32_t R0_8 = PIN_R0_8;

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
#define PIN_I1_0	0x00002002
#define PIN_I1_1	0x00002001
#define PIN_I1_2	0x00002000
#define PIN_I1_3	0x00002107
#define PIN_I1_4	0x00002106
#define PIN_I1_5	27
#define PIN_I1_6	4
#define PIN_I1_7	0x00004900
#define PIN_I1_8	0x00004a03
#define PIN_I1_9	0x00004b02
#define PIN_I1_10	0x00004b03
#define PIN_I1_11	0x00004a02
#define PIN_I1_12	0x00004901

static const uint32_t I1_0 = PIN_I1_0;
static const uint32_t I1_1 = PIN_I1_1;
static const uint32_t I1_2 = PIN_I1_2;
static const uint32_t I1_3 = PIN_I1_3;
static const uint32_t I1_4 = PIN_I1_4;
static const uint32_t I1_5 = PIN_I1_5;
static const uint32_t I1_6 = PIN_I1_6;
static const uint32_t I1_7 = PIN_I1_7;
static const uint32_t I1_8 = PIN_I1_8;
static const uint32_t I1_9 = PIN_I1_9;
static const uint32_t I1_10 = PIN_I1_10;
static const uint32_t I1_11 = PIN_I1_11;
static const uint32_t I1_12 = PIN_I1_12;

#define PIN_Q1_0	0x00004002
#define PIN_Q1_1	0x00004009
#define PIN_Q1_2	0x00004006
#define PIN_Q1_3	0x00004004
#define PIN_Q1_4	0x00004007
#define PIN_Q1_5	0x00004003
#define PIN_Q1_6	0x00004005
#define PIN_Q1_7	0x00004008

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

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
#define PIN_I1_0	27
#define PIN_I1_1	4
#define PIN_I1_2	0x00004900
#define PIN_I1_3	0x00004a03
#define PIN_I1_4	0x00004b02
#define PIN_I1_5	0x00004b03

static const uint32_t I1_0 = PIN_I1_0;
static const uint32_t I1_1 = PIN_I1_1;
static const uint32_t I1_2 = PIN_I1_2;
static const uint32_t I1_3 = PIN_I1_3;
static const uint32_t I1_4 = PIN_I1_4;
static const uint32_t I1_5 = PIN_I1_5;

#define PIN_Q1_0	0x00004003
#define PIN_Q1_1	0x00004005
#define PIN_Q1_2	0x00004008

static const uint32_t Q1_0 = PIN_Q1_0;
static const uint32_t Q1_1 = PIN_Q1_1;
static const uint32_t Q1_2 = PIN_Q1_2;

static const uint32_t A1_0 = PIN_Q1_0;
static const uint32_t A1_1 = PIN_Q1_1;
static const uint32_t A1_2 = PIN_Q1_2;

#define PIN_R1_1	0x00002001
#define PIN_R1_2	0x00002002
#define PIN_R1_3	0x00002107
#define PIN_R1_4	0x00002000
#define PIN_R1_5	0x00004007
#define PIN_R1_6	0x00004004
#define PIN_R1_7	0x00004006
#define PIN_R1_8	0x00004009

static const uint32_t R1_1 = PIN_R1_1;
static const uint32_t R1_2 = PIN_R1_2;
static const uint32_t R1_3 = PIN_R1_3;
static const uint32_t R1_4 = PIN_R1_4;
static const uint32_t R1_5 = PIN_R1_5;
static const uint32_t R1_6 = PIN_R1_6;
static const uint32_t R1_7 = PIN_R1_7;
static const uint32_t R1_8 = PIN_R1_8;

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
#define PIN_I2_0	0x00002006
#define PIN_I2_1	0x00002005
#define PIN_I2_2	0x00002007
#define PIN_I2_3	0x00002004
#define PIN_I2_4	0x00002003
#define PIN_I2_5	17
#define PIN_I2_6	16
#define PIN_I2_7	0x00004903
#define PIN_I2_8	0x00004902
#define PIN_I2_9	0x00004803
#define PIN_I2_10	0x00004b01

static const uint32_t I2_0 = PIN_I2_0;
static const uint32_t I2_1 = PIN_I2_1;
static const uint32_t I2_2 = PIN_I2_2;
static const uint32_t I2_3 = PIN_I2_3;
static const uint32_t I2_4 = PIN_I2_4;
static const uint32_t I2_5 = PIN_I2_5;
static const uint32_t I2_6 = PIN_I2_6;
static const uint32_t I2_7 = PIN_I2_7;
static const uint32_t I2_8 = PIN_I2_8;
static const uint32_t I2_9 = PIN_I2_9;
static const uint32_t I2_10 = PIN_I2_10;

#define PIN_Q2_0	0x00004106
#define PIN_Q2_1	0x00004107
#define PIN_Q2_2	0x00004105
#define PIN_Q2_3	0x00004104
#define PIN_Q2_4	0x00004103
#define PIN_Q2_5	0x00004102
#define PIN_Q2_6	0x00004101
#define PIN_Q2_7	0x00004100

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

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
#define PIN_I2_0	17
#define PIN_I2_1	16
#define PIN_I2_2	0x00004903
#define PIN_I2_3	0x00004902
#define PIN_I2_4	0x00004803
#define PIN_I2_5	0x00004b01

static const uint32_t I2_0 = PIN_I2_0;
static const uint32_t I2_1 = PIN_I2_1;
static const uint32_t I2_2 = PIN_I2_2;
static const uint32_t I2_3 = PIN_I2_3;
static const uint32_t I2_4 = PIN_I2_4;
static const uint32_t I2_5 = PIN_I2_5;

#define PIN_Q2_0	0x00004102
#define PIN_Q2_1	0x00004101
#define PIN_Q2_2	0x00004100

static const uint32_t Q2_0 = PIN_Q2_0;
static const uint32_t Q2_1 = PIN_Q2_1;
static const uint32_t Q2_2 = PIN_Q2_2;

static const uint32_t A2_0 = PIN_Q2_0;
static const uint32_t A2_1 = PIN_Q2_1;
static const uint32_t A2_2 = PIN_Q2_2;

#define PIN_R2_1	0x00002005
#define PIN_R2_2	0x00002006
#define PIN_R2_3	0x00002004
#define PIN_R2_4	0x00002007
#define PIN_R2_5	0x00004103
#define PIN_R2_6	0x00004104
#define PIN_R2_7	0x00004105
#define PIN_R2_8	0x00004107

static const uint32_t R2_1 = PIN_R2_1;
static const uint32_t R2_2 = PIN_R2_2;
static const uint32_t R2_3 = PIN_R2_3;
static const uint32_t R2_4 = PIN_R2_4;
static const uint32_t R2_5 = PIN_R2_5;
static const uint32_t R2_6 = PIN_R2_6;
static const uint32_t R2_7 = PIN_R2_7;
static const uint32_t R2_8 = PIN_R2_8;

#endif
