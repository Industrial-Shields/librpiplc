/*
 * Copyright (c) 2025 Industrial Shields. All rights reserved
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

#define PIN_RE             MAKE_PIN_DIRECT(17)
#define PIN_DE             MAKE_PIN_DIRECT(27)
#define PIN_CS0            MAKE_PIN_DIRECT(8)
#define PIN_CS1            MAKE_PIN_DIRECT(7)
static const uint32_t RE = PIN_RE;
static const uint32_t DE = PIN_DE;
static const uint32_t CS0 = PIN_CS0;
static const uint32_t CS1 = PIN_CS1;

#define PIN_EXP1_AN        0xFFFFFFFF
#define PIN_EXP1_PWM       0xFFFFFFFF
#define PIN_EXP1_INT       0xFFFFFFFF
#define PIN_EXP1_RST       0xFFFFFFFF
static const uint32_t EXP1_AN = PIN_EXP1_AN;
static const uint32_t EXP1_PWM = PIN_EXP1_PWM;
static const uint32_t EXP1_INT = PIN_EXP1_INT;
static const uint32_t EXP1_RST = PIN_EXP1_RST;

#define PIN_I0_4_20       MAKE_PIN_ADS1015(0x49, 0x01)
#define PIN_I1_4_20       MAKE_PIN_ADS1015(0x49, 0x00)
#define PIN_I0            MAKE_PIN_ADS1015(0x49, 0x02)
#define PIN_I1            MAKE_PIN_ADS1015(0x49, 0x03)
#define PIN_I2            MAKE_PIN_DIRECT(20)
#define PIN_I3            MAKE_PIN_DIRECT(21)
#define PIN_I4            MAKE_PIN_DIRECT(26)
static const uint32_t I0_4_20 = PIN_I0_4_20;
static const uint32_t I1_4_20 = PIN_I1_4_20;
static const uint32_t I0 = PIN_I0;
static const uint32_t I1 = PIN_I1;
static const uint32_t I2 = PIN_I2;
static const uint32_t I3 = PIN_I3;
static const uint32_t I4 = PIN_I4;

#define PIN_O0           MAKE_PIN_DIRECT(19)
#define PIN_O1           MAKE_PIN_DIRECT(6)
#define PIN_O2           MAKE_PIN_DIRECT(5)
#define PIN_O3           MAKE_PIN_DIRECT(22)
#define PIN_O4           MAKE_PIN_DIRECT(4)
static const uint32_t O0 = PIN_O0;
static const uint32_t O1 = PIN_O1;
static const uint32_t O2 = PIN_O2;
static const uint32_t O3 = PIN_O3;
static const uint32_t O4 = PIN_O4;

#define PIN_Q0           MAKE_PIN_DIRECT(19)
#define PIN_Q1           MAKE_PIN_DIRECT(6)
#define PIN_Q2           MAKE_PIN_DIRECT(5)
#define PIN_Q3           MAKE_PIN_DIRECT(22)
#define PIN_Q4           MAKE_PIN_DIRECT(4)
static const uint32_t Q0 = PIN_Q0;
static const uint32_t Q1 = PIN_Q1;
static const uint32_t Q2 = PIN_Q2;
static const uint32_t Q3 = PIN_Q3;
static const uint32_t Q4 = PIN_Q4;
