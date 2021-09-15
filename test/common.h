#ifndef __COMMON_H__
#define __COMMON_H__

static const uint32_t digitalInputs[] = {
#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	I0_0, I0_1, I0_2, I0_3, I0_4, I0_5, I0_6,

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	I0_0, I0_1, I0_2, I0_3, I0_4, I0_5,

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	I1_0, I1_1, I1_2, I1_3, I1_4, I1_5, I1_6,

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	I1_0, I1_1, I1_2, I1_3, I1_4, I1_5,

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	I2_0, I2_1, I2_2, I2_3, I2_4, I2_5, I2_6,

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	I2_0, I2_1, I2_2, I2_3, I2_4, I2_5,

#endif
};
static const int numDigitalInputs = sizeof(digitalInputs) / sizeof(uint32_t);

static const uint32_t analogInputs[] = {
#if defined(RPIPLC_21) || defined(RPIPLC_38AR) || defined(RPIPLC_42) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	I0_7, I0_8, I0_9, I0_10, I0_11, I0_12,

#elif defined(RPIPLC_19R) || defined(RPIPLC_38R) || defined(RPIPLC_50RRA) || defined(RPIPLC_57R)
	I0_0, I0_1, I0_2, I0_3, I0_4, I0_5,

#endif

#if defined(RPIPLC_42) || defined(RPIPLC_57AAR) || defined(RPIPLC_58)
	I1_7, I1_8, I1_9, I1_10, I1_11, I1_12,

#elif defined(RPIPLC_38R) || defined(RPIPLC_38AR) || defined(RPIPLC_50RRA) || defined(RPIPLC_53ARR) || defined(RPIPLC_54ARA) || defined(RPIPLC_57R)
	I1_0, I1_1, I1_2, I1_3, I1_4, I1_5,

#endif

#if defined(RPIPLC_50RRA) || defined(RPIPLC_54ARA) || defined(RPIPLC_58)
	I2_7, I2_8, I2_9, I2_10,

#elif defined(RPIPLC_53ARR) || defined(RPIPLC_57AAR) || defined(RPIPLC_57R)
	I2_0, I2_1, I2_2, I2_3, I2_4, I2_5,

#endif
};
static const int numAnalogInputs = sizeof(analogInputs) / sizeof(uint32_t);

static const uint32_t digitalOutputs[] = {
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
static const int numDigitalOutputs = sizeof(digitalOutputs) / sizeof(uint32_t);

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
static const int numAnalogOutputs = sizeof(analogOutputs) / sizeof(uint32_t);

#endif
