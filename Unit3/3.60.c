#include <stdio.h>

long  loop(long x, int n){
	long res = 0;
	long mask;
	for(mask = 1; mask !=0; mask <<(n %256)) 
	{
	res |= (mask & x);
	}
	return res;
}

int main() {
	return 0;
}

