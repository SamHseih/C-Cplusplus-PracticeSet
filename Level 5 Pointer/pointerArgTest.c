#include<stdio.h>

int add(int* a, int* b){
    return *a + *b;
};

int sum(int* a , int size){
    int i,sum=0;
    for(i=0;i<size;i++){
        sum += a[i];
    }
    return sum;
}

int main(){
    int a = 5,b=10;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("a+b= %d\n", add(&a,&b));
    printf("sum= %d\n", sum(arr,10));
    return 0;

}