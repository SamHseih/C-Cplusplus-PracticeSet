#include<stdio.h>

int main(){
	int i,j,k,l,tem;
	int sum=0;		
	int a[3][3];
	int b[3][3];
	int c[3][3]={0};  // 對C做初始化 
	
	/*for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			c[i][j]=0;  //對C做初始化 
		}
	}*/ 
	//printf("輸入a矩陣: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	//printf("輸入b矩陣: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			for(k=0;k<=2;k++){
				c[i][j]=c[i][j]+a[i][k]*b[k][j];  // 也可以寫	c[i][j]+=a[i][k]*b[k][j];
			}
		}	
	}
	
/*	printf("a矩陣:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",a[i][j]);}
			printf("\n");
	} printf("\n");*/
	
	
/*	printf("b矩陣:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",b[i][j]);}
			printf("\n");
	} printf("\n");*/
	
	
//	printf("c矩陣:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",c[i][j]);}
			if(i!=2)printf("\n");
	} 
	
	return 0;
	
}
