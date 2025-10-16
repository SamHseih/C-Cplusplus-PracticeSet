#include<stdio.h>
#include<stdlib.h>

void Insert(int *p,int key,int i);
void Insort(int *a,int n);
void print(int n,int *p);

int main(){
	
	int i,j;
	int *p;
	int n;
	puts("請輸入Data總數 :");
	scanf("%d",&n);
	p=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	
	print(n,p);
	Insort(p,n);
	free(p);
return 0;
}

void Insert(int *p,int key,int i){  // 將data key插入以排序好陣列p之中 從第i開始判斷 
	
	int j=i;  
	printf("我是Key = %d\n",key);
	while(key<p[j]&&j>=0){    // true 2必要條件  1. 即將插入的位置比key大  2. j不是-1  
		printf("我是 P[%d] = %d\n",j,p[j]);  
		p[j+1]=p[j];  // 先把key之前的值複製，並後移後，覆蓋key值 
		j=j-1;
	}
	p[j+1]=key; //將key填入正確位置 
}


void Insort(int *a,int n){  
	int i;
	for(i=1;i<n;i++){  //進行 n-1 次的Insort
		//printf("Pass :%d ==>\n",i); 
		Insert(a,a[i],i-1); //從第二個data開始當key ,第i-1=0 開始判斷 
		print(n,a);
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
