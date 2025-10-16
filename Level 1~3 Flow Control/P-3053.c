#include<stdio.h>

int main(){
	int number;
	scanf("%d",&number);
	int i,j,k;
	for(i=1;i<=number;i++){	
		for(k=0;k<=(number-i-1);k++){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			if(j!=i)
			printf("* ");
			else
			printf("*");
		}
		if(i!=number){
				printf("\n");
			}
	}
	return 0;
}
