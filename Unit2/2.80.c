#include <stdio.h>
#include <limits.h>
/** Round to 0*/
int threefourths(int x){
	/**Bias*/
	int sig = (((unsigned) x) >> ((sizeof(x) << 3)) - 1);
	/*trying to construct a bias such that we get what we want*/
    return ((x + (x << 1)) >> 2) +( sig && ((x | 0)&3)) ;
}
/** We simply assume that 3*x will not overflow at first,
/*  the expression on the book doesn't seem that explict*/

int main(){
    int i;
    for(i = 0; i >-10 ; i--){
        printf("%d\n", threefourths(i));
    }
    for(i = 0; i < 10 ; i++){
        printf("%d\n", threefourths(i));
    }
    return 0;
}
