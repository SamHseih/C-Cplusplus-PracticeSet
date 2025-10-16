#include<stdio.h>
#include<stdlib.h>

void callbyaddress_swap(int *a,int *b);
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
	
	//int a[8]={10,9,5,4,6,8,7,2};
	
	for(i=n-1;i>=1;i=i-1){
	printf("pass [%d] =>\n",(n-i));
	 for(j=0;j<i;j++){
		if(p[j]>p[j+1]){
				//puts("近來囉3");
				callbyaddress_swap(&p[j],&p[j+1]);}
				printf("run [%d] => ",(j));
				print(n,p);
			
		}
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
