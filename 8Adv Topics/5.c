#include <stdio.h>
#include <stdint.h>
 
uint32_t pack_values(uint8_t val1, uint8_t val2, uint8_t val3, uint8_t val4) {
    return (val1 << 24) | (val2 << 16) | (val3 << 8) | val4;
}
 
void unpack_values(uint32_t packed, uint8_t *val1, uint8_t *val2, uint8_t *val3, uint8_t *val4) {
    *val1 = (packed >> 24) & 0xFF;
    *val2 = (packed >> 16) & 0xFF;
    *val3 = (packed >> 8) & 0xFF;
    *val4 = packed & 0xFF;
}
 
int main() {
    uint8_t a, b, c, d;
    printf("Enter four 8-bit values (0-255): ");
    scanf("%hhu %hhu %hhu %hhu", &a, &b, &c, &d);
 
    uint32_t packed = pack_values(a, b, c, d);
    printf("Packed Integer: 0x%08X\n", packed);
 
    uint8_t unpacked_a, unpacked_b, unpacked_c, unpacked_d;
    unpack_values(packed, &unpacked_a, &unpacked_b, &unpacked_c, &unpacked_d);
    printf("Unpacked Values: %u, %u, %u, %u\n", unpacked_a, unpacked_b, unpacked_c, unpacked_d);
 
    return 0;
}