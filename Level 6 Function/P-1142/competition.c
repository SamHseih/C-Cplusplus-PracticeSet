#include <stdio.h>
#include <stdlib.h>
#include "competition.h"
#include<string.h>
void competition(int *a,int n){
    int *temp=(int*)malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++){
    	temp[i]=a[n-i-1];
	}
	//printf("temp[]= ");
	//for(i=0;i<n;i++){printf("%d ",temp[i]);}puts("");
	for(i=0;i<n;i++){a[i]=temp[i];}
	//printf("a[]= ");
	//for(i=0;i<n;i++){printf("%d ",a[i]);}puts("");
	free(temp);
}
