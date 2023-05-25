#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int keyLength = strlen(key);
    int textLength = strlen(plaintext);

    // Calculate the number of rows based on the key length
    int rows = (textLength + keyLength - 1) / keyLength;

    // Allocate memory for the transposition matrix
    char** matrix = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(keyLength * sizeof(char));
    }

    // Fill the transposition matrix with the plaintext characters
    int textIndex = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLength; j++) {
            if (textIndex < textLength) {
                matrix[i][j] = plaintext[textIndex++];
            } else {
                matrix[i][j] = 'X';  // Pad with 'X' if necessary
            }
        }
    }

    // Rearrange the columns of the transposition matrix based on the key
    for (int i = 0; i < keyLength; i++) {
        int keyIndex = key[i] - '1';
        for (int j = 0; j < rows; j++) {
            ciphertext[i * rows + j] = matrix[j][keyIndex];
        }
    }
    ciphertext[textLength] = '\0';

    // Free memory for the transposition matrix
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];

    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);

    printf("Enter the key: ");
    scanf(" %[^\n]", key);

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

