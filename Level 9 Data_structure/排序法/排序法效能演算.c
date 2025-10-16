#include <windows.h>
#include <time.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 1000

void Insert(int *p,int key,int i);
void Insort(int *a,int n);
void print(int n,int *p);
void callbyaddress_swap(int *a,int *b);
int *selectMin(int n,int*p);
void quickSort(int *numbers,int low,int high);

int main(){
	clock_t t1,t2;
	int i,j,q;
	int t=900;  //重複執行次數 
	int p[N];  //原陣列 
	int k[N];  //將要被排序的陣列 
	srand((unsigned)time(NULL));
	
	for(i=0;i<N;i++){
		//p[i]=i+1; //best case
		p[i]=N-i; //worst case
		//p[i]=rand(); //random case
	}
	
	//print(N,p);
	
	t1=clock();
	for(q=0;q<t;q++){
	memcpy(k,p,sizeof(int)*N);
			for(i=N-1;i>=1;i--){
				 for(j=0;j<i;j++){
					if(k[j]>k[j+1]){
						callbyaddress_swap(&k[j],&k[j+1]);}
						}//print(N,k);
			}
			//printf("%d",q);
	}
	t2=clock();
	printf("BubbleSort 花費 : %.2f time.. \n", (t2-t1)/(double)(CLOCKS_PER_SEC));
	
	t1=clock();		
	for(q=0;q<t;q++){
	memcpy(k,p,sizeof(int)*N);
		
			int *Min;
				for(i=0;i<N-1;i++){
					Min=selectMin(N-1-i,k+i);
					callbyaddress_swap(&k[i],Min);
					//print(t,k);
					}
					//printf("%d",q);
		}t2=clock();
		printf("SelectionSort 花費 : %.2f time.. \n", (t2-t1)/(double)(CLOCKS_PER_SEC));	

	
	t1=clock();	
	for(q=0;q<t;q++){	
	memcpy(k,p,sizeof(int)*N);
	//print(t,k);
		
			//puts("進去插入排序囉\n");
				Insort(k,N);//printf("%d",q);
		}
		t2=clock();
		printf("InsertionSort 花費 : %.2f time.. \n", (t2-t1)/(double)(CLOCKS_PER_SEC));	

	t1=clock();	
	for(q=0;q<t;q++){	
	memcpy(k,p,sizeof(int)*N);
	//print(t,k);
		
			//puts("進去快速排序囉\n");
				quickSort(k,0,N-1);
			//	printf("%d",q);
		}
		t2=clock();
		printf("QuickSort 花費 : %.2f time.. \n", (t2-t1)/(double)(CLOCKS_PER_SEC));
return 0;

}
		

void callbyaddress_swap(int *a,int *b){ //SelectionSort、Bubblesort、Quicksort用 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


void Insert(int *p,int key,int i){  // 將data r 插入  以排序好陣列p 之中  n為p之data總數 
	
	int j=i;
	//printf("我是Key = %d\n",key);
	while(key<p[j]&&j>=0){
		//printf("我是 P[%d] = %d\n",j,p[j]);
		p[j+1]=p[j];
		j=j-1;
	}
	p[j+1]=key;
}


void Insort(int *a,int n){  //進行 n-1 次的Insort
	int i;
	for(i=1;i<n;i++){  
		//printf("Pass :%d ==>\n",i); 
		Insert(a,a[i],i-1);
		//print(n,a);
	}	
}


void print(int n,int *p){  //進行列印 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	
}

int *selectMin(int n,int*p){  // SelectionSort 用 
	int i=0;
	int *min=&p[0];
	//printf("Initial = %d\n",p[i]);
	for(i=0;i<n;i++){
		if(*min>p[i+1]){
			min=&p[i+1];
		}
	}//printf("Min= %d\n",*min);
	
	return min;
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
			callbyaddress_swap(&numbers[i],&numbers[j]);
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
	
	
