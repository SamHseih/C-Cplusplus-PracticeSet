#include<stdio.h>

int main(){
	
	int number;
	scanf("%d",&number);
	for(int i=1;i<=number;i++){  // ��Ji �@�] i�h 
		
		for(int k=1;k<=number-i;k++){ // ��J �� i �h "�Ů� "�ƥ� 
			printf(" ")	;
			}
		
		for(int j=1;j<=i;j++){  // ��J�� i �h�� * �ƥ� 
				printf("*");
			}
			if(i!=number)	printf("\n",i);  // ���� for loop i �h�L�@��Ŧ� 
			
		}
	
	return 0;
}
