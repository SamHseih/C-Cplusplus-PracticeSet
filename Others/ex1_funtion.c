#include<stdio.h>
float abc(int);
int main(){
	float x=123.11;
	printf("�e  x = %g\n",x);
	x=abc(2);
	printf("��  x = %g",x);	
} 

float abc(int a){
	double c=56.111;
	printf("call me");
	
	return c;
}
