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
static const uint32_t digitalInputsOutputs[] = {/*EXP1_AN, EXP1_PWM, EXP1_INT, EXP1_RST*/};
static const size_t numDigitalInputOutput = sizeof(digitalInputsOutputs) / sizeof(uint32_t);

static const uint32_t digitalInputs[] = {I2, I3, I4};
static const size_t numDigitalInputs = sizeof(digitalInputs) / sizeof(uint32_t);

static const uint32_t analogInputs[] = {I0_4_20, I1_4_20, I0, I1};
static const size_t numAnalogInputs = sizeof(analogInputs) / sizeof(uint32_t);

static const uint32_t digitalOutputs[] = {RE, DE, O0, O1, O2, O3, O4};
static const size_t numDigitalOutputs = sizeof(digitalOutputs) / sizeof(uint32_t);

static const uint32_t PWMOutputs[] = {EXP1_PWM};
static const size_t numPWMOutputs = sizeof(PWMOutputs) / sizeof(uint32_t);

static const uint32_t analogOutputs[] = {};
static const size_t numAnalogOutputs = sizeof(analogOutputs) / sizeof(uint32_t);


// Pin-name arrays
static const pin_name_t namedDigitalInputsOutputs[] = {
	/*
    {"EXP1_AN", EXP1_AN},
    {"EXP1_PWM", EXP1_PWM},
    {"EXP1_INT", EXP1_INT},
    {"EXP1_RST", EXP1_RST}
    */
};
static const size_t numNamedDigitalInputsOutputs = sizeof(namedDigitalInputsOutputs) / sizeof(pin_name_t);

static const pin_name_t namedDigitalInputs[] = {
    {"I2", I2},
    {"I3", I3},
    {"I4", I4}
};
static const size_t numNamedDigitalInputs = sizeof(namedDigitalInputs) / sizeof(pin_name_t);

static const pin_name_t namedAnalogInputs[] = {
    {"I0_4_20", I0_4_20},
    {"I1_4_20", I1_4_20},
    {"I0", I0},
    {"I1", I1}
};
static const size_t numNamedAnalogInputs = sizeof(namedAnalogInputs) / sizeof(pin_name_t);

static const pin_name_t namedDigitalOutputs[] = {
    {"RE", RE},
    {"DE", DE},
    {"O0", O0},
    {"O1", O1},
    {"O2", O2},
    {"O3", O3},
    {"O4", O4}
};
static const size_t numNamedDigitalOutputs = sizeof(namedDigitalOutputs) / sizeof(pin_name_t);

static const pin_name_t namedPWMOutputs[] = {
    {"EXP1_PWM", EXP1_PWM}
};
static const size_t numNamedPWMOutputs = sizeof(namedPWMOutputs) / sizeof(pin_name_t);

static const pin_name_t namedAnalogOutputs[] = {};
static const size_t numNamedAnalogOutputs = sizeof(namedAnalogOutputs) / sizeof(pin_name_t);
