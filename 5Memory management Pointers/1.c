// 1. Program that dynamically splits a user entered string into tokens based on a delimiter provided by the user. Ask user whether splitting should be case-sensitive or case-insensitive and split accordingly. Trim whitespaces from each token and store it in a dynamically allocated data structure along with frequency of occurance of each token. Print the tokens along with their frequency.  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *token;
    int frequency;
} Token;

typedef struct {
    Token *tokens;
    int size;
} TokenList;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

char *trim_whitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    return str;
}

void add_token(TokenList *list, char *token) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->tokens[i].token, token) == 0) {
            list->tokens[i].frequency++;
            return;
        }
    }
    list->tokens = realloc(list->tokens, (list->size + 1) * sizeof(Token));
    list->tokens[list->size].token = strdup(token);
    list->tokens[list->size].frequency = 1;
    list->size++;
}

void split_and_count(char *input, char *delimiter, int case_sensitive) {
    TokenList list = {NULL, 0};
    char *input_copy = strdup(input);
    char *token = strtok(input_copy, delimiter);
    while (token) {
        token = trim_whitespace(token);
        if (!case_sensitive) to_lowercase(token);
        add_token(&list, token);
        token = strtok(NULL, delimiter);
    }
    free(input_copy);

    printf("\nTokens and their frequencies:\n");
    for (int i = 0; i < list.size; i++) {
        printf("Token: %s, Frequency: %d\n", list.tokens[i].token, list.tokens[i].frequency);
        free(list.tokens[i].token);
    }
    free(list.tokens);
}

int main() {
    char input[256], delimiter[10];
    int case_sensitive;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline

    printf("Enter a delimiter: ");
    fgets(delimiter, sizeof(delimiter), stdin);
    delimiter[strcspn(delimiter, "\n")] = 0; // Remove newline

    printf("Case-sensitive split? (1 for Yes, 0 for No): ");
    scanf("%d", &case_sensitive);

    split_and_count(input, delimiter, case_sensitive);

    return 0;
}
///////////////incomplete