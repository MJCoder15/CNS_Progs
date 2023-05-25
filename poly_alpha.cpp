#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char* plaintext, char* key) {
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);
    int key_index = 0;

    for (int i = 0; i < plaintext_length; i++) {
        char ascii_offset = isupper(plaintext[i]) ? 'A' : 'a';
        char shifted_char = ((plaintext[i] - ascii_offset + key[key_index] - 'A') % 26) + ascii_offset;
        plaintext[i] = shifted_char;

        key_index = (key_index + 1) % key_length;
    }
}

int main() {
    char plaintext[100];
    char key[100];

    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);

    printf("Enter the key: ");
    scanf(" %[^\n]", key);

    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);

    for (int i = 0; i < key_length; i++) {
        key[i] = toupper(key[i]);
    }
    encrypt(plaintext, key);
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}

