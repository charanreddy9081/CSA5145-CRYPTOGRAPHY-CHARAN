#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY 26
#define MAX_PLAINTEXT 1000

// Function to generate the cipher sequence from a keyword
void generate_cipher_sequence(char keyword[], char cipher_sequence[]) {
    int i, j, k = 0;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    // Copy the keyword to the cipher sequence
    for (i = 0; i < strlen(keyword); i++) {
        cipher_sequence[k++] = tolower(keyword[i]);
    }

    // Add the remaining letters of the alphabet to the cipher sequence
    for (i = 0; i < 26; i++) {
        for (j = 0; j < k; j++) {
            if (alphabet[i] == cipher_sequence[j]) {
                break;
            }
        }
        if (j == k) {
            cipher_sequence[k++] = alphabet[i];
        }
    }
    cipher_sequence[k] = '\0';
}

// Function to encrypt the plaintext using the monoalphabetic cipher
void encrypt(char plaintext[], char cipher_sequence[]) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = cipher_sequence[plaintext[i] - 'a'];
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = toupper(cipher_sequence[plaintext[i] - 'A']);
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char cipher_sequence[MAX_KEY];
    char plaintext[MAX_PLAINTEXT];

    generate_cipher_sequence(keyword, cipher_sequence);

    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_PLAINTEXT, stdin);
    plaintext[strlen(plaintext) - 1] = '\0'; // remove newline character

    encrypt(plaintext, cipher_sequence);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}
