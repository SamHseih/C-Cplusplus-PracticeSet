#include<stdio.h>

int C(int,int);

int main(){
	
	int n,m;
		scanf("%d%d",&n,&m);
	if(m>n) printf("input error");
	else {
			printf("%d\n",C(n,m));
	
	}
}


int C(int n, int m){
	

	if(n==m||m==0) return 1;
	else {
		return(C(n-1,m)+C(n-1,m-1));
	}
	
}

