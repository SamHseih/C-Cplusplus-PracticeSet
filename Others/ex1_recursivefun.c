#include<stdio.h>

int F(int);

int main(){
	
	unsigned long a;
	scanf("%d",&a);
	a=F(a);
	printf("%d\n",a);
}


int F(int n){
	
	unsigned long a[n];
	a[0]=0;
	if(n<=0){printf("Error\n");}
	else if(n==1)a[1]=1;
	else if(n==2)a[2]=1;
	else if(n>2){
		int i;
		a[0]=0;a[1]=1;a[2]=1;a[n]=0;
		for(i=1;i<=n-2;i++)
			{a[i+2]=a[i]+a[i+1];}
		}
	return a[n];
}

//¶O§B¯Ç«Y¼Æ½m²ß
 
