#include <stdio.h>
/** return if x <= y */
unsigned int f2u(float x) {
	unsigned int *p = (unsigned int *)&x;
	return *p;
}

int float_lw(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy , sx,and sy */
    return  (sx > sy) || (sx == 1 && ux >= uy) || (sy == 0 && ux <= uy) || !(ux ||(uy- (sy << 31)))  ;
}

void test_float_lw(){
	int flag = 1;
	if(float_lw(0.0,-0.0) == 0) {
		flag = 0; 
		printf("1st case\n");
	}
	if(float_lw(0.5,0.3) == 1) {
		flag = 0; 
		printf("2nd case\n");
	}
	if(float_lw(-45.67,-23.5432) == 0) {
		flag = 0; 
		printf("3rd case\n");
	}
	if(float_lw(0.0,-0.3) == 1) {
		flag = 0; 
		printf("4th case\n");
	}
	if(float_lw(-0.0,0.0) == 0) {
		flag = 0; 
		printf("5th case\n");
	}
	if(flag == 1) {
		printf("passed\n");
	} else {
		printf("failed\n");
	}
}
int main() {
	test_float_lw();
	return 0;
}