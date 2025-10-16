//請試著輸入一數字n , 並印出一棵豪華聖誕樹。
//樹葉由三層一組，底部由 n2-1 的'^'開始建立起來。
//然後建了三層后就變成 (n-1)2-1 的 '^'。
//重複動作直到最上層的 '^'。
//'^'號個數為奇數。
//最頂部有一顆'*'號。
//樹印好后還有高度為 n-2 ,厚度為 n-2 的 樹幹。符號為'#'。

#include<stdio.h>

int main(){
	
	int number;
	scanf("%d",&number);
	
	for(int i=0;i<number;i++){  //共跑number層數
	 
		if (i==0){ 
			for(int b=1;b<number;b++){ //第1層中的某層空白數目 
					printf(" ");}
			printf("*\n");} 
		
		else if(i!=0&&i<=number-2){
			int a=i;
			for(int l=0;l<3;l++){ //第i層中的樹葉
				for(int j=0;j<number-a;j++){ //第i層中的某層空白數目 
					printf(" ");}
				for(int k=1;k<=(2*a-1);k++){ //第i層中的某層^數目 
					printf("^");}
				a=a+1;  //local i 遞迴變數 
				printf("\n"); 
			}
		}
		else if(i!=0&&i==number-1){
		
			for(int h=1;h<=number-2;h++){
				for(int j=0;j<number/2+1;j++){ //樹幹中的每層空白數目 
					printf(" ");}
				for(int w=1;w<=number-2;w++){
					printf("#");}
			if (h!=number-2)printf("\n");
			}
		}
				
	}
	return 0; 	
}
