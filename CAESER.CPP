#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char* plaintext, int shift) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            char ascii_offset = isupper(plaintext[i]) ? 'A' : 'a';
            plaintext[i] = ((plaintext[i] - ascii_offset + shift) % 26) + ascii_offset;
        }
    }
}

int main() {
        char plaintext[100];
        int shift;
		printf("Enter the plaintext: ");
        scanf(" %[^\n]", plaintext);

        printf("Enter the shift value: ");
        scanf("%d", &shift);

        encrypt(plaintext, shift);
        printf("Ciphertext: %s\n", plaintext);
    
    return 0;
}