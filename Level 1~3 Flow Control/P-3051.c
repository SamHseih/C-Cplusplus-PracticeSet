#include<stdio.h> 

// ���m�߬�*���t�Ͼ� 
//�иյۿ�J�@�Ʀrn�æL�X�@���׬�n���t�Ͼ�
// *���ӼƬ��_�ơA�C�h���P�����W�G��

int main(){
	
	int number;
	scanf("%d",&number);
	for(int i=0;i<number;i++){  // ��Ji �@�] i�h 
		
		for(int k=1;k<number-i;k++){ // ��J �� i �h "�Ů� "�ƥ� 
			printf(" ")	;
			}
		
		for(int j=1;j<=2*i+1;j++){  // ��J�� i �h�� * �ƥ� 
				
				printf("*");
			}
		if(i+1<number)	printf("\n");  // ���� for loop i �h�L�@��Ŧ� 
		}
	
	return 0;
}
