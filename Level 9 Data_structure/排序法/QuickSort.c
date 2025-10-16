#include<stdio.h>
#include<stdlib.h>
#define N 6 
void swap(int *p,int *b);
void quickSort(int *numbers,int low,int high);
int main(){
	int i;
	int n;
	puts("輸入Data數 :");
	scanf("%d",&n);
	int *a;
	a=(int*)malloc(sizeof(int)*n);
	puts("輸入Data:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++){
		printf("%d ",a[i]);	
	}puts("");
	
	quickSort(a,0,n-1);

	for(i=0;i<n;i++){
		printf("%d ",a[i]);	
	}
	return 0;
}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void quickSort(int *numbers,int low,int high){
	
	int i,j,l,pivot;
	i=low+1; //直接跳過 pivot 不會多做一次 
	j=high;
	pivot=numbers[low];
	
	//printf("pivot = %d  low= %d high= %d\n",pivot,low,high);
	
	do{
		while(numbers[i]<pivot&&i<high){
			i++;
			//printf("i = %d\n",i);
		}
		while(numbers[j]>pivot&&j>=0){
			j--;
			//printf("j = %d\n",j);
		}
		if(i<j){
			swap(&numbers[i],&numbers[j]);
			//puts("交換1次");

		}
	}while(i<j);
	//printf("我是準備跟pivot交換的J=%d  值為=\n",j,numbers[j]); 
	/*for(i=0;i<6;i++){
		printf("*%2d ",numbers[i]);	
	}puts("");*/
	numbers[low]=numbers[j];
	numbers[j]=pivot;

	if(j-1>low){
		quickSort(numbers,low,j-1);
	}
	if(j+1<high){
		quickSort(numbers,j+1,high);

	}
}
