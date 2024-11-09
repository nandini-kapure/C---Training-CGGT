// 1. Program to swap the byte ordering/endianness of a number from Little Endian to Big Endian and vice versa
#include <stdio.h>
 
unsigned int swap_func(unsigned int num) {
    
    unsigned int byte0 = (num & 0x000000FF) << 24; 
    unsigned int byte1 = (num & 0x0000FF00) << 8; 
    unsigned int byte2 = (num & 0x00FF0000) >> 8;  
    unsigned int byte3 = (num & 0xFF000000) >> 24;
 
    return byte0 | byte1 | byte2 | byte3;
}
 
int main() {
    unsigned int num;
 
   
    printf("Enter a hexadecimal number (e.g., 0x12345678): ");
    scanf("%x", &num);
 
    printf("Original number: 0x%x\n", num);
 
    unsigned int swapped = swap_func(num);
    printf("Swapped Endianness: 0x%x\n", swapped);
 
    return 0;
}