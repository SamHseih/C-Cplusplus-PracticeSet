#include<stdio.h>

int maun(){
	
	int a[]={21,215,31,44,55};
	int i;
	for(i=0;i<5;i++){
		printf("a[%d]=> %d  ,mem= %d",i,a[i],&a[i]);
	}
	return 0;
}
