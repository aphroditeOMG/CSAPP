#include <stdio.h>

long decode2(long x, long y, long z){
	y -= z;
	return  ((y << 63) >> 63) ^ (x * y);
}

int main(){
	return 0;
}


