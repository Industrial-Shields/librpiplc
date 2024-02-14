#include <cstddef>
#include <cstring>
#include "pins_references.hpp"

template<const pin_name_t* PA, size_t N>
const pin_name_t* find_pin(const char* name){
    for (size_t i = 0; i < N; i++) {
        if (strcmp(name, PA[i].name) == 0) {
            return &PA[i];
        }
    }
    return nullptr;
}
