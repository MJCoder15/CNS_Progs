#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char* plaintext, char* key) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            char ascii_offset = isupper(plaintext[i]) ? 'A' : 'a';
            plaintext[i] = key[plaintext[i] - ascii_offset];
        }
    }
}

int main() {
    char plaintext[100];
    char key[26];

    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);

    printf("Enter the key: ");
    scanf(" %[^\n]", key);

    if (strlen(key) != 26) {
        printf("Invalid key. The key must contain all 26 alphabets.\n");
        return 1;
    }

    // Convert the key to uppercase
    for (int i = 0; i < 26; i++) {
        key[i] = toupper(key[i]);
    }

    encrypt(plaintext, key);
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}

