#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
 size_t i;
 for(i = 0; i < len; i++)
        printf(" %.2x",start[i]);
 printf("\n");
}

void show_int(int x){
show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
show_bytes((byte_pointer) &x, sizeof(void *));
}

int main(void){
    test_int();
    printf("\n");
    test_float();
    printf("\n");
    test_byte();
    printf("\n");
}

void test_int(){
    int i;
    int x;
    for(i = 0x1; i < 0xf; i++){
          x = i;
          show_int(x);
    }
    for(i = 0xffff1; i < 0xfffff; i++){
          x = i;
          show_int(x);
    }
}

void test_float(){
    int i;
    float u = 0.0222;
    for(i = 0; i < 10; i++){
        show_float(u++);
    }
}

void test_byte(){
    int i;
    char m[10];
    show_pointer(m);
    for( i = 0; i < 10; i++){
            show_pointer(m[i]);
    }
}
