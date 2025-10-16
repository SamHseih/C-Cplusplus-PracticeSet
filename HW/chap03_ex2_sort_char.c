#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6
void Insert(char [][128],char r[128],int i);
void Insort(char s1[][128],int n);
void print(int n,char p[][128]);
void swap(char s1[][128],int q,int r); //同個陣列q元素與r交換
int *selectMin(int n,int*p);


int main(){
	
	int i,j,k;
	char s1[N][128];
	for(i=0;i<N;i++)
	scanf("%s",s1[i]);
	//print(N,s1);
	
	
	//puts("請輸入\n(1) 泡沫排序法\n(2) 選擇排序法 (找最大的移到最前)\n(3) 插入排序法 (從陣列第[1]開始往後輪流當key)");
	scanf("%d",&k);
	switch (k){
		case 1:{
			//puts("進去泡沫排序囉\n");
			
				for(i=N-1;i>=1;i=i-1){
						//printf("pass [%d] =>\n",(N-i));
	 				for(j=0;j<i;j++){
						if(strcmp(s1[j],s1[j+1])<0){
							//puts("近來囉3");
							swap(s1,j,j+1);
							//printf("run [%d] => ",(j));
							//print(N,s1);
						}
					}
				//puts("出來囉");
				print(N,s1);
				}
			print(N,s1);	
			break;
		}
		
		case 2:{
			int Max;
			//puts("進去囉");
				for(i=0;i<5;i++){
					//printf("pass [%d] =>\n",(i+1));
					Max=selectMax(6-i,&s1[i]);
					swap(s1,Max+i,i);
					print(6,s1);
					}
					//puts("出來囉");
					print(6,s1);
			break;
		}
		
		case 3:{
			//puts("進去插入排序囉\n");
				Insort(s1,6);	
				print(6,s1);
			break;
		}
	}
	return 0;
}

void swap(char s1[][128],int q,int r){ // ) 某陣列 , 第q項與第r項交換 
	
	char temp[128];
	strcpy(temp,s1[q]);
	strcpy(s1[q],s1[r]);
	strcpy(s1[r],temp);
	
}


void Insort(char s1[][128],int n){
	int i;
		for(i=1;i<n;i++){   //key值 由矩陣第二格開始往後跑  j在key值前 
			Insert(s1,s1[i],i-1);    
			print(6,s1); 
		}
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


void print(int n,char p[][128]){  //進行列印 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		//puts("");
		printf("%s ",p[i]);
	}
	printf("\n");
	
}

int selectMax(int n,char s1[][128]){ //selection 用 
	int i,k=0;
	char *max=s1[0];
	//printf("Initial = %s\n",max);
	for(i=0;i<n;i++){
		if(strcmp(max,s1[i])<0){
			max=s1[i];
			k=i;
			//printf("Max= %s\n",max);
		}
	}
	//printf("Max= %s\n",max);  
	//printf("k=> %d\n",k);
	
	return k;
	}
	
