#include<stdio.h>
#include<stdlib.h>

int main() {
  
  int i = 10;
  int k;
  int *p;
  
  p = &i;
  printf("p = %p\n", p);  // ��ӰO�����} 
  printf("*p = %d\n", *p); //10 
  k = *p;  //k = 10
  printf("k = %d\n", k); //10

  *p = 125; //i=125
  
  printf("*p = %d\n", *p);  //125  
  printf("i = %d\n", i);   //125 
  printf("k = %d\n", k); //10 
  //p=777;  //�o�O�@�ӿ��~���ާ@�A���i�������ܼ�assign �@�Ӿ�ơA�]�������ܼƴN�O�n�s  �O�����}��!!!  �ҥH�Acomplier�| ĵ�i�A!!! 

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
