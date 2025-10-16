#include<stdio.h>


float rate(int);


int main(){
	
	int income;
	scanf("%d",&income);
	float b=1;
	printf("лe %g\n",b);
	b=rate(income);
	printf("лс %g\n",b);
}

float rate(int income){
	float a=2;
	switch(income){
		case 1 ...5:  
			printf("0.06\n");
			a=0.06;
			break;
		case 6 ...7:
			printf("0.13\n");
			a=0.13;
			break;
		default :
			printf("0.16\n");
			a=0.16;
	}
	return a;
}
