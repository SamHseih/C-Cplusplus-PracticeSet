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



void hanoi(int n,char from,char mid,char to,int *p){  // n為 在搬動第n個圓盤時
	
	if(n==0){return;}
	hanoi(n-1,from,to,mid,p);// 先將第n-1個圓盤搬到”中間塔/目標塔”
	printf("plate %d from %c -> %c\n",n,from,to);// 將自己搬到”目標塔
			p[n-1]++;
	hanoi(n-1,mid,from,to,p);// 再將第n-1個圓盤從”中間塔”搬回來		
}
