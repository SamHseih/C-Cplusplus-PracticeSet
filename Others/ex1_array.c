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
	
		printf("本期大樂透 電腦選號 號碼如下:\n");
	for(i=0;i<7;i++){
		if(i<6){printf(" %d ",a[i]);
		}
		
		else{printf("\n");
	printf("特別號 : %d",a[i]);}
	return 0;
	}
}

//此練習為大樂偷抽獎       程式碼有問題，尚待釐清 ex2 為正確範例 
