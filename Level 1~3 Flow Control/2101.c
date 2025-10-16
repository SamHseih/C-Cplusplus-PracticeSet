#include<stdio.h>
#include<math.h>
	float TaxRate(int);
	int Discount(int);
	
int main(){	
		
	int income;
	
	scanf("%d",&income);
	
	float taxrate=TaxRate(income);
	int discount=Discount(income);
	float tax=income*taxrate;
	tax=round(tax);
	float taxpay=tax-discount;
	printf("income %d\n",income);
	printf("tax rate %.0f%%\n",taxrate*100); //.0f 為小數點後0位 
	printf("tax %.0f\n",tax);     
	printf("discount %d\n",discount);
	printf("taxpay %.0f",taxpay);
	
	return 0; 
} 
	float TaxRate(int income)
	{
		float rate;
		switch(income){
		
			case 1 ...370000:
				rate=0.06;
				break;
			case 370001 ...990000:
				rate=0.13;
				break;
			case 990001 ...1980000:
				rate=0.21;
				break;
			case 1980001 ...3720000:
				rate=0.3;
				break;

			default :
				rate=0.4;
		}
		//printf("In Function-Taxrate : %g\n",rate);
		return rate;
	}
	
	int Discount(int income)
	{
		int discount;
		switch(income){
		
			case 1 ...370000:
				discount=0;
				break;
			case 370001 ...990000:
				discount=25900;
				break;
			case 990001 ...1980000:
				discount=105100;
				break;
			case 1980001 ...3720000:
				discount=283300;
				break;

			default :
				discount=655300;
		}
		//printf("In Function-Discount : %d\n",discount);
		return discount;
	}
	
	
	
