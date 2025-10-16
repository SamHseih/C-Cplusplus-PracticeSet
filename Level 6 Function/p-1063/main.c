#include <stdio.h>
#include <stdlib.h>
#include "score.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n=0;
	int i,maxp=0;
	while(n<1||n>60000){
	scanf("%d",&n);
	if(n<=60000&&n>1)break;
	else puts("Error input");
	}
	int *p;
	p=(int*)malloc(sizeof(int)*n);
	inputAry(n,p);
	for(i=0;i<n;i++){
		if(MaxScore(n,p)==p[i]){maxp=i+1;break;}
	}
	printf("avg = %.2f\n",Avg(n,p));
	printf("highest:\n%d: %d",maxp,MaxScore(n,p));
	return 0;
}
