#include <stdio.h>

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
   Assume w = 32*/
    int any_odd_one(unsigned x){
    return !!(x & 0x01010101);
    }

int main(){
    printf("%d\n", any_odd_one(0x01010101));
    printf("%d\n", any_odd_one(0x11111111));
    printf("%d\n", any_odd_one(0x10101010));
    printf("%d\n", any_odd_one(0x00000000));
    return 0;
}
