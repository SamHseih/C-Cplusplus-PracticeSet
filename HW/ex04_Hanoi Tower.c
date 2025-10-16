#include<stdlib.h>
#include<stdio.h>

void hanoi(int n,char from,char mid,char to,int *p);

int main(){
	int n,i;
	scanf("%d",&n);
	
	int *p;
	p=(int*)calloc(n,sizeof(int));
	
	hanoi(n,'A','B','C',p);
	puts("");
	for(i=0;i<n;i++){
		printf("plate %d = %d\n",i+1,p[i]);
	}
	
	free(p);
	
	return 0;
}



void hanoi(int n,char from,char mid,char to,int *p){  // n�� �b�h�ʲ�n�Ӷ�L��
	
	if(n==0){return;}
	hanoi(n-1,from,to,mid,p);// ���N��n-1�Ӷ�L�h�졨������/�ؼж�
	printf("plate %d from %c -> %c\n",n,from,to);// �N�ۤv�h�졨�ؼж�
			p[n-1]++;
	hanoi(n-1,mid,from,to,p);// �A�N��n-1�Ӷ�L�q�������𡨷h�^��		
}
