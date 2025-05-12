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
#error "Not importing from pins_references.hpp"
#endif

#include <cstdint>
#include <cstddef>

// Pins arrays
static const uint32_t digitalInputsOutputs[] = {};
static const size_t numDigitalInputOutput = sizeof(digitalInputsOutputs) / sizeof(uint32_t);

static const uint32_t digitalInputs[] = {EXP_INT};
static const size_t numDigitalInputs = sizeof(digitalInputs) / sizeof(uint32_t);

static const uint32_t analogInputs[] = {};
static const size_t numAnalogInputs = sizeof(analogInputs) / sizeof(uint32_t);

static const uint32_t digitalOutputs[] = {DE_RE, EXP_PWM, EXP_RST};
static const size_t numDigitalOutputs = sizeof(digitalOutputs) / sizeof(uint32_t);

static const uint32_t PWMOutputs[] = {};
static const size_t numPWMOutputs = sizeof(PWMOutputs) / sizeof(uint32_t);

static const uint32_t analogOutputs[] = {};
static const size_t numAnalogOutputs = sizeof(analogOutputs) / sizeof(uint32_t);


// Pin-name arrays
static const pin_name_t namedDigitalInputsOutputs[] = {};
static const size_t numNamedDigitalInputsOutputs = sizeof(namedDigitalInputsOutputs) / sizeof(pin_name_t);

static const pin_name_t namedDigitalInputs[] = {{"EXP_INT", EXP_INT}};
static const size_t numNamedDigitalInputs = sizeof(namedDigitalInputs) / sizeof(pin_name_t);

static const pin_name_t namedAnalogInputs[] = {};
static const size_t numNamedAnalogInputs = sizeof(namedAnalogInputs) / sizeof(pin_name_t);

static const pin_name_t namedDigitalOutputs[] = {{"DE_RE", DE_RE}, {"EXP_PWM", EXP_PWM}, {"EXP_RST", EXP_RST}};
static const size_t numNamedDigitalOutputs = sizeof(namedDigitalOutputs) / sizeof(pin_name_t);

static const pin_name_t namedPWMOutputs[] = {};
static const size_t numNamedPWMOutputs = sizeof(namedPWMOutputs) / sizeof(pin_name_t);

static const pin_name_t namedAnalogOutputs[] = {};
static const size_t numNamedAnalogOutputs = sizeof(namedAnalogOutputs) / sizeof(pin_name_t);
