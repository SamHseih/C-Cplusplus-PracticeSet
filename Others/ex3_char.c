#include<stdio.h>
#include<string.h>
void print(int n,char p[][128]);
void callbyvalue_swap(char s1[][128],char s2[][128]); //兩個陣列交換 
void swap(char s1[][128],int q,int r); //同個陣列q元素與r交換 
int main(){
	
	int i=0;
	char s1[][128]={("1aaaaa"),("a1aaaa"),("aa1aaa"),("aaa1aa"),("aaaa1a"),("aaaaa1")};
	//char s2[][128]={("asdasd"),("cvgnhd"),("qwefdgd"),("assdfgsdfdasd"),("asddfgvasd"),("asbgbfgndasd")};
	
	
	print(6,s1);
	//print(6,s2);
	
	//callbyvalue_swap(s1,s2);
	
	swap(s1,0,4);
	
	print(6,s1);
	//print(6,s2);
	
}



void print(int n,char p[][128]){  //進行列印 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		puts("");
		printf("%s",p[i]);
	}
	printf("\n");
	
}

void swap(char s1[][128],int q,int r){
	char temp[128];
	strcpy(temp,s1[q]);
	strcpy(s1[q],s1[r]);
	strcpy(s1[r],temp);
	
}

void callbyvalue_swap(char s1[][128],char s2[][128]){
	int i=0;
	char temp[128];
	for(i=0;i<6;i++){
	strcpy(temp,s1[i]);
	printf("temp => %s\n",temp);
	strcpy(s1[i],s2[i]);
	printf("s1 => %s\n",s1[i]);
	strcpy(s2[i],temp);
	printf("s2 => %s\n",s2[i]);	
	}
	
}
