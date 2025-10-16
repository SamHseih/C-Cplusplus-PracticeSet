#include<stdio.h>
#include<stdlib.h>

void callbyaddress_swap(int *a,int *b);
void print(int n,int *p);
int *selectMin(int n,int*p);


int main(){
	

	int i,j;
	int *p,*Min;
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
		Min=selectMin(n-1-i,p+i);
		callbyaddress_swap(&p[i],Min);
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

int *selectMin(int n,int*p){
	int i=0;
	int *min=&p[0];
	printf("Initial = %d\n",p[i]);
	for(i=0;i<n;i++){
		if(*min>p[i+1]){
			min=&p[i+1];
		}
	}printf("Min= %d\n",*min);
	
	return min;
	}
	


