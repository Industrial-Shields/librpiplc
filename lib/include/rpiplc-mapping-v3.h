/*
 * Copyright (c) 2024 Industrial Shields. All rights reserved
 *
 * This file is part of librpiplc.
 *
 * librpiplc is free software: you can redistribute
 * it and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either version
 * 3 of the License, or (at your option) any later version.
 *
 * librpiplc is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RPIPLC_MAPPING_H__
#error "Not importing from rpiplc-mapping.h"
#endif


#include <stdint.h>

#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
#define PIN_I0_0	MAKE_PIN_MCP23008(0x21, 0x05) //0x00002105
#define PIN_I0_1	MAKE_PIN_MCP23008(0x21, 0x03) //0x00002103
#define PIN_I0_2	MAKE_PIN_MCP23008(0x21, 0x02) //0x00002102
#define PIN_I0_3	MAKE_PIN_MCP23008(0x21, 0x01) //0x00002101
#define PIN_I0_4	MAKE_PIN_MCP23008(0x21, 0x00) //0x00002100
#define PIN_I0_5	MAKE_PIN_DIRECT(13)
#define PIN_I0_6	MAKE_PIN_DIRECT(12)
#define PIN_I0_7	MAKE_PIN_ADS1015(0x4a, 0x00) //0x00004a00
#define PIN_I0_8	MAKE_PIN_ADS1015(0x4a, 0x01) //0x00004a01
#define PIN_I0_9	MAKE_PIN_ADS1015(0x4b, 0x00) //0x00004b00
#define PIN_I0_10	MAKE_PIN_ADS1015(0x48, 0x02) //0x00004802
#define PIN_I0_11	MAKE_PIN_ADS1015(0x48, 0x00) //0x00004800
#define PIN_I0_12	MAKE_PIN_ADS1015(0x48, 0x01) //0x00004801

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

#define PIN_Q0_0	MAKE_PIN_PCA9685(0x40, 0x0f) //0x0000400f
#define PIN_Q0_1	MAKE_PIN_PCA9685(0x40, 0x0e) //0x0000400e
#define PIN_Q0_2	MAKE_PIN_PCA9685(0x40, 0x0d) //0x0000400d
#define PIN_Q0_3	MAKE_PIN_PCA9685(0x40, 0x0c) //0x0000400c
#define PIN_Q0_4	MAKE_PIN_PCA9685(0x40, 0x0b) //0x0000400b
#define PIN_Q0_5	MAKE_PIN_PCA9685(0x40, 0x0a) //0x0000400a
#define PIN_Q0_6	MAKE_PIN_PCA9685(0x40, 0x01) //0x00004001
#define PIN_Q0_7	MAKE_PIN_PCA9685(0x40, 0x00) //0x00004000

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
#define PIN_I0_0	MAKE_PIN_DIRECT(13)
#define PIN_I0_1	MAKE_PIN_DIRECT(12)
#define PIN_I0_2	MAKE_PIN_ADS1015(0x4a, 0x00) //0x00004a00
#define PIN_I0_3	MAKE_PIN_ADS1015(0x4a, 0x01) //0x00004a01
#define PIN_I0_4	MAKE_PIN_ADS1015(0x4b, 0x00) //0x00004b00
#define PIN_I0_5	MAKE_PIN_ADS1015(0x48, 0x02) //0x00004802

static const uint32_t I0_0 = PIN_I0_0;
static const uint32_t I0_1 = PIN_I0_1;
static const uint32_t I0_2 = PIN_I0_2;
static const uint32_t I0_3 = PIN_I0_3;
static const uint32_t I0_4 = PIN_I0_4;
static const uint32_t I0_5 = PIN_I0_5;

#define PIN_Q0_0	MAKE_PIN_PCA9685(0x40, 0x0a) //0x0000400a
#define PIN_Q0_1	MAKE_PIN_PCA9685(0x40, 0x01) //0x00004001
#define PIN_Q0_2	MAKE_PIN_PCA9685(0x40, 0x00) //0x00004000

static const uint32_t Q0_0 = PIN_Q0_0;
static const uint32_t Q0_1 = PIN_Q0_1;
static const uint32_t Q0_2 = PIN_Q0_2;

static const uint32_t A0_0 = PIN_Q0_0;
static const uint32_t A0_1 = PIN_Q0_1;
static const uint32_t A0_2 = PIN_Q0_2;

#define PIN_R0_1	MAKE_PIN_MCP23008(0x21, 0x03) //0x00002103
#define PIN_R0_2	MAKE_PIN_MCP23008(0x21, 0x05) //0x00002105
#define PIN_R0_3	MAKE_PIN_MCP23008(0x21, 0x01) //0x00002101
#define PIN_R0_4	MAKE_PIN_MCP23008(0x21, 0x02) //0x00002102
#define PIN_R0_5	MAKE_PIN_PCA9685(0x40, 0x0b) //0x0000400b
#define PIN_R0_6	MAKE_PIN_PCA9685(0x40, 0x0c) //0x0000400c
#define PIN_R0_7	MAKE_PIN_PCA9685(0x40, 0x0d) //0x0000400d
#define PIN_R0_8	MAKE_PIN_PCA9685(0x40, 0x0e) //0x0000400e

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
#define PIN_I1_0	MAKE_PIN_MCP23008(0x20, 0x02) //0x00002002
#define PIN_I1_1	MAKE_PIN_MCP23008(0x20, 0x01) //0x00002001
#define PIN_I1_2	MAKE_PIN_MCP23008(0x20, 0x00) //0x00002000
#define PIN_I1_3	MAKE_PIN_MCP23008(0x21, 0x07) //0x00002107
#define PIN_I1_4	MAKE_PIN_MCP23008(0x21, 0x06) //0x00002106
#define PIN_I1_5	MAKE_PIN_DIRECT(27)
#define PIN_I1_6	MAKE_PIN_DIRECT(4)
#define PIN_I1_7	MAKE_PIN_ADS1015(0x49, 0x00) //0x00004900
#define PIN_I1_8	MAKE_PIN_ADS1015(0x4a, 0x03) //0x00004a03
#define PIN_I1_9	MAKE_PIN_ADS1015(0x4b, 0x02) //0x00004b02
#define PIN_I1_10	MAKE_PIN_ADS1015(0x4b, 0x03) //0x00004b03
#define PIN_I1_11	MAKE_PIN_ADS1015(0x4a, 0x02) //0x00004a02
#define PIN_I1_12	MAKE_PIN_ADS1015(0x49, 0x01) //0x00004901

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

#define PIN_Q1_0	MAKE_PIN_PCA9685(0x40, 0x02) //0x00004002
#define PIN_Q1_1	MAKE_PIN_PCA9685(0x40, 0x09) //0x00004009
#define PIN_Q1_2	MAKE_PIN_PCA9685(0x40, 0x06) //0x00004006
#define PIN_Q1_3	MAKE_PIN_PCA9685(0x40, 0x04) //0x00004004
#define PIN_Q1_4	MAKE_PIN_PCA9685(0x40, 0x07) //0x00004007
#define PIN_Q1_5	MAKE_PIN_PCA9685(0x40, 0x03) //0x00004003
#define PIN_Q1_6	MAKE_PIN_PCA9685(0x40, 0x05) //0x00004005
#define PIN_Q1_7	MAKE_PIN_PCA9685(0x40, 0x08) //0x00004008

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
#define PIN_I1_0	MAKE_PIN_DIRECT(27)
#define PIN_I1_1	MAKE_PIN_DIRECT(4)
#define PIN_I1_2	MAKE_PIN_ADS1015(0x49, 0x00) //0x00004900
#define PIN_I1_3	MAKE_PIN_ADS1015(0x4a, 0x03) //0x00004a03
#define PIN_I1_4	MAKE_PIN_ADS1015(0x4b, 0x02) //0x00004b02
#define PIN_I1_5	MAKE_PIN_ADS1015(0x4b, 0x03) //0x00004b03

static const uint32_t I1_0 = PIN_I1_0;
static const uint32_t I1_1 = PIN_I1_1;
static const uint32_t I1_2 = PIN_I1_2;
static const uint32_t I1_3 = PIN_I1_3;
static const uint32_t I1_4 = PIN_I1_4;
static const uint32_t I1_5 = PIN_I1_5;

#define PIN_Q1_0	MAKE_PIN_PCA9685(0x40, 0x03) //0x00004003
#define PIN_Q1_1	MAKE_PIN_PCA9685(0x40, 0x05) //0x00004005
#define PIN_Q1_2	MAKE_PIN_PCA9685(0x40, 0x08) //0x00004008

static const uint32_t Q1_0 = PIN_Q1_0;
static const uint32_t Q1_1 = PIN_Q1_1;
static const uint32_t Q1_2 = PIN_Q1_2;

static const uint32_t A1_0 = PIN_Q1_0;
static const uint32_t A1_1 = PIN_Q1_1;
static const uint32_t A1_2 = PIN_Q1_2;

#define PIN_R1_1	MAKE_PIN_MCP23008(0x20,0x01) //0x00002001
#define PIN_R1_2	MAKE_PIN_MCP23008(0x20, 0x02) //0x00002002
#define PIN_R1_3	MAKE_PIN_MCP23008(0x21, 0x07) //0x00002107
#define PIN_R1_4	MAKE_PIN_MCP23008(0x20, 0x00) //0x00002000
#define PIN_R1_5	MAKE_PIN_PCA9685(0x40, 0x07) //0x00004007
#define PIN_R1_6	MAKE_PIN_PCA9685(0x40, 0x04) //0x00004004
#define PIN_R1_7	MAKE_PIN_PCA9685(0x40, 0x06) //0x00004006
#define PIN_R1_8	MAKE_PIN_PCA9685(0x40, 0x09) //0x00004009

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
#define PIN_I2_0	MAKE_PIN_MCP23008(0x20, 0x06) //0x00002006
#define PIN_I2_1	MAKE_PIN_MCP23008(0x20, 0x05) //0x00002005
#define PIN_I2_2	MAKE_PIN_MCP23008(0x20, 0x07) //0x00002007
#define PIN_I2_3	MAKE_PIN_MCP23008(0x20, 0x04) //0x00002004
#define PIN_I2_4	MAKE_PIN_MCP23008(0x20, 0x03) //0x00002003
#define PIN_I2_5	MAKE_PIN_DIRECT(17)
#define PIN_I2_6	MAKE_PIN_DIRECT(16)
#define PIN_I2_7	MAKE_PIN_ADS1015(0x49, 0x03) //0x00004903
#define PIN_I2_8	MAKE_PIN_ADS1015(0x49, 0x02) //0x00004902
#define PIN_I2_9	MAKE_PIN_ADS1015(0x48, 0x03) //0x00004803
#define PIN_I2_10	MAKE_PIN_ADS1015(0x4b, 0x01) //0x00004b01

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

#define PIN_Q2_0	MAKE_PIN_PCA9685(0x41, 0x06) //0x00004106
#define PIN_Q2_1	MAKE_PIN_PCA9685(0x41, 0x07) //0x00004107
#define PIN_Q2_2	MAKE_PIN_PCA9685(0x41, 0x05) //0x00004105
#define PIN_Q2_3	MAKE_PIN_PCA9685(0x41, 0x04) //0x00004104
#define PIN_Q2_4	MAKE_PIN_PCA9685(0x41, 0x03) //0x00004103
#define PIN_Q2_5	MAKE_PIN_PCA9685(0x41, 0x02) //0x00004102
#define PIN_Q2_6	MAKE_PIN_PCA9685(0x41, 0x01) //0x00004101
#define PIN_Q2_7	MAKE_PIN_PCA9685(0x41, 0x00) //0x00004100

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
#define PIN_I2_0	MAKE_PIN_DIRECT(17)
#define PIN_I2_1	MAKE_PIN_DIRECT(16)
#define PIN_I2_2	MAKE_PIN_ADS1015(0x49, 0x03) //0x00004903
#define PIN_I2_3	MAKE_PIN_ADS1015(0x49, 0x02) //0x00004902
#define PIN_I2_4	MAKE_PIN_ADS1015(0x48, 0x03) //0x00004803
#define PIN_I2_5	MAKE_PIN_ADS1015(0x4b, 0x01) //0x00004b01

static const uint32_t I2_0 = PIN_I2_0;
static const uint32_t I2_1 = PIN_I2_1;
static const uint32_t I2_2 = PIN_I2_2;
static const uint32_t I2_3 = PIN_I2_3;
static const uint32_t I2_4 = PIN_I2_4;
static const uint32_t I2_5 = PIN_I2_5;

#define PIN_Q2_0	MAKE_PIN_PCA9685(0x41, 0x02) //0x00004102
#define PIN_Q2_1	MAKE_PIN_PCA9685(0x41, 0x01) //0x00004101
#define PIN_Q2_2	MAKE_PIN_PCA9685(0x41, 0x00) //0x00004100

static const uint32_t Q2_0 = PIN_Q2_0;
static const uint32_t Q2_1 = PIN_Q2_1;
static const uint32_t Q2_2 = PIN_Q2_2;

static const uint32_t A2_0 = PIN_Q2_0;
static const uint32_t A2_1 = PIN_Q2_1;
static const uint32_t A2_2 = PIN_Q2_2;

#define PIN_R2_1	MAKE_PIN_MCP23008(0x20, 0x05) //0x00002005
#define PIN_R2_2	MAKE_PIN_MCP23008(0x20, 0x06) //0x00002006
#define PIN_R2_3	MAKE_PIN_MCP23008(0x20, 0x04) //0x00002004
#define PIN_R2_4	MAKE_PIN_MCP23008(0x20, 0x07) //0x00002007
#define PIN_R2_5	MAKE_PIN_PCA9685(0x41, 0x03) //0x00004103
#define PIN_R2_6	MAKE_PIN_PCA9685(0x41, 0x04) //0x00004104
#define PIN_R2_7	MAKE_PIN_PCA9685(0x41, 0x05) //0x00004105
#define PIN_R2_8	MAKE_PIN_PCA9685(0x41, 0x07) //0x00004107

static const uint32_t R2_1 = PIN_R2_1;
static const uint32_t R2_2 = PIN_R2_2;
static const uint32_t R2_3 = PIN_R2_3;
static const uint32_t R2_4 = PIN_R2_4;
static const uint32_t R2_5 = PIN_R2_5;
static const uint32_t R2_6 = PIN_R2_6;
static const uint32_t R2_7 = PIN_R2_7;
static const uint32_t R2_8 = PIN_R2_8;

#endif
