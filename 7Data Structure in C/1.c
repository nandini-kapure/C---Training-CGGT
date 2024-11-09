// 1. Program to check if a string of parentheses is balanced. The string is balanced if every opening parenthesis has a corresponding closing parenthesis and they are correctly nested. Input: A string consisting of parentheses (and optionally other characters). E.g., (a + b) * (c - d)", "(a + b * (c - d). Output: Balanced or Not-balanced
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_SIZE 100
 
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
 

void initialize(Stack* stack) {
    stack->top = -1;
}
 

int is_empty(Stack* stack) {
    return stack->top == -1;
}
 

int is_full(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, char value) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}
 

char pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}
 
int is_balanced(const char* str) {
    Stack stack;
    initialize(&stack);
 
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
 
       
        if (ch == '(') {
            push(&stack, ch);
        }
        
        else if (ch == ')') {
            if (is_empty(&stack)) {
                return 0; 
            }
            pop(&stack);
        }
    }
    
   
    return is_empty(&stack);
}
 
int main() {
    char input[MAX_SIZE];
 
    printf("Enter a string with parentheses: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
 
    if (is_balanced(input)) {
        printf("Balanced\n");
    } else {
        printf("Not balanced\n");
    }
 
    return 0;
}