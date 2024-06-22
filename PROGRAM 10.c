#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to create the Playfair matrix
void create_playfair_matrix(char key[], char matrix[SIZE][SIZE]) {
    int i, j, k = 0;
    char alphabet[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    // Create the key matrix
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (k < strlen(key)) {
                matrix[i][j] = toupper(key[k]);
                k++;
            } else {
                int found = 0;
                for (int i = 0; i < SIZE * SIZE; i++) {
                    for (int m = 0; m < SIZE; m++) {
                        if (matrix[l / SIZE][m] == alphabet[i * SIZE + j]) {
                            found = 1;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (!found) {
                    matrix[i][j] = alphabet[i * SIZE + j];
                }
            }
        }
    }
}

// Function to encrypt the message using the Playfair cipher
void encrypt_playfair(char message[], char matrix[SIZE][SIZE]) {
    int i, j, k = 0;
    char ciphertext[100];

    // Remove spaces and convert to uppercase
    for (i = 0; i < strlen(message); i++) {
        if (message[i] != ' ') {
            message[k++] = toupper(message[i]);
        }
    }
    message[k] = '\0';

    // Encrypt the message
    i = 0;
    while (message[i] != '\0') {
        int row1, col1, row2, col2;
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (matrix[j][k] == message[i]) {
                    row1 = j;
                    col1 = k;
                }
                if (matrix[j][k] == message[i + 1]) {
                    row2 = j;
                    col2 = k;
                }
            }
        }

        // Rules for encryption
        if (row1 == row2) {
            ciphertext[i] = matrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            ciphertext[i] = matrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }

        i += 2;
    }
    ciphertext[i - 1] = '\0';

    printf("Encrypted text: %s\n", ciphertext);
}

int main() {
    char key[] = "MFHIJKUNOPQZVWXYELARGDSTBC";
    char matrix[SIZE][SIZE];
    char message[] = "Must see you over Cadogan West. Coming at once.";

    create_playfair_matrix(key, matrix);

    encrypt_playfair(message, matrix);

    return 0;
}
