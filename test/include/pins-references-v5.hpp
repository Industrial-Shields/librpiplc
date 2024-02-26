#ifndef __PINS_REFERENCES_H__
#error "Not importing from pins_references.h"
#endif

#include <cstdint>
#include <cstddef>

// Pins arrays
static const uint32_t digitalInputs[] = {
	PIN8, OPTO_IN_1, OPTO_IN_2,
#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	I0_0, I0_1, I0_2, I0_3, I0_4, I0_5, I0_6,

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	I0_0, I0_1,

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	I1_0, I1_1, I1_2, I1_3, I1_4, I1_5, I1_6,

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	I1_0, I1_1,

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	I2_0, I2_1, I2_2, I2_3, I2_4, I2_5, I2_6,

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	I2_0, I2_1,

#endif
};
static const size_t numDigitalInputs = sizeof(digitalInputs) / sizeof(uint32_t);

static const uint32_t analogInputs[] = {
#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	I0_7, I0_8, I0_9, I0_10, I0_11, I0_12,

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	I0_2, I0_3, I0_4, I0_5,

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	I1_7, I1_8, I1_9, I1_10, I1_11, I1_12,

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	I1_2, I1_3, I1_4, I1_5,

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	I2_7, I2_8, I2_9, I2_10, I2_11, I2_12

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	I2_2, I2_3, I2_4, I2_5,

#endif
};
static const size_t numAnalogInputs = sizeof(analogInputs) / sizeof(uint32_t);

static const uint32_t digitalOutputs[] = {
        PIN8, PWM1, PWM2, PWM3, OPTO_OUT_1, OPTO_OUT_2, P_RELAY,
#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	Q0_0, Q0_1, Q0_2, Q0_3, Q0_4, Q0_5, Q0_6, Q0_7,

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	Q0_0, Q0_1, Q0_2,
	R0_1, R0_2, R0_3, R0_4, R0_5, R0_6, R0_7, R0_8,

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	Q1_0, Q1_1, Q1_2, Q1_3, Q1_4, Q1_5, Q1_6, Q1_7,

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	Q1_0, Q1_1, Q1_2,
	R1_1, R1_2, R1_3, R1_4, R1_5, R1_6, R1_7, R1_8,

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	Q2_0, Q2_1, Q2_2, Q2_3, Q2_4, Q2_5, Q2_6, Q2_7,

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	Q2_0, Q2_1, Q2_2,
	R2_1, R2_2, R2_3, R2_4, R2_5, R2_6, R2_7, R2_8,

#endif
};
static const size_t numDigitalOutputs = sizeof(digitalOutputs) / sizeof(uint32_t);

static const uint32_t analogOutputs[] = {
#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	A0_5, A0_6, A0_7,

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	A0_0, A0_1, A0_2,

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	A1_5, A1_6, A1_7,

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	A1_0, A1_1, A1_2,

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	A2_5, A2_6, A2_7,

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	A2_0, A2_1, A2_2,

#endif
};
static const size_t numAnalogOutputs = sizeof(analogOutputs) / sizeof(uint32_t);


// Pin-name arrays
static const pin_name_t namedDigitalInputs[] = {
	{"PIN8", PIN8}, {"OPTO_IN_1", OPTO_IN_1}, {"OPTO_IN_2", OPTO_IN_2},

#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	{"I0.0", I0_0}, {"I0.1", I0_1}, {"I0.2", I0_2}, {"I0.3", I0_3}, {"I0.4", I0_4}, {"I0.5", I0_5}, {"I0.6", I0_6},

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	{"I0.0", I0_0}, {"I0.1", I0_1},
#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	{"I1.0", I1_0}, {"I1.1", I1_1}, {"I1.2", I1_2}, {"I1.3", I1_3}, {"I1.4", I1_4}, {"I1.5", I1_5}, {"I1.6", I1_6},

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	{"I1.0", I1_0}, {"I1.1", I1_1},

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	{"I2.0", I2_0}, {"I2.1", I2_1}, {"I2.2", I2_2}, {"I2.3", I2_3}, {"I2.4", I2_4}, {"I2.5", I2_5}, {"I2.6", I2_6},

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	{"I2.0", I2_0}, {"I2.1", I2_1},

#endif
};
static const size_t numNamedDigitalInputs = sizeof(namedDigitalInputs) / sizeof(pin_name_t);

static const pin_name_t namedAnalogInputs[] = {

#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	{"I0.7", I0_7}, {"I0.8", I0_8}, {"I0.9", I0_9}, {"I0.10", I0_10}, {"I0.11", I0_11}, {"I0.12", I0_12},

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	{"I0.2", I0_2}, {"I0.3", I0_3}, {"I0.4", I0_4}, {"I0.5", I0_5},

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	{"I1.7", I1_7}, {"I1.8", I1_8}, {"I1.9", I1_9}, {"I1.10", I1_10}, {"I1.11", I1_11}, {"I1.12", I1_12},

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	{"I1.2", I1_2}, {"I1.3", I1_3}, {"I1.4", I1_4}, {"I1.5", I1_5},

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	{"I2.7", I2_7}, {"I2.8", I2_8}, {"I2.9", I2_9}, {"I2.10", I2_10}, {"I2.11", I2_11}, {"I2.12", I2_12},

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	{"I2.2", I2_2}, {"I2.3", I2_3}, {"I2.4", I2_4}, {"I2.5", I2_5}

#endif
};
static const size_t numNamedAnalogInputs = sizeof(namedAnalogInputs) / sizeof(pin_name_t);

static const pin_name_t namedDigitalOutputs[] = {
	{"PIN8", PIN8}, {"PWM1", PWM1}, {"PWM2", PWM2}, {"PWM3", PWM3}, {"OPTO_OUT_1", OPTO_OUT_1}, {"OPTO_OUT_2", OPTO_OUT_2}, {"PRELAY", P_RELAY},

#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	{"Q0.0", Q0_0}, {"Q0.1", Q0_1}, {"Q0.2", Q0_2}, {"Q0.3", Q0_3}, {"Q0.4", Q0_4}, {"Q0.5", Q0_5}, {"Q0.6", Q0_6}, {"Q0.7", Q0_7},

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	{"Q0.0", Q0_0}, {"Q0.1", Q0_1}, {"Q0.2", Q0_2},
	{"R0.1", R0_1}, {"R0.2", R0_2}, {"R0.3", R0_3}, {"R0.4", R0_4}, {"R0.5", R0_5}, {"R0.6", R0_6}, {"R0.7", R0_7}, {"R0.8", R0_8},

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	{"Q1.0", Q1_0}, {"Q1.1", Q1_1}, {"Q1.2", Q1_2}, {"Q1.3", Q1_3}, {"Q1.4", Q1_4}, {"Q1.5", Q1_5}, {"Q1.6", Q1_6}, {"Q1.7", Q1_7},

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	{"Q1.0", Q1_0}, {"Q1.1", Q1_1}, {"Q1.2", Q1_2},
	{"R1.1", R1_1}, {"R1.2", R1_2}, {"R1.3", R1_3}, {"R1.4", R1_4}, {"R1.5", R1_5}, {"R1.6", R1_6}, {"R1.7", R1_7}, {"R1.8", R1_8},

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	{"Q2.0", Q2_0}, {"Q2.1", Q2_1}, {"Q2.2", Q2_2}, {"Q2.3", Q2_3}, {"Q2.4", Q2_4}, {"Q2.5", Q2_5}, {"Q2.6", Q2_6}, {"Q2.7", Q2_7},

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	{"Q2.0", Q2_0}, {"Q2.1", Q2_1}, {"Q2.2", Q2_2},
	{"R2.1", R2_1}, {"R2.2", R2_2}, {"R2.3", R2_3}, {"R2.4", R2_4}, {"R2.5", R2_5}, {"R2.6", R2_6}, {"R2.7", R2_7}, {"R2.8", R2_8},

#endif
};
static const size_t numNamedDigitalOutputs = sizeof(namedDigitalOutputs) / sizeof(pin_name_t);

static const pin_name_t namedAnalogOutputs[] = {
#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	{"A0.5", A0_5}, {"A0.6", A0_6}, {"A0.7", A0_7},
	{"Q0.0", Q0_0}, {"Q0.1", Q0_1}, {"Q0.2", Q0_2}, {"Q0.3", Q0_3}, {"Q0.4", Q0_4}, {"Q0.5", Q0_5}, {"Q0.6", Q0_6}, {"Q0.7", Q0_7},

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	{"A0.0", A0_0}, {"A0.1", A0_1}, {"A0.2", A0_2},
	{"Q0.0", Q0_0}, {"Q0.1", Q0_1}, {"Q0.2", Q0_2},

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	{"A1.5", A1_5}, {"A1.6", A1_6}, {"A1.7", A1_7},
	{"Q1.0", Q1_0}, {"Q1.1", Q1_1}, {"Q1.2", Q1_2}, {"Q1.3", Q1_3}, {"Q1.4", Q1_4}, {"Q1.5", Q1_5}, {"Q1.6", Q1_6}, {"Q1.7", Q1_7},

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	{"A1.0", A1_0}, {"A1.1", A1_1}, {"A1.2", A1_2},
	{"Q1.0", Q1_0}, {"Q1.1", Q1_1}, {"Q1.2", Q1_2},

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	{"A2.5", A2_5}, {"A2.6", A2_6}, {"A2.7", A2_7},
	{"Q2.0", Q2_0}, {"Q2.1", Q2_1}, {"Q2.2", Q2_2}, {"Q2.3", Q2_3}, {"Q2.4", Q2_4}, {"Q2.5", Q2_5}, {"Q2.6", Q2_6}, {"Q2.7", Q2_7},
	

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	{"A2.0", A2_0}, {"A2.1", A2_1}, {"A2.2", A2_2},
	{"Q2.0", Q2_0}, {"Q2.1", Q2_1}, {"Q2.2", Q2_2},

#endif
};
static const size_t numNamedAnalogOutputs = sizeof(namedAnalogOutputs) / sizeof(pin_name_t);
