#include <stdio.h>

#define SIZE 25

int main() {
    // Calculate the number of possible keys
    long long possible_keys = 1;
    for (int i = 0; i < SIZE; i++) {
        possible_keys *= (26 - i);
    }
    printf("Number of possible keys: %lld (approximately 2^%.2f)\n", possible_keys, log2(possible_keys));

    // Calculate the number of effectively unique keys
    long long unique_keys = 1;
    for (int i = 0; i < SIZE; i++) {
        unique_keys *= (26 - i);
        if (i >= 2) {
            unique_keys /= i;
        }
    }
    printf("Number of effectively unique keys: %lld (approximately 2^%.2f)\n", unique_keys, log2(unique_keys));

    return 0;
}
