#include <stdio.h>

// Function to encrypt using affine Caesar cipher
char encrypt(char p, int a, int b) {
    return ((a * (p - 'A') + b) % 26) + 'A';
}

// Function to decrypt using affine Caesar cipher
char decrypt(char c, int a, int b)
 {
    int a_inv = 0;
    for (i = 1; i < 26; i++)
	 {
        if ((a * i) % 26 == 1) 
		{
            a_inv = i;
            break;
        }
    }
    return ((a_inv * (c - 'A' - b)) % 26) + 'A';
}

int main() {
    char plaintext[100], ciphertext[100];
    int a, b;
    printf("Enter a plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strlen(plaintext) - 1] = '\0'; // remove the newline character
    printf("Enter values for a and b: ");
    scanf("%d %d", &a, &b);
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = encrypt(plaintext[i], a, b);
    }
    ciphertext[strlen(plaintext)] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
    char decryptedtext[100];
    for (int i = 0; i < strlen(ciphertext); i++) {
        decryptedtext[i] = decrypt(ciphertext[i], a, b);
    }
    decryptedtext[strlen(ciphertext)] = '\0';
    printf("Decrypted text: %s\n", decryptedtext);
    return 0;
}
