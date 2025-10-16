#include<stdio.h>

int main(){
	
	int number;
	scanf("%d",&number);
	for(int i=1;i<=number;i++){  // 輸入i 共跑 i層 
		
		for(int k=1;k<=number-i;k++){ // 輸入 第 i 層 "空格 "數目 
			printf(" ")	;
			}
		
		for(int j=1;j<=i;j++){  // 輸入第 i 層之 * 數目 
				printf("*");
			}
			if(i!=number)	printf("\n",i);  // 防止 for loop i 多印一行空行 
			
		}
	
	return 0;
}
