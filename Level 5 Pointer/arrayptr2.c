#include<stdio.h>
/*
++/--的位置，因為++/--的優先權(precedence)是高於*(dereference)的，因此:

a) *ptr++是表示*(ptr++)的意思，就是ptr指向下一個位置所存的值(同arr[i++])。
b)*++ptr是代表ptr先做位址往前移，再取值(同arr[++i])。
c) ++*ptr是表示++(*ptr)之意，即為ptr當下位置的值+1(同++arr[i])。

*/
int main(){

    int x = 5, y = 7;
    int *a[10];
    a[0] = &x; //5
    a[1] = &y; //7
    printf("a[0]= %x a[1]= %x\n",a[0],a[1]);

    printf("x= %d y= %d\n",x,y);
    printf("now~ %d\n",++*a[0]); // 先取值再遞增，先取a[0]指標後，進行*取值運算後再後置遞增
    printf("x= %d y= %d\n",x,y); // 6  7
 
    printf("*a[0]++ %d\n",*a[0]++); //優先順序 : [] > ++ > *  等價於 *(a[0]++)
    printf("x= %d y= %d\n",x,y);
    printf("*a+1= %d\n",*a+1);  //a++ 也不對 這邊 a 只是指到 a[0] 的記憶體變數，不能改變的!

    int b[4] = {1,5,7,45};
    int* ptr = b;
    printf("b[0]= %x b[1]= %x\n",&b[0],&b[1]);
    printf("++b[1]=  %d\n",++b[1]);

    printf("ptr =  %d\n",*ptr);
    printf("ptr =  %d\n",*++ptr);
    printf("ptr =  %d\n",*ptr);
    for(int i =0  ; i< 4;++i){
        printf("%d ",b[i]);
    }

    printf("\n");
    printf("ptr =  %d\n",*ptr++);
    printf("ptr =  %d\n",*ptr);
    printf("b[1]++ =  %d\n",b[1]++); 
    for(int i =0  ; i< 4;++i){
        printf("%d ",b[i]);
    }
}