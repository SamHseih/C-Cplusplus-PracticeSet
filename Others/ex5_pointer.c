#include<stdio.h>
#include<stdlib.h>
 

int main(){

int *ptr;
int n,i=0,k;
printf("請問要輸入幾個整數:");
scanf("%d",&n);
//printf("n=> %d\n",n);
ptr=(int*)malloc(sizeof(int)*n);
	if(ptr==NULL){
		printf("記憶體空間不足,無法配置.....\n");
		exit(0);
	}
else {

	do{

		printf("輸入第 %d 個整數 :",i+1);
		scanf("%d",&k);
		ptr[i]=k;
		printf("\n");
		i++;
	}while(i!=n);

/*	for(i=0;i<n;i++){
		printf("第%d個整數 --> %d\n",i+1,ptr[i]);
	}*/
}
printf("請輸入要搜尋的數值 : ");
scanf("%d",&k);	printf("\n==========================\n");
int flag=0;
for(i=0;i<n;i++){
	if(ptr[i]==k){
		printf("%d 是第 %d 個數字",k,i+1);
		flag=flag+1;
		break;
	}
}

if(flag==0){
	printf("沒有這個數字-> %d",k);
}

free(ptr);

return 0;
}
