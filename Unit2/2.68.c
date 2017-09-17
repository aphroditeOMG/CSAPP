#include <stdio.h>
#include <limits.h>

/*
 *Mask with least significant n bits set to 1
 *Example : n=6 --> 0x3F, n=17 --> 0x1FFFF
 *Assume 1 <= n <= w
 */
int lower_one_mask(int n){
    unsigned trial = -1;
    return (int) (trial >> ( 8 * sizeof(int) -n ));
}

int main(){
    int i;
    for(i = 1 ; i <= 32 ; i ++){
    printf("%x\n", lower_one_mask(i));
    }
    return 0;
}
