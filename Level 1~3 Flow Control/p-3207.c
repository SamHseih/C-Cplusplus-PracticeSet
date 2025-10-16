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
	int tax1=round(tax);
	int taxpay=tax1-discount;
	printf("%g%c ",taxrate*100,37); //tax rate
	printf("%d ",tax1); //tax 
	printf("%d ",discount); //discount
	printf("%d ",taxpay); //taxpay
	return 0; 
} 
	float TaxRate(int income)
	{
		float rate;
		switch(income){
		
			case 0 ...540000:
				rate=0.05;
				break;
			case 540001 ...1210000:
				rate=0.12;
				break;
			case 1210001 ...2420000:
				rate=0.20;
				break;
			case 2420001 ...4530000:
				rate=0.3;
				break;
			case 4530001 ...10310000:
				rate=0.4;
				break;
			default :
				rate=0.45;
		}
		//printf("In Function-Taxrate : %g\n",rate);
		return rate;
	}
	
	int Discount(int income)
	{
		int discount;
		switch(income){
		
			case 0 ...540000:
				discount=0;
				break;
			case 540001 ...1210000:
				discount=37800;
				break;
			case 1210001 ...2420000:
				discount=134600;
				break;
			case 2420001 ...4530000:
				discount=376600;
				break;
			case 4530001 ...10310000:
				discount=829600;
				break;
			default :
				discount=1345100;
		}
		//printf("In Function-Discount : %d\n",discount);
		return discount;
	}
	
	
	
