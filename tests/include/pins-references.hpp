/**
 * Copyright (c) 2024 Industrial Shields. All rights reserved
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __PINS_REFERENCES_H__
#define __PINS_REFERENCES_H__

#include <cstdint>
#include <rpiplc.h>

#define __PERROR_WITH_LINE_STRINGIFY_HELPER(x) #x
#define __PERROR_WITH_LINE_STRINGIFY(x) __PERROR_WITH_LINE_STRINGIFY_HELPER(x)
#define PERROR_WITH_LINE(msg) perror(msg " in line " __PERROR_WITH_LINE_STRINGIFY(__LINE__))

typedef struct {
        const char* name;
        uint32_t pin;
} pin_name_t;

#if defined(RPIPLC_V6)
#include "pins-references-v6.hpp"

#elif defined(RPIPLC_V4)
#include "pins-references-v4.hpp"

#elif defined(RPIPLC_V3)
#include "pins-references-v3.hpp"

#elif defined(UPSAFEPI_V6) && defined(UPSAFEPI)
#include "pins-references-upsafepi-v6.hpp"

#else
#error "No selected PLC version"
#endif

#endif // __PINS_REFERENCES_H__
