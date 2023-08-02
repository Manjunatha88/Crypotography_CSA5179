#include <stdio.h>
#include <ctype.h>
void monoalphabeticEncrypt(char message[], char key[]) {
    char ch;
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        if (isalpha(ch)) {
            if (isupper(ch))
                message[i] = toupper(key[ch - 'A']);
            else
                message[i] = tolower(key[ch - 'a']);
        }
    }
}
void monoalphabeticDecrypt(char message[], char key[]) {
    char decryptedKey[26];
    for (int i = 0; i < 26; i++) {
        decryptedKey[key[i] - 'A'] = i + 'A';
    }
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            if (isupper(ch))
                message[i] = decryptedKey[ch - 'A'];
            else
                message[i] = tolower(decryptedKey[ch - 'a']);
        }
    }
}
int main() {
    char message[100];
    char key[] = "THEQUICKBROWNFXJMPSVLAZYDG";
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    monoalphabeticEncrypt(message, key);
    printf("Encrypted message: %s\n", message);
    monoalphabeticDecrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}
