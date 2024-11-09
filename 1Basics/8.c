// 8. Program to Reverse All Bits of a 32-bit Integer

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t num) {
    uint32_t rev_num = 0; 
    int bitCount = 32;       

    for (int i = 0; i < bitCount; i++) {
        rev_num <<= 1;
        if (num & 1) {
            rev_num |= 1;
        }
        num >>= 1;
    }

    return rev_num;
}

int main() {
    uint32_t num;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    uint32_t reversed = reverseBits(num);

    printf("Original number: %u\n", num);
    printf("Reversed number: %u\n", reversed);

    return 0;
}
