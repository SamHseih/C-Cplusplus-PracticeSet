#include<stdio.h>
//�����@�Ӿ��N �䤤0<N<100000,�L�̭n�DFlash �]��N ����m�A���^�ӡC
//�L�{�������۾��O��Flash ����m�A�п�XFlash�����ʭy��C�H�ҩ�Flash�S���Ŷ����D����O�C
//�Ҥl�GN=5��X�G"123454321\n" �]���ΪŮ�^Input Format��J�@�Ӿ��N 0<N<10000.Output Format�@��Ʀr�AFlash�����ʭy��C(�S���Ů�)
int main(){
	
	int number;
	scanf("%d",&number);
	int i=0,k;
	k=number;
	for (i=1;i<=(2*k)-1;i++){
		if(i<=k){ 
		printf("%d",i);}
		else{
		number=number-1;
			printf("%d",number);
		}
	}
	printf("\n");
}
