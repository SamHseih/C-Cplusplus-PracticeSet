#include<stdio.h>

void unitsdigit(int);
void tensdigit(int);

int main(){

int number;
int i=0,k;
scanf("%d",&number);
if(number<=9999999&&number>=2){

k=number/1000000;
	if(k!=0)
		{	unitsdigit(k); 
		printf(" million ");
	number=number%1000000;}
		//printf("234567此時的number: %d\n",number);	
k=number/100000;
	if(k!=0){
	 	unitsdigit(k);
		printf(" hundred ");
	number=number%100000;}
		//printf("34567此時的number: %d\n",number);	
k=number/1000;
	if(k!=0){
	tensdigit(k);
	unitsdigit(k);
		printf(" thousand ");
	number=number%1000;}
		//printf("567此時的number: %d\n",number);

k=number/100; 
	if(k!=0){
	 	unitsdigit(k);
		printf(" hundred ");
	number=number%100;}
		//printf("67此時的number: %d\n",number);	
if(number!=0){
		tensdigit(number);
		unitsdigit(number); } 
	printf(" dollars");
}
else if(number==1){
	printf("one dollar");
}
else
	printf("out of range");
}


void unitsdigit(int input){
	switch(input){
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
		case 20:
			printf("twenty");
			break;
		case 30:
			printf("thirty");
			break;
		case 40:
			printf("forty");
			break;
		case 50:
			printf("fifty");
			break;
		case 60:
			printf("sixty");
			break;
		case 70:
			printf("seventy");
			break;
		case 80:
			printf("eightty");
			break;
		case 90:
			printf("ninety");
			break;
		
	}
}

void tensdigit(int input){
		switch(input){
		case 10:
			printf("ten");
			break;
		case 11:
			printf("eleven");
			break;
		case 12:
			printf("twelve");
			break;
		case 13:
			printf("thirteen");
			break;
		case 14:
			printf("fourteen");
			break;
		case 15:
			printf("fifteen");
			break;
		case 16 ...19:
			input=input%10;
			unitsdigit(input);
			printf("teen");
			break;
		case 21 ...29: case 31 ...39: case 41 ...49: case 51 ...59: case 61 ...69: case 71 ...79: case 81 ...89: case 91 ...99:{
			int k=input-input%10;
			unitsdigit(k);
			printf(" "); 
			input=input%10;
			unitsdigit(input);
			break;}
	}
	}

