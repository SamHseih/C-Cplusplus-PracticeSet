#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6

//由大排到小!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
void swap(char s1[][128],int q,int r); //同個陣列q元素與r交換
void print(int n,char p[][128]);

int main(){
	
	
	int i,j;
	char a[N][128];
	int n;
	//char s1[][128]={("abc"),("cde"),("zom"),("ddg"),("sda"),("aaa")};
	
	//puts("請輸入Data總數 :");
	for(i=0;i<N;i++){
		scanf("%s",a[i]);
	}
	
	//print(N,a);
	
	for(i=N-1;i>=1;i=i-1){
	//printf("pass [%d] =>\n",(N-i));
	 for(j=0;j<i;j++){
		if(strcmp(a[j],a[j+1])<0){
				//puts("近來囉3");
				swap(a,j,j+1);
				//printf("run [%d] => ",(j));
				//print(N,s1);
			
		}
	}
	//puts("出來囉");
	print(N,a);
	}
	
	print(N,a);
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
