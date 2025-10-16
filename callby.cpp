#include <stdio.h>

//call by value swap
void swap_value(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

//call by address/point swap
void swap_address(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//call by reference swap  for c++
void swap_ref(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int outA = 10;

int main(){
    int locala = 5;
    int localb = 10;
    printf("init: ");   
    printf("locala= %d , localb= %d \n",locala,localb);
    swap_value(locala,localb);
    printf("locala= %d , localb= %d \n",locala,localb);

    swap_address(&locala,&localb);
    printf("locala= %d , localb= %d \n",locala,localb);

    swap_ref(locala,localb);
    printf("locala= %d , localb= %d \n",locala,localb);

    //call by ref legal
    int i =42;
    const int &r = 42;
    const int &r2 = r + 1;

    printf("r= %d \n",r);
    printf("r2= %d \n",r2);

    //其實宣告 &名稱 並綁定另一個變數，就只是換名稱而已，叫做 alias (別名)使用
    const int ival = 1024;
    const int &refVal = ival;  // 合法
    //int &ref2 = ival;          // 不合法，ref2是nonconst

    int ival2 = 1024;
    int &refVal2 = ival2;  // 合法
    //int &refVal2;        // 不合法，reference必須被初始化
    //int &refVal3 = 10;   // 不合法，初值必須是object
}