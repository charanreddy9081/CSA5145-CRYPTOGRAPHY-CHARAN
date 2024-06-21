#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monoalphabeticSubstitutionCipher(char str[], char key[]) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = toupper(key[str[i] - 'A']);
            } else {
                str[i] = tolower(key[str[i] - 'a']);
                
            }
        }
    }
}

int main() {
    char str[100];
    char key[26] = "JGURYXQVZWBELHIKMOTPFNCDAS";
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // remove the newline character
    monoalphabeticSubstitutionCipher(str, key);
    printf("Encrypted string: %s\n", str);
    return 0;
}
