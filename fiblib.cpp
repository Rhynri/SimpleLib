#include "fiblib.h"

namespace FibLib {
    uint64_t get(uint32_t index) {
        if (index <= 2) {
            return 1;
        }

        uint64_t first = 1; 
        uint64_t second = 1;

        // Index minus 1 to account for zero indexing
        for (uint32_t i = 2; i < index; ++i) {
            uint64_t next = first + second;
            first = second;
            second = next;
        }

        // Latest number will be in second
        return second;
    }
} // namespace FibLib