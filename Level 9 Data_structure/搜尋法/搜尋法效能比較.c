#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
int BinSearch(int a[],int key,int n); // 此n為陣列的末端位置, 總共n+1個data 
int linearSearch(int a[],int key,int n);  
void print(int n,int *p); //n筆Data 

int main(){
	int a[N]={0};
	int i=0,j=0,k=0,key; //i為目前data數目  
	clock_t t1,t2;
	int t=100;
		for(k=0;k<N;k++){
			a[k]=i+1;
		}

			
		t1=clock();
		for(k=0;k<t;k++){ //printf("%d",k);	
			for(i=0;i<N;i++){
				linearSearch(a,i,N);
			//if( k==-1)puts("not found\n");
			//else printf("found %d\n",a[k]);
			}	
		}
		t2=clock();		//print(i,a);
		printf("LinearSearch 花費 : %.2f time.. \n", (t2-t1)/(double)(CLOCKS_PER_SEC));
		
		
		
		t1=clock();
		for(k=0;k<t;k++){//printf("%d",k);	
				for(i=0;i<N;i++){
			BinSearch(a,i,N);
				}
			}
		t2=clock();		//print(i,a);
		
		printf("BinSearch 花費 : %.2f time.. \n", (t2-t1)/(double)(CLOCKS_PER_SEC));
	
  }
int linearSearch(int a[],int key,int n){ //線性搜尋 
	int i=0;
	while(key!=a[i]){
		//printf("%d: %d\n",i,a[i]);
		i++;
		if(key==a[i]){//printf("%d: %d\n",i,a[i]);
		return i;
		}
		else if(i>=n-1){//printf("%d: %d\n",i,a[i]);
		break;
		}
	}
	return -1;
}

int BinSearch(int a[],int key,int n){  //二元搜尋 
	int l,u,m;
	//print(n,a);
	l=0;
	u=n;
		while(l<=u){
			m=(l+u)/2;
			//printf("我是中心值 %d\n",a[m]);
			//printf("%d: %d\n",m,a[m]);
			if(a[m]==key){
				
				return m;
			}
			else if(a[m]>key){
				u=m-1;
				
				//printf("我是上限 %d\n",a[u]);
			}
			else if(a[m]<key){
				l=m+1;
				//printf("我是下限 %d\n",a[l]);
			}	
		}
	return -1;
}

void print(int n,int *p){  //進行列印 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	
}
