#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char str[], int k) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = 'A' + (str[i] - 'A' + k) % 26;
            } else {
                str[i] = 'a' + (str[i] - 'a' + k) % 26;
            }
        }
    }
}

int main() {
    char str[100];
    int k;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // remove the newline character
    printf("Enter the shift value (1-25): ");
    scanf("%d", &k);
    caesarCipher(str, k);
    printf("Encrypted string: %s\n", str);
    return 0;
}
