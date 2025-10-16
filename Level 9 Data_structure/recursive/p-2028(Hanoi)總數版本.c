/*盒內塔每個圓盤有3個任務,
	第一個 在移動去目標塔之前把比它小的圓盤 們 移動去中間塔 
 	第二個 移動到目標塔
	第三個  把移到中間塔的圓盤 移去目標塔  

	所以要有雙遞迴
		 

*/


#include<stdio.h>

int hanoi(int n,char from,char mid,char to);


int main(){
	int n,i;
	scanf("%d",&n);
	n=hanoi(n,'A','B','C');
	printf("%d",n);
	return 0;
}

int hanoi(int n,char from,char mid,char to){  // n為 在搬動第n個圓盤時
	int count=0;
	if(n==0){return 0;}
	count=hanoi(n-1,from,to,mid);// 先將第n-1個圓盤搬到”中間塔/目標塔”
	count++;printf("圓盤%2d從%c塔-> %c塔\n",n,from,to);// 將自己搬到”目標塔
	count=count+hanoi(n-1,mid,from,to);// 再將第n-1個圓盤從”中間塔”搬回來		
	return count;
}
