#include<stdio.h>
#include<stdlib.h>
 

int main(){

int *ptr;
int n,i=0,k;
scanf("%d",&n);
//printf("n=> %d\n",n);
ptr=(int*)malloc(sizeof(int)*n);

	do{
		scanf("%d",&k);
		ptr[i]=k;
	//	printf("\n");
		i++;
	}while(i!=n);


//printf("請輸入要搜尋的數值 : ");
scanf("%d",&k);	//printf("\n==========================\n");
int flag=0;
for(i=0;i<n;i++){
	if(ptr[i]==k){
		printf("found %d",k);
		flag=flag+1;
		break;
	}
}

if(flag==0){
	printf("not found");
}

free(ptr);

return 0;
}
