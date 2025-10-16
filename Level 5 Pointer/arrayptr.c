#include <stdio.h>

int main(){
//array ptr
int arr[10]= {0,11,20,34,42,51,66,77,88,93}; // 10個int整數陣列
int *arr_ptr[10]; // 有10個元素，每個元素都是 int*（指向 int 的指標）
int (*ptr_arr)[10]; // 一個指向(10個int陣列)的指標

int * ptr = arr;
int x = *ptr++ + 1;

printf("*ptr++ = %d\n", x);// 先取值印出 0 +1後 向右位移
printf("*ptr = %d\n", *ptr); //11
int y = *++ptr + 1; //21 
printf("*++ptr = %d\n", y);
printf("*ptr = %d\n", *ptr);//20
printf("++*ptr = %d\n", ++*ptr);//21
printf("*ptr = %d\n", *ptr);//20  上一行改21了


for (int i = 0; i < 10; i++) {
    arr_ptr[i] = &arr[i]; // 每個 arr_ptr[i] 指向 arr[i]
}
printf("*arr_ptr[5] = %d\n", *arr_ptr[5]); // 5
printf("*arr_ptr[5] mem = %x\n", arr_ptr[5]); // 5
printf("arr[5] mem = %x\n", &arr[5]); // 5

ptr_arr = &arr; // ptr_arr 指向整個陣列 arr
printf("(*ptr_arr)[2] = %d\n", (*ptr_arr)[2]); // 2

}