#include<stdio.h>
#include<time.h>
int main(){
	
	int a[7];
	int i,r,j=1;
	int number[48];
	int dim=48;
	for(i=0;i<48;i++)
		{number[i]=i+1;
			printf("**a[%d] => %d \n",i,a[i]);}
	for(i=0;i<48;i++){
		printf("a[%d] => %d \n",i,a[i]);}
	srand(time(NULL));
	
	for(i=0;i<7;i++){
		r=rand()%dim;
		a[i]=number[r];
		number[r]=number[dim-1];
		dim=dim-1;
	}
	
		printf("�����j�ֳz �q���︹ ���X�p�U:\n");
	for(i=0;i<7;i++){
		if(i<6){printf(" %d ",a[i]);
		}
		
		else{printf("\n");
	printf("�S�O�� : %d",a[i]);}
	return 0;
	}
}

//���m�߬��j�ְ����       �{���X�����D�A�|����M ex2 �����T�d�� 
