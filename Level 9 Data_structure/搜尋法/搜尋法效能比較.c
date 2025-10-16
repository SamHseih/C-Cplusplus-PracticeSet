#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
int BinSearch(int a[],int key,int n); // ��n���}�C�����ݦ�m, �`�@n+1��data 
int linearSearch(int a[],int key,int n);  
void print(int n,int *p); //n��Data 

int main(){
	int a[N]={0};
	int i=0,j=0,k=0,key; //i���ثedata�ƥ�  
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
		printf("LinearSearch ��O : %.2f time.. \n", (t2-t1)/(double)(CLOCKS_PER_SEC));
		
		
		
		t1=clock();
		for(k=0;k<t;k++){//printf("%d",k);	
				for(i=0;i<N;i++){
			BinSearch(a,i,N);
				}
			}
		t2=clock();		//print(i,a);
		
		printf("BinSearch ��O : %.2f time.. \n", (t2-t1)/(double)(CLOCKS_PER_SEC));
	
  }
int linearSearch(int a[],int key,int n){ //�u�ʷj�M 
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

int BinSearch(int a[],int key,int n){  //�G���j�M 
	int l,u,m;
	//print(n,a);
	l=0;
	u=n;
		while(l<=u){
			m=(l+u)/2;
			//printf("�ڬO���߭� %d\n",a[m]);
			//printf("%d: %d\n",m,a[m]);
			if(a[m]==key){
				
				return m;
			}
			else if(a[m]>key){
				u=m-1;
				
				//printf("�ڬO�W�� %d\n",a[u]);
			}
			else if(a[m]<key){
				l=m+1;
				//printf("�ڬO�U�� %d\n",a[l]);
			}	
		}
	return -1;
}

void print(int n,int *p){  //�i��C�L 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	
}
