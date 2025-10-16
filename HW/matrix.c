#include<stdio.h>

void Input2dAry(int [][3]);
void Print2dAry(int [][3]);
void MatrixMul2dAry(int [][3],int [][3],int [][3]);


int main(){
	int a[3][3];
	int b[3][3];
	int c[3][3]={0};
	Input2dAry(a);
	Input2dAry(b);
	MatrixMul2dAry(a,b,c);
	Print2dAry(c);
	return 0;
}



void Input2dAry(int a[][3]){
	int i,j,l;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
}


void Print2dAry(int a[][3]){
	int i,j;
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%-5d",a[i][j]);}
			if(i!=2)printf("\n");
	}
}



void MatrixMul2dAry(int a[][3],int b[][3],int c[][3]){
	int i,j,k;
	
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			for(k=0;k<=2;k++){
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
				}
			}
		}
}
