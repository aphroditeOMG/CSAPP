#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmeb, size_t size){
    size_t p = nmeb * size;
    if(nmeb == 0 || size == 0|| p / nmeb != size)
        return NULL;
    void *head = malloc(p);
    memset(head, 0, p);
    return head;
}

int main(){

    return 0;
}
