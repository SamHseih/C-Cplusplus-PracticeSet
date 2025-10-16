#include<stdio.h>

int main(){
	
	int number;
	scanf("%d",&number);
	for(int i=0;i<number;i++){
		for(int j=0;j<number-i;j++){
			printf("*");
		}
		if(i!=number-1){
			printf("\n",i);
		}
	}
	
	return 0;
}
