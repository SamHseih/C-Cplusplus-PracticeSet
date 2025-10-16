#include<stdio.h>
#include<stdlib.h>
#define N 6  
void Insert(int *p,int key,int i);
void Insort(int *a,int n);
void print(int n,int *p);
void callbyaddress_swap(int *a,int *b);
int *selectMin(int n,int*p);


int main(){
	int i,j,k=1;
	int *Min;
	int p[N]={0};
	
	for(i=0;i<N;i++){
		scanf("%d",&p[i]);
	}
	print(N,p);
	puts("請輸入\n(1) 泡沫排序法\n(2) 選擇排序法 (找最小的移到最前)\n(3) 插入排序法 (從陣列第[1]開始往後輪流當key)");
	scanf("%d",&k);
	switch (k){
		case 1:{
			//puts("進去泡沫排序囉\n");
			for(i=N-1;i>=1;i--){
				//printf("pass [%d] =>\n",(N-i));
				 for(j=0;j<i;j++){
					if(p[j]>p[j+1]){
						//puts("近來囉3");
						callbyaddress_swap(&p[j],&p[j+1]);}
					//printf("run [%d] => ",(j));
					//print(N,p);
			
				}print(N,p);
			}
				//puts("出來囉");
				print(N,p);
			break;
		}
		
		case 2:{
			//puts("進去選擇排序囉\n");
				for(i=0;i<N-1;i++){
					//printf("pass [%d] =>\n",(i+1));
					Min=selectMin(N-1-i,p+i);
					callbyaddress_swap(&p[i],Min);
					print(N,p);
					}
				//puts("出來囉");
				print(N,p);
			break;
		}
		
		case 3:{
			puts("進去插入排序囉\n");
				Insort(p,N);
				print(N,p);
			break;
		}	
	}
}

void callbyaddress_swap(int *a,int *b){ //SelectionSort、Bubblesort用 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Insert(int *p,int key,int i){  // 將data r 插入  以排序好陣列p 之中  n為p之data總數 
	
	int j=i;
	printf("我是Key = %d\n",key);
	while(key<p[j]&&j>=0){
		printf("我是 P[%d] = %d\n",j,p[j]);
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
	
