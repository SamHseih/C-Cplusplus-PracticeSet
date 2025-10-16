#include <stdio.h>

int main(void) {
    int a, b, temp;
    int *p1, *p2;
    printf("請輸入 a 的值："); 
    scanf("%d", &a);
    printf("請輸入 b 的值：");
    scanf("%d", &b);

    p1 = &a;
    p2 = &b;

    if(*p1 < *p2){
      temp = *p1;
      *p1 = *p2;
      *p2 = temp;
    }
    printf("*p1的值：%d\n", *p1);
    printf("*p2的值：%d\n", *p2);
}
