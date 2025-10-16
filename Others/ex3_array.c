#include<stdio.h>

int main(){
	
	int a[3][4];
	int i,j,k=1;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			a[i][j]=k;
			k=k+1;
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%2d ",a[i][j]);   //2d 代表可佔兩隔 對齊用 
		}printf("\n");
	}
	
}
