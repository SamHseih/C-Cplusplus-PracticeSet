#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 52
#define PEOPLE 4
#define HAND 13
#define SUIT 4

// // 3愛心 4菱形 5梅花 6黑桃 
int stack[MAX_SIZE];
int top=-1;
int push(int value);
int pop();
void reshuffle(int *p);
void Insert(int *p,int key,int i);
void Insort(int *a,int n);
void SortHand(int *p);

int main(){
	
	int i,j,k=0;
	int player[SUIT][HAND];
	for(i=0;i<MAX_SIZE;i++){stack[i]=i;}//初始化牌組 
	{//檢查初始化排組用
	/*for(i=0;i<PEOPLE;i++){
		for(j=0;j<HAND;j++){
		printf("%2d:%c%d ",stack[j+13*i],((stack[j+HAND*i])/HAND)+3,stack[j+HAND*i]%HAND+1);
		k++;
		}puts("\n\n");
	} */} 
	//洗牌並放入牌堆
	reshuffle(stack);  
	//發牌
	for(i=0;i<HAND;i++){          
		for(j=0;j<PEOPLE;j++){
			player[j][i]=pop();    
		}
	}
	for(i=0;i<PEOPLE;i++){
		printf("Player%d:\n",i+1); 
		for(j=0;j<HAND;j++){
		printf("[%c%2d] ",((player[i][j])/HAND)+3,player[i][j]%HAND+1);
		k++;
		}puts("\n");
	}  
	//數字排序
	for(i=0;i<PEOPLE;i++)Insort(player[i],HAND);  
	//花色排序
	for(i=0;i<PEOPLE;i++)SortHand(player[i]);  
	puts("");
	//列印
	for(i=0;i<PEOPLE;i++){
		printf("Player%d:\n",i+1); 
		for(j=0;j<HAND;j++){
		printf("[%c%2d] ",((player[i][j])/HAND)+3,player[i][j]%HAND+1);
		k++;
		}puts("\n");
	}  
	return 0;
}



int push(int value){
	if(top==MAX_SIZE-1){
		return -1;
	}	
		top++;
		stack[top]=value;
	
	return 1;
}

int pop(){
	int temp;
	if(top==-1){
		return -1;
	}
	temp=stack[top];
	stack[top]=0; //看資料是否敏感，此步驟可清可不清
	top--;
	return temp; 
}	

void reshuffle(int *p){
	
	srand(time(NULL));
	int i,r;
	int dim=MAX_SIZE;
	int a[MAX_SIZE];
	for(i=0;i<MAX_SIZE;i++){
		a[i]=p[i];
	}
	
	for(i=0;i<MAX_SIZE;i++){
		r=rand()%dim;
		//printf("R= %d\n",r);
		push(a[r]);
		a[r]=a[dim-1];		
		
		dim--;
	}
	
}

void Insert(int *p,int key,int i){  // 將data key插入以排序好陣列p之中 從第i開始判斷 
	
	int j=i;  
	//printf("我是Key = %d\n",key);
	while(key<p[j]&&j>=0){    // true 2必要條件  1. 即將插入的位置比key大  2. j不是-1  
		//printf("我是 P[%d] = %d\n",j,p[j]);  
		p[j+1]=p[j];  // 先把key之前的值複製，並後移後，覆蓋key值 
		j=j-1;
	}
	p[j+1]=key; //將key填入正確位置 
}

void Insort(int *a,int n){  
	int i;
	for(i=1;i<n;i++){  //進行 n-1 次的Insort
		//printf("Pass :%d ==>\n",i); 
		Insert(a,a[i],i-1); //從第二個data開始當key ,第i-1=0 開始判斷 
		//print(n,a);
	}	
}

void SortHand(int *p){
		int i=HAND-1;
		int s=0;
		while(i>=0){
		if(p[i]>=39){
				push(p[i]);}
				i--;
		}
		i=HAND-1;
		while(i>=0){
		if(p[i]<=12&&p[i]>=0){
				push(p[i]);}
				i--;
		}
		i=HAND-1;
		while(i>=0){
		if(p[i]<=25&&p[i]>=13){
				push(p[i]);}
				i--;
		}
		i=HAND-1;
		while(i>=0){
		if(p[i]<=38&&p[i]>=26){
				push(p[i]);}
				i--;
		}
	for(i=0;i<HAND;i++){
		p[i]=pop();
	}

}
