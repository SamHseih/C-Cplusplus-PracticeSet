#include<stdio.h>

int main(){
	
	int number;
	scanf("%d",&number);
	for(int i=0;i<number;i++){  // ��Ji �@�] i�h 
		
		for(int k=1;k<=i;k++){ // ��J �� i �h "�Ů� "�ƥ� 
			printf(" ")	;
			}
		
		for(int j=0;j<number-i;j++){  // ��J�� i �h�� * �ƥ� 
				printf("*");
			}
		if(i!=number-1){			// ���� for loop i �h���@��Ů�  
				printf("\n",i);
			}
		}
	
	return 0;
}
