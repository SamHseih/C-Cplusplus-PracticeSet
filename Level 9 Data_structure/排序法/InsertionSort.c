#include<stdio.h>
#include<stdlib.h>

void Insert(int *p,int key,int i);
void Insort(int *a,int n);
void print(int n,int *p);

int main(){
	
	int i,j;
	int *p;
	int n;
	puts("�п�JData�`�� :");
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

void Insert(int *p,int key,int i){  // �Ndata key���J�H�ƧǦn�}�Cp���� �q��i�}�l�P�_ 
	
	int j=i;  
	printf("�ڬOKey = %d\n",key);
	while(key<p[j]&&j>=0){    // true 2���n����  1. �Y�N���J����m��key�j  2. j���O-1  
		printf("�ڬO P[%d] = %d\n",j,p[j]);  
		p[j+1]=p[j];  // ����key���e���Ƚƻs�A�ëᲾ��A�л\key�� 
		j=j-1;
	}
	p[j+1]=key; //�Nkey��J���T��m 
}


void Insort(int *a,int n){  
	int i;
	for(i=1;i<n;i++){  //�i�� n-1 ����Insort
		//printf("Pass :%d ==>\n",i); 
		Insert(a,a[i],i-1); //�q�ĤG��data�}�l��key ,��i-1=0 �}�l�P�_ 
		print(n,a);
	}	
}


void print(int n,int *p){  //�i��C�L 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	
}
