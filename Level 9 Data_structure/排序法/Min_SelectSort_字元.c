#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char s1[][128],int q,int r); //�P�Ӱ}�Cq�����Pr�洫
void print(int n,char p[][128]);
int selectMin(int n,char s1[][128]);


int main(){
	

	int i,j;
	int Min;
	int n;
	char s1[6][128];
	
	for(i=0;i<6;i++)
	scanf("%s",s1[i]);
	
	
	//Min=selectMin(6,s1);
	
	
	//puts("�i�h�o");
	for(i=0;i<5;i++){
	//printf("pass [%d] =>\n",(i+1));
		Min=selectMin(6-i,&s1[i]);
		//printf("In main Min= %d\n",Min);  
		swap(s1,Min+i,i);
		print(6,s1);
	}
	//puts("�X���o");
	print(6,s1);
	
	
	
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

int selectMin(int n,char s1[][128]){ // n �r��ƥ� �}�C�r�� 
	int i=0,k=0;
	char *min;
	min=s1[0];
	//printf("Initial = %s\n",min);
	for(i=0;i<n;i++){   //��X�̤p�� 
		if(strcmp(min,s1[i])>0){
			min=s1[i];
			k=i;    //�����b���@�ӯx�} 
			//printf("Min= %s\n",min);
		}
	}
	//printf("Min= %s\n",min);  
	//printf("k=> %d\n",k);
	return k;
	}
	


