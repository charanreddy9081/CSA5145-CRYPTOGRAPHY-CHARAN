#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to decrypt the Playfair cipher
void decrypt_playfair(char ciphertext[], char key[]) {
    int i, j, k = 0;
    char plaintext[100];
    char key_matrix[SIZE][SIZE];
    char temp;

    // Create the key matrix
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            key_matrix[i][j] = key[k++];
            if (k == strlen(key)) {
                k = 0;
                while (key_matrix[i][j] == key[k] || key_matrix[i][j] == 'J') {
                    key_matrix[i][j] = 'A' + (k % 26);
                    k++;
                }
            }
        }
    }

    // Decrypt the ciphertext
    i = 0;
    while (ciphertext[i] != '\0') {
        int row1, col1, row2, col2;
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (key_matrix[j][k] == ciphertext[i]) {
                    row1 = j;
                    col1 = k;
                }
                if (key_matrix[j][k] == ciphertext[i + 1]) {
                    row2 = j;
                    col2 = k;
                }
            }
        }

        // Rules for decryption
        if (row1 == row2) {
            plaintext[i] = key_matrix[row1][(col1 - 1 + SIZE) % SIZE];
            plaintext[i + 1] = key_matrix[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) {
            plaintext[i] = key_matrix[(row1 - 1 + SIZE) % SIZE][col1];
            plaintext[i + 1] = key_matrix[(row2 - 1 + SIZE) % SIZE][col2];
        } else {
            plaintext[i] = key_matrix[row1][col2];
            plaintext[i + 1] = key_matrix[row2][col1];
        }

        i += 2;
    }
    plaintext[i - 1] = '\0';

    printf("Decrypted text: %s\n", plaintext);
}

int main() {
    char ciphertext[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    char key[] = "PLAYFAIR";

    decrypt_playfair(ciphertext, key);

    return 0;
}
