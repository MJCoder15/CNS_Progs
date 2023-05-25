#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateRandomKey(int length, char* key) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'A';  // Generate a random uppercase letter
    }
}

void encrypt(char* plaintext, char* key) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        plaintext[i] = (plaintext[i] - 'A' + key[i] - 'A') % 26 + 'A';  // Perform modulo 26 addition
    }
}

int main() {
    char plaintext[100];
    char key[100];

    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);

    int plaintext_length = strlen(plaintext);

    generateRandomKey(plaintext_length, key);

    encrypt(plaintext, key);
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}

