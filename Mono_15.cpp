#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function to calculate letter frequencies in the given text
void calculateLetterFrequencies(const char *text, int frequencies[]) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            frequencies[text[i] - 'A']++;
        }
    }
}

// Function to find the index of the most frequent letter in frequencies array
int findMaxFrequencyIndex(const int frequencies[]) {
    int maxIndex = 0;
    for (int i = 1; i < ALPHABET_SIZE; i++) {
        if (frequencies[i] > frequencies[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to decrypt the text using the given key
void decryptText(const char *ciphertext, const char *key, char *plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] == ' ') {
            plaintext[i] = ' ';
        } else {
            plaintext[i] = key[ciphertext[i] - 'A'];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    const char *ciphertext = "YOUR CIPHERTEXT HERE"; // Replace this with your ciphertext
    int frequencies[ALPHABET_SIZE] = {0};

    // Calculate letter frequencies in the ciphertext
    calculateLetterFrequencies(ciphertext, frequencies);

    // Find the index of the most frequent letter in the ciphertext
    int maxFrequencyIndex = findMaxFrequencyIndex(frequencies);

    // Assuming 'E' is the most common letter in English
    int keyShift = (maxFrequencyIndex + ALPHABET_SIZE - ('E' - 'A')) % ALPHABET_SIZE;

    // Generate decryption key based on the shift
    char key[ALPHABET_SIZE + 1];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        key[i] = 'A' + (i + keyShift) % ALPHABET_SIZE;
    }
    key[ALPHABET_SIZE] = '\0';

    // Decrypt the ciphertext using the key
    char plaintext[strlen(ciphertext) + 1];
    decryptText(ciphertext, key, plaintext);

    printf("Decryption Key: %s\n", key);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}

