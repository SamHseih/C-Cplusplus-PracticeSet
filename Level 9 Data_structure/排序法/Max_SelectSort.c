#include<stdio.h>
#include<stdlib.h>

void callbyaddress_swap(int *a,int *b);
void print(int n,int *p);
int *selectMax(int n,int*p);


int main(){
	

	int i,j;
	int *p,*Max;
	int n;
	puts("請輸入Data總數 :");
	scanf("%d",&n);
	p=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	print(n,p);
	
	puts("進去囉");
	for(i=0;i<n-1;i++){
	printf("pass [%d] =>\n",(i+1));
		Max=selectMax(n-1-i,p);
		callbyaddress_swap(&p[n-1-i],Max);
		print(n,p);
	}
	puts("出來囉");
	print(n,p);
	
	free(p);
	
	
	return 0;
}


void callbyaddress_swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void print(int n,int *p){
	int i=0;
	printf("a= { ");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("}\n");
	
}

int *selectMax(int n,int*p){
	int i;
	int *max=&p[0];
	printf("Initial = %d\n",p[i]);
	for(i=0;i<n;i++){
		if(*max<p[i+1]){
			max=&p[i+1];
			printf("Max= %d\n",p[i+1]);
		}
	}
	
	return max;
	}
	


