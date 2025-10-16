#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Insert(char [][128],char r[128],int i);
void Insort(char s1[][128],int n);
void print(int n,char p[][128]);

int main(){
	
	int i,j;
	
	int n;
	char s1[6][128];
	
	for(i=0;i<6;i++)
	scanf("%s",s1[i]);
	
	Insort(s1,6);	
	print(6,s1);
	
return 0;
}

void Insert(char s1[][128],char r[128],int i){  // 將data key 插入  以排序好陣列s1[0]~s1[i]  
	char key[128]; //宣告要記錄key的值 
	strcpy(key,r);  //同上 
	int j;
	j=i;  //key值前一格一開始要比的對象  爾後j -- 直到0 
	
	//printf("key = %s\n",key);
	while(strcmp(s1[j],key)<0&&j>=0){  //比較 若key值較大，把陣列往後搬 而且為了防止無限輪迴 當j<0的時候停止 
		//printf("In while j= %d\n",j);  
		//printf("In while s1[%d]= %s\n",j,s1[j]);
		//printf("In while %c\n",s1[i]);
		strcpy(s1[j+1],s1[j]);   
		//printf("key = %s\n",key);
		//print(7,s1);
		j=j-1;
		//printf("In while j= %d\n",j);
	}
	//printf("出來while  key = %s\n",key);
	strcpy(s1[j+1],key);
	//printf("s1[j+1]= %s\n",s1[j+1]);
}

void Insort(char s1[][128],int n){
	int i;
		for(i=1;i<n;i++){   //key值 由矩陣第二格開始往後跑  j在key值前 
			Insert(s1,s1[i],i-1);    
			print(6,s1); 
		}
	}	

void print(int n,char p[][128]){  //進行列印 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		//puts("");
		printf("%s  ",p[i]);
	}
	printf("\n");
}

