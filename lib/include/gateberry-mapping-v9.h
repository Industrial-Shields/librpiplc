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

#define PIN_DE_RE             MAKE_PIN_DIRECT(27)
static const uint32_t DE_RE = PIN_DE_RE;

#define PIN_EXP_RST           MAKE_PIN_DIRECT(26)
#define PIN_EXP_CS            MAKE_PIN_DIRECT(11)
#define PIN_EXP_AN            MAKE_PIN_DIRECT(16)
#define PIN_EXP_PWM           MAKE_PIN_DIRECT(20)
#define PIN_EXP_INT           MAKE_PIN_DIRECT(21)
static const uint32_t EXP_RST = PIN_EXP_RST;
static const uint32_t EXP_CS =  PIN_EXP_CS;
static const uint32_t EXP_AN =  PIN_EXP_AN;
static const uint32_t EXP_PWM = PIN_EXP_PWM;
static const uint32_t EXP_INT = PIN_EXP_INT;

#define PIN_RS485_TERMINATION             MAKE_PIN_DIRECT(17)
static const uint32_t RS485_TERMINATION = PIN_RS485_TERMINATION;
