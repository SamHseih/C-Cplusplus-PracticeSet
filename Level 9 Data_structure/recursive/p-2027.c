#include<stdio.h>

 
int Fac(int n);

int main(){
	int n,FacN;
	scanf("%d",&n);
	FacN=Fac(n);
	printf("%d",FacN);
}


int Fac(int n){
	if(n==1) return 1;
	else {
	return n*Fac(n-1);
	}
	
}
