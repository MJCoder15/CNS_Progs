#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* plaintext, int rails, char* ciphertext) {
    int len = strlen(plaintext);
    int rail_len = 2 * (rails - 1);
    int index = 0;

    // Encrypt characters in the zigzag pattern
    for (int i = 0; i < rails; i++) {
        for (int j = i; j < len; j += rail_len) {
            ciphertext[index++] = plaintext[j];
            if (i != 0 && i != rails - 1) {
                int k = j + rail_len - 2 * i;
                if (k < len) {
                    ciphertext[index++] = plaintext[k];
                }
            }
        }
    }
    ciphertext[index] = '\0';
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    int rails;

    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    encrypt(plaintext, rails, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

