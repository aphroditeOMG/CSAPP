#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;
/** Compute -f. If f is NaN, then return f*/
float_bits float_negative(float_bits f){
    unsigned exp = f >> 23 & 0xff ;
    unsigned frac = f << 9;
    if(!(exp ^ 0xff) && frac){
        return f;
    }
    return f - 0x80000000;
}

int main(){
    unsigned i;
    float test;
    unsigned u;
    for(i = 0; i <= -1; i++){
        test = - *(float *)&i;
        u =  * (int *)&test;
        if(u != float_negative(i)){
            printf("%x %x %x\n", i, u, float_negative(i));
        }
    }
    /**comment : seems that system will change a NaN's symbol 
    /*   and convert the nearest bit from the exp bits, 
    /*   which is the first bit of the frac area to 1
    /*   /s  /11111111/ x......../
    /*   ->
    /*   /1-s/11111111/ 1......../
    /*   if we take its negative*/
    return 0;
}
