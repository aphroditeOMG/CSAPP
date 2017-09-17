#include <stdio.h>
#include <string.h>
/*Copy integer into buffer if space is available*/
/* Warning: The following code is buggy*/

void copy_int( int val, void *buf, int maxbytes){
    if (maxbytes - sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}

/** A. sizeof() returns size_t, which is unsigned, thus the expression
/*    maxbytes - sizeof(val) will be unsigned
/*    then it's always > = 0*/

/** B. the debugged version*/
/** as val is an integer, then its size will never be too large to be a negative number
/*  if we convert it to integer*/
void copy_int_debugged( int val, void *buf, int maxbytes){
    if (maxbytes - (int)sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}

int main(){
    return 0;
}
