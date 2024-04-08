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

#include <cstddef>
#include <cstring>
#include "pins-references.hpp"

template<const pin_name_t* PA, size_t N>
const pin_name_t* find_pin(const char* name){
	for (size_t i = 0; i < N; i++) {
		if (strcmp(name, PA[i].name) == 0) {
			return &PA[i];
		}
	}

	return nullptr;
}
