#include<stdio.h>
#include<stdlib.h>
 

int main(){

int *ptr;
int n,i=0,k;
printf("�аݭn��J�X�Ӿ��:");
scanf("%d",&n);
//printf("n=> %d\n",n);
ptr=(int*)malloc(sizeof(int)*n);
	if(ptr==NULL){
		printf("�O����Ŷ�����,�L�k�t�m.....\n");
		exit(0);
	}
else {

	do{

		printf("��J�� %d �Ӿ�� :",i+1);
		scanf("%d",&k);
		ptr[i]=k;
		printf("\n");
		i++;
	}while(i!=n);

/*	for(i=0;i<n;i++){
		printf("��%d�Ӿ�� --> %d\n",i+1,ptr[i]);
	}*/
}
printf("�п�J�n�j�M���ƭ� : ");
scanf("%d",&k);	printf("\n==========================\n");
int flag=0;
for(i=0;i<n;i++){
	if(ptr[i]==k){
		printf("%d �O�� %d �ӼƦr",k,i+1);
		flag=flag+1;
		break;
	}
}

if(flag==0){
	printf("�S���o�ӼƦr-> %d",k);
}

free(ptr);

return 0;
}
