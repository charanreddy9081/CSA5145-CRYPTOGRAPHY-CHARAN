#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CIPHERTEXT 1000

// Function to decrypt the ciphertext using a simple substitution cipher
void decrypt(char ciphertext[], char* alphabet) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = alphabet[ciphertext[i] - 'a'];
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = toupper(alphabet[ciphertext[i] - 'A']);
        }
    }
}

int main() {
    char ciphertext[MAX_CIPHERTEXT];
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    printf("Enter the ciphertext: ");
    fgets(ciphertext, MAX_CIPHERTEXT, stdin);
    ciphertext[strlen(ciphertext) - 1] = '\0'; // remove newline character

    // Assume the substitution is based on the frequency of letters in the English language
    // The most frequent letter in the English language is 'E', so we can assume that '‡' corresponds to 'E'
    // The second most frequent letter is 'T', so we can assume that '†' corresponds to 'T'
    // The third most frequent letter is 'A', so we can assume that ')' corresponds to 'A'
    // And so on...
    // We can create a substitution alphabet based on this frequency analysis
    char substitution_alphabet[] = "‡†)851JGXFZWBVKMDCLNHYOIUQT";
    for (int i = 0; i < 26; i++) {
        alphabet[substitution_alphabet[i] - 'A'] = 'A' + i;
    }

    decrypt(ciphertext, alphabet);

    printf("Decrypted text: %s\n", ciphertext);

    return 0;
}
