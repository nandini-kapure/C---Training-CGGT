// 4. Program to extract comments from source code and print the extracted comments. The program should identify and extract comments in a user entered C/C++ program.   

#include <stdio.h>
#include <string.h>

#define MAX_CODE_LENGTH 1000

// Function to extract comments from source code
void extract_comments(const char *code) {
    int in_single_line_comment = 0;
    int in_multi_line_comment = 0;

    printf("Extracted Comments:\n");
    
    for (int i = 0; code[i] != '\0'; i++) {
        if (!in_single_line_comment && !in_multi_line_comment) {
            // Check for start of a single-line comment
            if (code[i] == '/' && code[i + 1] == '/') {
                in_single_line_comment = 1;
                i++;
                printf("//");
            }
            // Check for start of a multi-line comment
            else if (code[i] == '/' && code[i + 1] == '*') {
                in_multi_line_comment = 1;
                i++;
                printf("/*");
            }
        } 
        else if (in_single_line_comment) {
            // Print characters within single-line comment
            if (code[i] == '\n') {
                in_single_line_comment = 0;
                printf("\n");
            } else {
                putchar(code[i]);
            }
        } 
        else if (in_multi_line_comment) {
            // Print characters within multi-line comment
            if (code[i] == '*' && code[i + 1] == '/') {
                in_multi_line_comment = 0;
                i++;
                printf("*/\n");
            } else {
                putchar(code[i]);
            }
        }
    }

    if (!in_single_line_comment && !in_multi_line_comment) {
        printf("\nNo more comments found.\n");
    }
}

int main() {
    char code[MAX_CODE_LENGTH];

    printf("Enter your C/C++ code (end with an empty line):\n");

    // Read the user input code until an empty line is encountered
    code[0] = '\0';
    while (fgets(code + strlen(code), MAX_CODE_LENGTH - strlen(code), stdin) != NULL) {
        if (strcmp(code + strlen(code) - 1, "\n") == 0 && code[strlen(code) - 2] == '\n') {
            break;
        }
    }

    extract_comments(code);

    return 0;
}
