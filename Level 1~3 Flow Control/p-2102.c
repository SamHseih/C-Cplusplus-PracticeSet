#include<stdio.h>

int main(){
	
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	int b[3][3]={2,4,6,8,10,12,14,16,18};
	int c[3][3];
	int tem=0;
	int sum=0;
	int i,j,k;
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			tem=0;
			for(k=0;k<=2;k++){
				tem=a[i][k]*b[k][j];
				sum=sum+tem;
			}
			c[i][j]=sum;
			sum=0;
		}	
	}
	
	/*printf("a¯x°}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",a[i][j]);}
			printf("\n");
	} printf("\n");*/
	
	
	/*printf("b¯x°}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",b[i][j]);}
			printf("\n");
	} printf("\n");*/
	
	
	//printf("c¯x°}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",c[i][j]);}
			if(i!=2)printf("\n");
	} 
	
}

