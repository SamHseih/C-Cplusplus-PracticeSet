#include<stdio.h>

void token(int);


int main(){

int number;
int i=0,k;
scanf("%d",&number);
if(number<=99999&&number>=1){

k=number/10000;
	if(k!=0)
		{	token(k); 
		printf("�U");
	number=number%10000;}
		//printf("���ɪ�number: %d\n",number);	
k=number/1000;
	if(k!=0){
	 	token(k);
		printf("�a");
	number=number%1000;}
		//printf("���ɪ�number: %d\n",number);
k=number/100;
	if(k!=0){
		token(k); 
		printf("��");
	number=number%100;}
		//printf("���ɪ�number: %d\n",number);
k=number/10;
	if(k!=0){
		token(k); 
		printf("�B");
	number=number%10;}
		//printf("���ɪ�number: %d\n",number);	
k=number/1;
	if(k!=0){
		token(k); } 
	printf("����");
		//printf("���ɪ�number: %d\n",number);
}
else
	printf("out of range");
}

void token(int input){
	switch(input){
		case 1:
			printf("��");
			break;
		case 2:
			printf("�L");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("�v");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("��");
			break;
		case 7:
			printf("�m");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("�h");
			break;
	}
}
