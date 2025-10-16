#include<stdio.h>


int F(int, int ct[]);

int main(){
	
	int a=0;
	scanf("%d",&a);
	int i;
	int ct[a];
	for(i=0;i<=a;i++){
		ct[i]=0;
	}
	printf("%d\n",F(a,ct));
}


int F(int n, int ct[]){
  if(n==1||n==2)
    return 1;

  if(ct[n-1])
    return ct[n-1];
  
  int a = F(n-1, ct);
  int b = F(n-2, ct);
  ct[n-1] = a+b;
  return a+b;  
}
