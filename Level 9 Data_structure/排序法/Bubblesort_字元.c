#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6

//�Ѥj�ƨ�p!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
void swap(char s1[][128],int q,int r); //�P�Ӱ}�Cq�����Pr�洫
void print(int n,char p[][128]);

int main(){
	
	
	int i,j;
	char a[N][128];
	int n;
	//char s1[][128]={("abc"),("cde"),("zom"),("ddg"),("sda"),("aaa")};
	
	//puts("�п�JData�`�� :");
	for(i=0;i<N;i++){
		scanf("%s",a[i]);
	}
	
	//print(N,a);
	
	for(i=N-1;i>=1;i=i-1){
	//printf("pass [%d] =>\n",(N-i));
	 for(j=0;j<i;j++){
		if(strcmp(a[j],a[j+1])<0){
				//puts("����o3");
				swap(a,j,j+1);
				//printf("run [%d] => ",(j));
				//print(N,s1);
			
		}
	}
	//puts("�X���o");
	print(N,a);
	}
	
	print(N,a);
	return 0;			

}

void swap(char s1[][128],int q,int r){ // ) �Y�}�C , ��q���P��r���洫 
	char temp[128];
	strcpy(temp,s1[q]);
	strcpy(s1[q],s1[r]);
	strcpy(s1[r],temp);
	
}

void print(int n,char p[][128]){  //�i��C�L 
	int i=0;
	//printf("a= { ");
	for(i=0;i<6;i++){
		//puts("");
		printf("%s  ",p[i]);
	}
	printf("\n");
	
}
