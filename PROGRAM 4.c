#include <stdio.h>
#include <string.h>

// Function to generate a monoalphabetic substitution cipher table
void generateTable(char key[], char table[26]) {
    int i, j, k = 0;
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; i < 26; i++) {
        table[i] = '-';
    }
    for (i = 0; i < strlen(key); i++) {
        if (!strchr(table, toupper(key[i]))) {
            table[k++] = toupper(key[i]);
        }
    }
    for (i = 0; i < 26; i++) {
        if (!strchr(table, alphabet[i])) {
            table[k++] = alphabet[i];
        }
    }
}

// Function to encrypt using polyalphabetic substitution cipher
void polyalphabeticCipher(char plaintext[], char key[], char ciphertext[]) {
    int i, j, k = 0;
    char table[26];
    generateTable(key, table);
    for (i = 0; i < strlen(plaintext); i++) {
        j = (plaintext[i] - 'A' + (key[k % strlen(key)] - 'A')) % 26;
        ciphertext[i] = table[j];
        k++;
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[100], key[20], ciphertext[100];
    printf("Enter a plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strlen(plaintext) - 1] = '\0'; // remove the newline character
    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);
    key[strlen(key) - 1] = '\0'; // remove the newline character
    polyalphabeticCipher(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
