#include<stdio.h>

int main(){
	int i,j,k,l,tem;
	int sum=0;		
	int a[3][3];
	int b[3][3];
	int c[3][3];
	//printf("¿é¤Ja¯x°}: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&l);
			a[i][j]=l;
		}
	}
	
	//printf("¿é¤Jb¯x°}: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&l);
			b[i][j]=l;
		}
	}
	
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
	
/*	printf("a¯x°}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",a[i][j]);}
			printf("\n");
	} printf("\n");*/
	
	
/*	printf("b¯x°}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",b[i][j]);}
			printf("\n");
	} printf("\n");*/
	
	
//	printf("c¯x°}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",c[i][j]);}
			if(i!=2)printf("\n");
	} 
	
}
