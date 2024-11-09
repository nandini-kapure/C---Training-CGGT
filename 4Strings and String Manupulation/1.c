// 1. Program to sanitize/clean up a user entered block of text by removing unwanted characters, extra spaces, newlines, etc. The program should handle inputs with excessive spaces, newline characters, and special symbols. After sanitization, display the sanitized text.

#include <stdio.h>
#include <ctype.h> 
#include <string.h>

void sanitize_text(char* input, char* output) {
    int i = 0, j = 0;
    int space_flag = 0;

    while (input[i] != '\0') {
        if (isalnum(input[i])) {
            output[j++] = input[i];
            space_flag = 0; 
        }
        else if (input[i] == '\n' || input[i] == '\r') {
            if (space_flag == 0) {  
                output[j++] = ' ';
                space_flag = 1;
            }
        }
        // Replace multiple spaces with a single space
        else if (isspace(input[i])) {
            if (space_flag == 0) {  
                output[j++] = ' ';
                space_flag = 1;
            }
        }
        i++;
    }
    if (j > 0 && output[j-1] == ' ') {
        output[j-1] = '\0';
    } else {
        output[j] = '\0';
    }
}

int main() {
    char input[1000], output[1000];

    printf("Enter a block of text:\n");
    fgets(input, sizeof(input), stdin); 

    sanitize_text(input, output);

    printf("\nSanitized Text:\n%s\n", output);

    return 0;
}

