#include <stdio.h>
//所有 c 語言 都是 call by value 只是 有值 以及 address 而已
int B = 2;
int C = 3;
void func_calladdress(int *p){p = &B;}//只改了傳入的指標，但是是複製的改了無效。
void func_changevalue(int *p){*p = B;}//改變指標所指的值，故有效。
void func_changeptr(int **p){*p = &C;}//改了指標所指的指標，故有效。

void func_call_reference(int &p){p = B;}//改了指標所指的指標，故有效。
void func_call_reference_pointer(int *&p){p = &C;}//改了指標所指的指標，故有效。

int main(){
     int A = 1 ;
     int *ptrA = &A;

     printf("init  %d\n", *ptrA);
     func_calladdress(ptrA);
     printf("%d\n", *ptrA);//不是B???  還是A !!
     

     A = 1 ;
     ptrA = &A;//指回來
     printf("init  %d\n", *ptrA);
     func_changevalue(ptrA);
     printf("%d\n", *ptrA);// 是B!!

     A = 1 ;
     ptrA = &A;//指回來
     printf("init  %d\n", *ptrA);
     func_changeptr(&ptrA);
     printf("%d\n", *ptrA);// 此時 ptrA 已經指向C!!

     A = 1 ;
     ptrA = &A;//指回來
     printf("init  %d\n", *ptrA);// 是B!!

     //C++ 版本 call by reference 的 int 版本
     func_call_reference(A);
     printf("call by reference %d\n", *ptrA);// 是B!!

     A = 1 ;
     ptrA = &A;//指回來
     printf("init  %d\n", *ptrA);// 是B!!
     //C++ 版本 call by reference 的 pointer 版本
     func_call_reference_pointer(ptrA);
     printf("call by reference %d\n", *ptrA);// 是C!!
     return 0;
}