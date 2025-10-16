#include<stdio.h>
#include<stdlib.h>

int main() {
  
  int i = 10;
  int k;
  int *p;
  
  p = &i;
  printf("p = %p\n", p);  // 原來記憶體位址 
  printf("*p = %d\n", *p); //10 
  k = *p;  //k = 10
  printf("k = %d\n", k); //10

  *p = 125; //i=125
  
  printf("*p = %d\n", *p);  //125  
  printf("i = %d\n", i);   //125 
  printf("k = %d\n", k); //10 
  //p=777;  //這是一個錯誤的操作，不可讓指標變數assign 一個整數，因為指標變數就是要存  記憶體位址的!!!  所以你complier會 警告你!!! 

	p=calloc(4,sizeof(int));
	
	for(i=0;i<4;i++){
		p[i]=i*i;
	}

	for( i=0;i<4;i++) {
      printf("~~~%d ",p[i]);
   }
	
	free(p);
  return 0;
}
