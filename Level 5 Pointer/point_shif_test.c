#include <stdio.h>


int main(){
//初階
int a[] = {10, 20, 30, 40, 50};
int *p = a;
printf("%d\n", *p++);//20 答錯!! 為 10 因為 parser 由左往右因此，會先取值後指標右移
printf("%d\n", *p);//10 答錯= = 你有看題目嗎?? 此時的指標已經在 a[1]了 故為20
printf("%d\n", *++p);//30 答錯!! 為 10 因為 parser 由左往右因此，會先取诶~ 但這裡發現++ 故會先++後取值
printf("%d\n", *p);//30 

//中階
int b[] = {10, 20, 30, 40, 50};
int *pp = b;
printf("%d\n", *++pp + *pp++); //20+20 = 40
printf("%d\n", *pp);//30

//高階
int c[] = {5, 10, 15, 20, 25};
int *pc = c;
int i = 1;
printf("%d\n", *(c + i++) + *(++pc)); // c[1]+c[1] = 20
printf("%d\n", *pc);//c[1] = 10
printf("%d\n", i);//i = 2 

//神奇編譯
int x[] = {5, 10, 15, 20, 25};
    i = 2;
    printf("x[%d]   = %d\n", i, x[i]);
    printf("*(x+%d) = %d\n", i, *(x + i));
    printf("%d[x]   = %d\n", i, i[x]);  // 超神奇但合法！

    // 額外驗證：印出位址
    printf("\n位址比較：\n");
    printf("&x[%d]  = %p\n", i, &x[i]);
    printf("x+%d    = %p\n", i, x + i);
    printf("i+x     = %p\n", i + x);
}