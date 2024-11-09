// 10. Program to check if a user provided IP Address (IPv4) is valid or not
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool partCheck(char *part) {
    int num = atoi(part); 
    
    if (num >= 0 && num <= 255) {
        return true;
    }
    return false;
}

bool isValidIP(char *ip) {
    char ip_copy[20];
    strcpy(ip_copy, ip);

    char *part = strtok(ip_copy, ".");
    int dot_count = 0;

    while (part != NULL) {
        dot_count++;
        if (!partCheck(part)) {
            return false;
        }
        part = strtok(NULL, ".");
    }

    return dot_count == 4;
}

int main() {
    char ip[20];

    printf("Enter an IPv4 address: ");
    scanf("%s", ip);

    if (isValidIP(ip)) {
        printf("The IP address %s is valid.\n", ip);
    } else {
        printf("The IP address %s is not valid.\n", ip);
    }

    return 0;
}
