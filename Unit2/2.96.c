#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;
typedef unsigned char *byte_pointer;

int multi(int exp,int number)
{
    if(exp < -23)
    {
        return 0;
    }
    else if(exp < 0)
    {
        return number >> -exp;
    }
    else if (exp >= 8)
    {
        return 0x80000000;
    }
    else
    {
        return number << exp;
    }
}

/*
 * Compute (int f)
 * If Conversion causes overflow or f is NaN, return x80000000
 */

int float_f2i(float_bits f)
{
    unsigned exp = f >> 23 & 0xff ;
    unsigned frac = f & 0x007fffff;
    unsigned number = 0x00800000 + frac;
    int real_exp = exp;
    if(!(exp ^ 0xff))
    {
        return 0x80000000;
    }
    else if(!(exp ^0xff) || exp < 0x7f)
    {
        return 0;
    }
    else if(f & 0x80000000)
    {
        return -multi(real_exp - 0x7f -23, number);
    }
    return multi(real_exp - 0x7f -23, number);
}

int main()
{
    unsigned i;
    float test;
    unsigned u;
    int flag = 1;
    for(i = 0; i <= -1; i++)
    {
        test = *(float *)&i;
        u = (int)test;
        if(u != float_f2i(i))
        {
            flag = 1;
            printf("%x %x %x\n", i, u, float_f2i(i));
        }
    }
    printf("Flag is %d\n", flag);
    return 0;
}
