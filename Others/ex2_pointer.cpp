#include <stdio.h>

int main(){
	
	int a;
	int* p1;
	char b;
	p1=&a;
	b=33; 
	printf("b的內容    :\n");
	for(int i=0;i<=9;i++){
			for(int j=0;j<=9;j++){
		 		printf("%c ",b);
		 		b=b+1;}
				printf("\n");
	}
	printf("b的值      : %d\n",b);	
	printf("b的位置    : %p\n",&b);
	printf("b+1的位置  : %p\n",&b+1);
	printf("a的位置    : %p\n",&a);
	printf("a+1的位置  : %p\n",&a+1);
	printf("p1的位置   : %p\n",&p1);
	printf("p1+1的位置 : %p\n",&p1+1);
	return 0;
}
