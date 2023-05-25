
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Function to prepare the key by removing duplicates and filling the remaining cells
void prepareKey(char key[], char keyMatrix[][SIZE]) {
    int i, j, k;
    char temp[26];
    int len = strlen(key);

    // Copy key to temp array
    strncpy(temp, key, len);

    // Append remaining alphabets to temp array
    for (i = len, j = 0; i < 26; i++, j++) {
        for (k = 0; k < len; k++) {
            if (temp[k] == 'A' + j) {
                break;
            }
        }
        if (k == len) {
            temp[len++] = 'A' + j;
        }
    }

    // Fill the key matrix
    for (i = 0, k = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            keyMatrix[i][j] = temp[k++];
        }
    }
}

// Function to find the position of a character in the key matrix
void findPosition(char keyMatrix[][SIZE], char ch, int *row, int *col) {
    int i, j;

    if (ch == 'J') {
        ch = 'I';
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to apply Playfair algorithm on the input message
void encrypt(char keyMatrix[][SIZE], char message[]) {
    int i, row1, col1, row2, col2;
    char cipher[100];
    int len = strlen(message);

    for (i = 0; i < len; i += 2) {
        findPosition(keyMatrix, message[i], &row1, &col1);
        findPosition(keyMatrix, message[i + 1], &row2, &col2);

        if (row1 == row2) {
            cipher[i] = keyMatrix[row1][(col1 + 1) % SIZE];
            cipher[i + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            cipher[i] = keyMatrix[(row1 + 1) % SIZE][col1];
            cipher[i + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            cipher[i] = keyMatrix[row1][col2];
            cipher[i + 1] = keyMatrix[row2][col1];
        }
    }

    cipher[len] = '\0';

    printf("Encrypted message: %s\n", cipher);
}

int main() {
    char key[26];
    char keyMatrix[SIZE][SIZE];
    char message[100];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message: ");
    scanf("%s", message);

    prepareKey(key, keyMatrix);
    encrypt(keyMatrix, message);

    return 0;
}
