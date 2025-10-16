#include<stdio.h>

int main(){
	
	int number;
	scanf("%d",&number);
	for(int i=0;i<number;i++){  // 輸入i 共跑 i層 
		
		for(int k=1;k<=i;k++){ // 輸入 第 i 層 "空格 "數目 
			printf(" ")	;
			}
		
		for(int j=0;j<number-i;j++){  // 輸入第 i 層之 * 數目 
				printf("*");
			}
		if(i!=number-1){			// 防止 for loop i 多做一行空格  
				printf("\n",i);
			}
		}
	
	return 0;
}
