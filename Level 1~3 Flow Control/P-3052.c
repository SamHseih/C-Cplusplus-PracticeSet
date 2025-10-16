#include<stdio.h> 

// 此練習為菱形號*號聖誕樹 
//請試著輸入一數字n並印出一高度為n之綾形
//號個數為奇數，每層之星號遞增/減二個


int main(){
	
	int number;
	scanf("%d",&number);
	 
	for(int i=0;i<number;i++){  // 輸入i 共跑 i層 
		
		
		
			if(i<=number/2){ //0到 number/2 層遞增  
		
				for(int k=0;k<number/2-i;k++){ // 輸入 第 i 層 "空格 "數目 
					printf(" ")	;}
		
				for(int j=1;j<=2*i+1;j++){  // 輸入第 i 層之 * 數目 
					printf("*");}
			} 
		
			else if(i>number/2){  //number/2 ~ number-1 層遞減  
			
				for(int k=0;k<i-number/2;k++){ // 輸入 第 i 層 "空格 "數目 
					printf(" ")	;}
		
				for(int j=1;j<=2*(number-i)-1;j++){  // 輸入第 i 層之 * 數目 
				
					printf("*");}
			}
		
		
		
		if(i+1<number)	printf("\n"); // 防止 for loop i 多印一行空行 
	}
	
	return 0;
}
