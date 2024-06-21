#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateMatrix(char key[], char matrix[5][5]) {
    int i, j, k, flag[26] = {0};
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    k = 0;
    for (i = 0; i < strlen(key); i++) {
        if (!flag[toupper(key[i]) - 'A']) {
            matrix[k / 5][k % 5] = toupper(key[i]);
            flag[toupper(key[i]) - 'A'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (!flag[i]) {
            matrix[k / 5][k % 5] = alphabet[i];
            k++;
        }
    }
}

void printMatrix(char matrix[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void playfairCipher(char str[], char matrix[5][5]) {
    int i, len = strlen(str);
    char temp[2];
    for (i = 0; i < len; i += 2) {
        temp[0] = str[i];
        temp[1] = (i + 1 < len)? str[i + 1] : 'X';
        if (temp[0] == temp[1]) {
            temp[1] = 'X';
        }
        int x1, y1, x2, y2;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (matrix[j][k] == temp[0]) {
                    x1 = j;
                    y1 = k;
                }
                if (matrix[j][k] == temp[1]) {
                    x2 = j;
                    y2 = k;
                }
            }
        }
        if (x1 == x2) {
            str[i] = matrix[x1][(y1 + 1) % 5];
            str[i + 1] = matrix[x2][(y2 + 1) % 5];
        } else if (y1 == y2) {
            str[i] = matrix[(x1 + 1) % 5][y1];
            str[i + 1] = matrix[(x2 + 1) % 5][y2];
        } else {
            str[i] = matrix[x1][y2];
            str[i + 1] = matrix[x2][y1];
        }
    }
}

int main() {
    char key[20], str[100];
    char matrix[5][5];
    printf("Enter a keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strlen(key) - 1] = '\0'; // remove the newline character
    generateMatrix(key, matrix);
    printf("Generated matrix:\n");
    printMatrix(matrix);
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // remove the newline character
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    playfairCipher(str, matrix);
    printf("Encrypted string: %s\n", str);
    return 0;
}
