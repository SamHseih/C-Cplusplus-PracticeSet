#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char s1[][128],int q,int r); //同個陣列q元素與r交換
void print(int n,char p[][128]);
int selectMax(int n,char s1[][128]);


int main(){
	

	int i,j;
	int Max;
	char s1[6][128];
	
	for(i=0;i<6;i++)
	scanf("%s",s1[i]);
	
	//selectMax(6,s1);
	
	//puts("進去囉");
	for(i=0;i<5;i++){
	//printf("pass [%d] =>\n",(i+1));
		Max=selectMax(6-i,&s1[i]);
		swap(s1,Max+i,i);
		print(6,s1);
	}
	//puts("出來囉");
	print(6,s1);
	
	
	
	
	return 0;
}


void swap(char s1[][128],int q,int r){ // ) 某陣列 , 第q項與第r項交換 
	char temp[128];
	strcpy(temp,s1[q]);
	strcpy(s1[q],s1[r]);
	strcpy(s1[r],temp);
	
}

void print(int n,char p[][128]){  //進行列印 
	int i=0;
	//printf("a= { ");
	for(i=0;i<6;i++){
		//puts("");
		printf("%s  ",p[i]);
	}
	printf("\n");
	
}

int selectMax(int n,char s1[][128]){
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
	
