#include <stdio.h>

int main(void) {
    int b = 2;
    int* pointer = &b;

    printf("跑计 b %d\n", b);
    printf("跑计 b %p\n", &b);
    printf("pointer %p\n", pointer);
    printf("\n"); //传︽
    
    *pointer = 100;

    printf("*pointer %d\n", *pointer);
    printf("跑计 b %d\n", b);
    printf("跑计 pointer %p\n", &pointer);
    return 0;
}
