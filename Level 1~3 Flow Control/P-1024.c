//�иյۿ�J�@�Ʀrn , �æL�X�@�ʻ��ظt�Ͼ�C
//�𸭥ѤT�h�@�աA������ n2-1 ��'^'�}�l�إ߰_�ӡC
//�M��ؤF�T�h�Z�N�ܦ� (n-1)2-1 �� '^'�C
//���ưʧ@����̤W�h�� '^'�C
//'^'���ӼƬ��_�ơC
//�̳������@��'*'���C
//��L�n�Z�٦����׬� n-2 ,�p�׬� n-2 �� ��F�C�Ÿ���'#'�C

#include<stdio.h>

int main(){
	
	int number;
	scanf("%d",&number);
	
	for(int i=0;i<number;i++){  //�@�]number�h��
	 
		if (i==0){ 
			for(int b=1;b<number;b++){ //��1�h�����Y�h�ťռƥ� 
					printf(" ");}
			printf("*\n");} 
		
		else if(i!=0&&i<=number-2){
			int a=i;
			for(int l=0;l<3;l++){ //��i�h������
				for(int j=0;j<number-a;j++){ //��i�h�����Y�h�ťռƥ� 
					printf(" ");}
				for(int k=1;k<=(2*a-1);k++){ //��i�h�����Y�h^�ƥ� 
					printf("^");}
				a=a+1;  //local i ���j�ܼ� 
				printf("\n"); 
			}
		}
		else if(i!=0&&i==number-1){
		
			for(int h=1;h<=number-2;h++){
				for(int j=0;j<number/2+1;j++){ //��F�����C�h�ťռƥ� 
					printf(" ");}
				for(int w=1;w<=number-2;w++){
					printf("#");}
			if (h!=number-2)printf("\n");
			}
		}
				
	}
	return 0; 	
}
