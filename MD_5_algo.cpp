#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef union uwb {
    unsigned w;
    unsigned char b[4];
} MD5union;
typedef unsigned DigestArray[4];
typedef unsigned (*DgstFctn)(unsigned a[]);
unsigned func0(unsigned abcd[]) {
    return (abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]);
}
unsigned func1(unsigned abcd[]) {
    return (abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]);
}
unsigned func2(unsigned abcd[]) {
    return abcd[1] ^ abcd[2] ^ abcd[3];
}
unsigned func3(unsigned abcd[]) {
    return abcd[2] ^ (abcd[1] | ~abcd[3]);
}
unsigned rol(unsigned r, short N) {
    unsigned mask1 = (1 << N) - 1;
    return ((r << N) & ~mask1) | ((r >> (32 - N)) & mask1);
}
unsigned *md5(const char *msg, int mlen) {
}
int main() {
    const char *msg = "The quick brown fox jumps over the lazy dog";
    unsigned *d = md5(msg, strlen(msg));
    MD5union u;
    printf("\t MD5 ENCRYPTION ALGORITHM IN C \n\n");
    printf("Input String to be Encrypted using MD5 : \n\t%s", msg);
    printf("\n\nThe MD5 code for the input string is: \n");
    printf("\t= 0x");    
    for (int j = 0; j < 4; j++) {
        u.w = d[j];
        for (int k = 0; k < 4; k++) {
            printf("%02x", u.b[k]);
        }
    }
    printf("\n\n\t MD5 Encryption Successfully Completed!!!\n\n");
    return 0;
}
