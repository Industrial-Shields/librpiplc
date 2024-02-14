#ifndef __RPIPLC_MAPPING_H__
#define __RPIPLC_MAPPING_H__

#if defined(RPIPLC_V5)
#include "rpiplc-mapping-v5.h"

#elif defined(RPIPLC_V4)
#include "rpiplc-mapping-v4.h"

#elif defined(RPIPLC_V3)
#include "rpiplc-mapping-v3.h"

#else
#error "No selected PLC version"
#endif

#endif
