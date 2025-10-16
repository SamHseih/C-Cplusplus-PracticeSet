#include <stdio.h>

int main(){

//宣告 decl
int a = 10;
int *ptr1 = &a;
int **ptr2 = &ptr1;
printf("a = %d\n", a); //10
printf("ptr1 mem = %x\n",ptr1); //10記憶體位置
printf("*ptr1 value= %d\n",*ptr1); //10
printf("ptr2 mem = %x\n", ptr2); // 記憶體位置
printf("*ptr2 mem = %x\n", *ptr2); // 記憶體位置
printf("**ptr2 value = %d\n", **ptr2); // 10


//use
a = 25;            // 直接存取變數
int *ptr_a = &a;
int **ptr_ptr_a=&ptr_a;
printf("a = %d\n", a); //25

*ptr_a = 20;       // 間接修改 a
**ptr_ptr_a = 30;  // 透過雙重指標修改 a
printf("ptr_a= %p\n",ptr_a); //30記憶體位置
printf("*ptr_a = %d\n", *ptr_a); //30
printf("**ptr_ptr_a = %d\n", **ptr_ptr_a); // 30
}