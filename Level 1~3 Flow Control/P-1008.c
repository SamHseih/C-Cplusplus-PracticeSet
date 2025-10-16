#include<stdio.h>

int main(){
	
	int number;
	int sum=0;
	int i=0;
	scanf("%d",&number);
	while(number!=0){
		int temp=number%10;
		sum=sum+temp;
		number=number/10;
	}
	printf("%d",sum);
	return 0;
	
}
