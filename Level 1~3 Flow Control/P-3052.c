#include<stdio.h> 

// ���m�߬��٧θ�*���t�Ͼ� 
//�иյۿ�J�@�Ʀrn�æL�X�@���׬�n�����
//���ӼƬ��_�ơA�C�h���P�����W/��G��


int main(){
	
	int number;
	scanf("%d",&number);
	 
	for(int i=0;i<number;i++){  // ��Ji �@�] i�h 
		
		
		
			if(i<=number/2){ //0�� number/2 �h���W  
		
				for(int k=0;k<number/2-i;k++){ // ��J �� i �h "�Ů� "�ƥ� 
					printf(" ")	;}
		
				for(int j=1;j<=2*i+1;j++){  // ��J�� i �h�� * �ƥ� 
					printf("*");}
			} 
		
			else if(i>number/2){  //number/2 ~ number-1 �h����  
			
				for(int k=0;k<i-number/2;k++){ // ��J �� i �h "�Ů� "�ƥ� 
					printf(" ")	;}
		
				for(int j=1;j<=2*(number-i)-1;j++){  // ��J�� i �h�� * �ƥ� 
				
					printf("*");}
			}
		
		
		
		if(i+1<number)	printf("\n"); // ���� for loop i �h�L�@��Ŧ� 
	}
	
	return 0;
}
