#include<stdio.h>

int main(){
	int i,j,k,l,tem;
	int sum=0;	
	int a[3][3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&k);
			//printf("k= %d\n",k);
			a[i][j]=k;
			//printf("a[%d][%d]=> %d\n",i,j,a[i][j]);
		}
	}
	
	printf("a¯x°}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",a[i][j]);}
			printf("\n");
	} printf("\n");
	
}
