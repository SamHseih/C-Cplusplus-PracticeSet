#include <stdio.h>

int add_one(int x) {
    return x + 1;
}

int square(int x) {
    return x * x;
}

int main(){

//函式指標
int (*a_func)(int); // 指向一個 int 函數 (int)
int (*arr_ptr_func[10])(int); // 有10個函式指標的陣列

a_func = add_one;
printf("a_func(5) = %d\n", a_func(5)); // 6

arr_ptr_func[0] = add_one;
arr_ptr_func[1] = square;

printf("arr_ptr_func  = %p\n", arr_ptr_func[0] ); // 記憶體位置 0xc9481450
printf("arr_ptr_func  = %p\n", arr_ptr_func[1] ); // 記憶體位置 0xc948145f
printf("arr_ptr_func  = %d\n", arr_ptr_func[0](10) ); // 11
printf("arr_ptr_func  = %d\n", arr_ptr_func[1](10) ); // 100
}