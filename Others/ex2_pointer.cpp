#include <stdio.h>

int main(){
	
	int a;
	int* p1;
	char b;
	p1=&a;
	b=33; 
	printf("b�����e    :\n");
	for(int i=0;i<=9;i++){
			for(int j=0;j<=9;j++){
		 		printf("%c ",b);
		 		b=b+1;}
				printf("\n");
	}
	printf("b����      : %d\n",b);	
	printf("b����m    : %p\n",&b);
	printf("b+1����m  : %p\n",&b+1);
	printf("a����m    : %p\n",&a);
	printf("a+1����m  : %p\n",&a+1);
	printf("p1����m   : %p\n",&p1);
	printf("p1+1����m : %p\n",&p1+1);
	return 0;
}
