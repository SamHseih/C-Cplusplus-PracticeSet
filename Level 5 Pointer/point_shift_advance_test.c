#include <stdio.h>

int main(){
int aa[] = {2, 4, 6, 8, 10};
int *ptr = aa;
int *qptr = aa + 2;

printf("%d\n", *ptr++ + *++qptr); //2 + 8 = 10
printf("%d\n", *ptr);//4
printf("%d\n", *qptr);//8

int a[] = {10, 20, 30};
int *p = a;
int **pp = &p;

printf("%d\n", **pp); //10
(*pp)++; // == p++
printf("%d\n", **pp);//20
printf("%d\n", *p);//20
}