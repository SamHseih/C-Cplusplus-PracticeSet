#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "competition.h"
 
int main(){
    int N,i;
    int *A;
    //N=指標陣列A的容量。
    scanf("%d",&N);
    A = (int *)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){scanf("%d",&A[i]);}
    competition(A,N);
    for(i=0;i<N;i++){printf("%d ",A[i]);}
    printf("\n");
    free(A);
}
