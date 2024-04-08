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
#define __RPIPLC_MAPPING_H__

/**
 * This header is used to define which version of the PLC mappings
 * will be imported.
 */

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
