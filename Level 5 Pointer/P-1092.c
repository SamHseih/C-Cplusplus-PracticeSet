#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int *p,int n);
void callbyaddress_swap(int *a,int *b);
void print(int n,int *p);


int main(){
	//int a[8]={10,9,5,4,6,8,7,2};	BubbleSort(a,8); output:2,4,5,6,7,8,9,10
	int i,n,value;
	scanf("%d",&n);
	int *p;
	p=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&value);
		p[i]=value;
	}
	BubbleSort(p,n);

}

void BubbleSort(int *p,int n){
	int i,j,flag=0;
	for(i=n-1;i>=1;i=i-1){   //跑n-1次 
	//printf("pass [%d] =>\n",(n-i));
	 flag=1;
	 for(j=0;j<i;j++){
		if(p[j]>p[j+1]){
				//puts("近來囉3");
				callbyaddress_swap(&p[j],&p[j+1]);flag=0;}
				//printf("run [%d] => ",(j));
				//print(n,p);
		if(flag==1){printf("跳\n");break;}
		}
	if(flag==1){printf("跳\n");break;}
	print(n,p);puts("");
	
	}
	//puts("出來囉");
	print(n,p);
}

void callbyaddress_swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void print(int n,int *p){
	int i=0;

	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}

	
}
