#include<stdio.h>
//給予一個整數N 其中0<N<100000,他們要求Flash 跑到N 的位置再折返回來。
//過程中都有相機記錄Flash 的位置，請輸出Flash的移動軌跡。以證明Flash沒有空間跳躍的能力。
//例子：N=5輸出："123454321\n" （不用空格）Input Format輸入一個整數N 0<N<10000.Output Format一串數字，Flash的移動軌跡。(沒有空格)
int main(){
	
	int number;
	scanf("%d",&number);
	int i=0,k;
	k=number;
	for (i=1;i<=(2*k)-1;i++){
		if(i<=k){ 
		printf("%d",i);}
		else{
		number=number-1;
			printf("%d",number);
		}
	}
	printf("\n");
}
