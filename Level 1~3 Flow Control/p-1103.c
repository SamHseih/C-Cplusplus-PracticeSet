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
		printf("萬");
	number=number%10000;}
		//printf("此時的number: %d\n",number);	
k=number/1000;
	if(k!=0){
	 	token(k);
		printf("仟");
	number=number%1000;}
		//printf("此時的number: %d\n",number);
k=number/100;
	if(k!=0){
		token(k); 
		printf("佰");
	number=number%100;}
		//printf("此時的number: %d\n",number);
k=number/10;
	if(k!=0){
		token(k); 
		printf("拾");
	number=number%10;}
		//printf("此時的number: %d\n",number);	
k=number/1;
	if(k!=0){
		token(k); } 
	printf("元整");
		//printf("此時的number: %d\n",number);
}
else
	printf("out of range");
}

void token(int input){
	switch(input){
		case 1:
			printf("壹");
			break;
		case 2:
			printf("貳");
			break;
		case 3:
			printf("參");
			break;
		case 4:
			printf("肆");
			break;
		case 5:
			printf("伍");
			break;
		case 6:
			printf("陸");
			break;
		case 7:
			printf("柒");
			break;
		case 8:
			printf("捌");
			break;
		case 9:
			printf("玖");
			break;
	}
}
