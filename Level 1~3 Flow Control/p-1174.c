#include<stdio.h>

int main(){
	int i,j,k,l,tem;
	int sum=0;		
	int a[3][3];
	int b[3][3];
	int c[3][3]={0};  // ��C����l�� 
	
	/*for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			c[i][j]=0;  //��C����l�� 
		}
	}*/ 
	//printf("��Ja�x�}: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	//printf("��Jb�x�}: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			for(k=0;k<=2;k++){
				c[i][j]=c[i][j]+a[i][k]*b[k][j];  // �]�i�H�g	c[i][j]+=a[i][k]*b[k][j];
			}
		}	
	}
	
/*	printf("a�x�}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",a[i][j]);}
			printf("\n");
	} printf("\n");*/
	
	
/*	printf("b�x�}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",b[i][j]);}
			printf("\n");
	} printf("\n");*/
	
	
//	printf("c�x�}:\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",c[i][j]);}
			if(i!=2)printf("\n");
	} 
	
	return 0;
	
}
