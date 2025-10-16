#include<stdio.h>

void print(int n);
int Fac(int n);

int main(){
	int n,FacN;
	scanf("%d",&n);
	print(n);	
	FacN=Fac(n);
	printf("Fac = %d",FacN);
}


void print(int n){
	
	if(n<=1){
		printf("n= %d\n",n);
	}
	else {
	print(n-1);
	printf("n= %d\n",n); 
	}
}


int Fac(int n){
	if(n==1) return 1;
	else {
	return n*Fac(n-1);
	}
	
}
