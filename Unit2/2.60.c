#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){
    unsigned char *u = &x;
    u[i] = b;
    return x;
}

int main(){
    printf("%x\n", replace_byte(0x12345678, 2, 0xAB));
    printf("%x\n", replace_byte(0x12345678, 0, 0xAB));
    return 0;
}
