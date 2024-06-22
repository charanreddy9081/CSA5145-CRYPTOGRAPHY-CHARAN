#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY 26
#define MAX_CIPHERTEXT 1000

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    int m0 = m;
    int x, y;
    int q, temp;

    x = 0;
    y = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        temp = m;
        m = a % m;
        a = temp;

        temp = x;
        x = y - q * x;
        y = temp;
    }

    if (y < 0)
        y += m0;

    return y;
}

// Function to decrypt the ciphertext using the affine cipher
void decrypt(char ciphertext[], int a, int b) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = ((ciphertext[i] - 'A' - b) * modInverse(a, 26)) % 26 + 'A';
    }
}

int main() {
    char ciphertext[MAX_CIPHERTEXT];
    int a, b;

    printf("Enter the ciphertext: ");
    fgets(ciphertext, MAX_CIPHERTEXT, stdin);
    ciphertext[strlen(ciphertext) - 1] = '\0'; // remove newline character

    // Assume the most frequent letter is 'B' and the second most frequent letter is 'U'
    // In the English language, the most frequent letter is 'E' and the second most frequent letter is 'T'
    // So, we can assume that 'B' corresponds to 'E' and 'U' corresponds to 'T'
    // Using the affine cipher formula: E = (a*P + b) mod 26, we can set up the following equations:
    // B = (a*E + b) mod 26
    // U = (a*T + b) mod 26
    // Substituting E = 4 and T = 19, we get:
    // B = (a*4 + b) mod 26
    // U = (a*19 + b) mod 26
    // Since B = 1 and U = 20, we can solve for a and b:
    // 1 = (a*4 + b) mod 26
    // 20 = (a*19 + b) mod 26
    // Solving the system of equations, we get a = 5 and b = 21

    a = 5;
    b = 21;

    decrypt(ciphertext, a, b);

    printf("Decrypted text: %s\n", ciphertext);

    return 0;
}
