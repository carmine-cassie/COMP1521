
#include <stdint.h>

#define SIGN     0b10000000000000000000000000000000
#define EXPONENT 0b01111111100000000000000000000000
#define FRACTION 0b00000000011111111111111111111111

int get_exponent(uint32_t f) {
    
    int exp = (f & EXPONENT) >> 23;

    return exp - 127;

}