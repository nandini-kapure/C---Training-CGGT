#include <stdio.h>
#include <stdint.h>
 
int is_little_endian() {
    uint16_t num = 1;
    return *((uint8_t*)&num);
}
 
uint32_t swap_endianness(uint32_t num) {
    return ((num >> 24) & 0x000000FF) |
           ((num >> 8) & 0x0000FF00) |
           ((num << 8) & 0x00FF0000) |
           ((num << 24) & 0xFF000000);
}
 
uint32_t read_4byte_integer(FILE *file) {
    uint32_t num;
    if (fread(&num, sizeof(num), 1, file) != 1) {
        perror("Error reading from file");
        return 0;
    }
 
    if (is_little_endian()) {
        return swap_endianness(num);
    } else {
        return num;
    }
}
 
int main() {
    const char *filename = "data.bin";
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
 
    printf("Integers read from the file:\n");
    while (!feof(file)) {
        uint32_t value = read_4byte_integer(file);
        if (feof(file)) break;
        printf("%u\n", value);
    }
 
    fclose(file);
    return 0;
}