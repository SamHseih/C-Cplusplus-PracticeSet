#include<stdio.h>
#include<stdlib.h>
struct _student{
	int number;
	int math;
	int english;
	int computer;
};
typedef struct _student student;


 int main(){
 	int num=0;
 	int i=0,k=1,j;	
	student s[5]={0};
	float Avgma=0,Avgeng=0,Avgcp=0;
 	do{ 
 		printf("�ثe�ǥͼ� : %d\n",i);
		printf("�п�� 1�s�W 2�C�L 3�ק� 4�L���� 5��N���� 6��ƥ���(�P��) 0���}:\n");
 		scanf("%d",&num);
 		
 		switch (num){
 			case 1:	{
 				printf("�s�W�P�Ǥ�..�п�J�ƾǡA�^��A�q�� :\n");
			 	if(i==5){printf("�H�Ƥw��");break;}
				else{
					s[i].number=k;
			 		scanf("%d",&s[i].math);
			 			Avgma+=s[i].math;
			 		scanf("%d",&s[i].english);
			 			Avgeng+=s[i].english;
			 		scanf("%d",&s[i].computer);
			 			Avgcp+=s[i].computer;			 			
					i++;
					k++;
					break;}
			 }
			 case 2:{
			 	printf("�C�L�P�Ǧ��Z��..�п�J�y��\n");
			 	scanf("%d",&num);
			 	printf("�ƾ�: %d\n",s[num-1].math);
			 	printf("�^��: %d\n",s[num-1].english);
			 	printf("�q��: %d\n",s[num-1].computer);
				break;
			 }
			 case 3:{
			 	printf("�ק�P�Ǧ��Z��..�п�J�y��\n");
			 	scanf("%d",&num);
			 		scanf("%d",&s[num-1].math);
			 		scanf("%d",&s[num-1].english);
			 		scanf("%d",&s[num-1].computer);
				break;
			 }
			 case 4:{
			 	printf("�C�L�Ҧ��P�Ǧ��Z��..\n");
			 	for(j=0;j<i;j++){
			 		printf("�ƾ�: %d\n",s[j].math);
			 		printf("�^��: %d\n",s[j].english);
			 		printf("�q��: %d\n",s[j].computer);
				 }
				break;
			 }
			 case 5:{
			 	printf("�C�L�������Z��..\n"); 
			 		printf("�ƾǥ���: %.2f\n",Avgma/i);
			 		printf("�^�奭��: %.2f\n",Avgeng/i);
			 		printf("�q������: %.2f\n",Avgcp/i);
				break;
			 }
			 case 6:{
			 	printf("�C�L�Y��P�ǥ������Z��..�п�J�y��\n");
				 	scanf("%d",&num);
				  	float tem=0;
					tem=(float)(s[num-1].math+s[num-1].english+s[num-1].computer)/3;
				  	printf("�������Z: %.2f\n",tem);
				break;
			 }
		}
	}while(num!=0);
return 0;
 }
