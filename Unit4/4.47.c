#include <stdio.h>

void bubble_p(long *data, long count) {
	long i, last;
	for(last = count-1; last > 0; last--) {
		for(i = 0; i < last; i++)
			if (*(data+i+1) < *(data+i)) {
				long t = *(data+i+1);
				*(data+i+1) = *(data+i);
				*(data+i) = t;
				/*
				*(data+i+1) ^= *(data+i);
				*(data+i) ^= *(data+i+1);
				*(data+i+1) ^= *(data+i);
				*/
			}
	}
}

/**
(a ^ b) ^ b = a;
(a ^ b) ^ a = b;
*/

int main() {
	long a[] = {1,8,2,5,9,3,4};
	bubble_p(a, 7);
	int i;
	for(i = 0; i < 7; i++){
		printf("%ld\n",a[i] );
	}

	return 0;
}
