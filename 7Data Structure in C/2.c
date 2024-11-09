#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_URLS 1000
#define MAX_URL_LENGTH 256
#define BASE 62
const char base62_chars[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
char *url_store[MAX_URLS];
int url_count = 0;
 

void encode_base62(int num, char *shortURL) {
    int i = 0;
    while (num > 0) {
        shortURL[i++] = base62_chars[num % BASE];
        num /= BASE;
    }
    shortURL[i] = '\0';
 
   
    for (int j = 0; j < i / 2; j++) {
        char temp = shortURL[j];
        shortURL[j] = shortURL[i - j - 1];
        shortURL[i - j - 1] = temp;
    }
}
 

int decode_base62(const char *shortURL) {
    int num = 0;
    for (int i = 0; shortURL[i] != '\0'; i++) {
        if ('0' <= shortURL[i] && shortURL[i] <= '9')
            num = num * BASE + shortURL[i] - '0';
        else if ('a' <= shortURL[i] && shortURL[i] <= 'z')
            num = num * BASE + shortURL[i] - 'a' + 10;
        else if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
            num = num * BASE + shortURL[i] - 'A' + 36;
    }
    return num;
}

char* shortenURL(const char *longURL) {
    if (url_count >= MAX_URLS) {
        printf("URL store is full.\n");
        return NULL;
    }
 
  
    url_store[url_count] = (char *)malloc(MAX_URL_LENGTH * sizeof(char));
    strcpy(url_store[url_count], longURL);
 
    
    char *shortURL = (char *)malloc(7 * sizeof(char));
    encode_base62(url_count, shortURL);
 
    url_count++;
    return shortURL;
}
 

char* retrieveURL(const char *shortURL) {
    int id = decode_base62(shortURL);
 
    if (id >= 0 && id < url_count) {
        return url_store[id];
    } else {
        return "URL not found.";
    }
}
 
int main() {
    char longURL[MAX_URL_LENGTH];
    char shortURL[7]; 
 
    printf("Enter a long URL to shorten: ");
    fgets(longURL, MAX_URL_LENGTH, stdin);
    longURL[strcspn(longURL, "\n")] = '\0'; 
 
    char *generated_shortURL = shortenURL(longURL);
    if (generated_shortURL != NULL) {
        printf("Short URL: %s\n", generated_shortURL);
 
     
        printf("Retrieving long URL from short URL...\n");
        char *originalURL = retrieveURL(generated_shortURL);
        printf("Original URL: %s\n", originalURL);
 
        free(generated_shortURL);
    }
 
    for (int i = 0; i < url_count; i++) {
        free(url_store[i]);
    }
 
    return 0;
} 