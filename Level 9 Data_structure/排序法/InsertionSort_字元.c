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

void Insert(char s1[][128],char r[128],int i){  // �Ndata key ���J  �H�ƧǦn�}�Cs1[0]~s1[i]  
	char key[128]; //�ŧi�n�O��key���� 
	strcpy(key,r);  //�P�W 
	int j;
	j=i;  //key�ȫe�@��@�}�l�n�񪺹�H  ����j -- ����0 
	
	//printf("key = %s\n",key);
	while(strcmp(s1[j],key)<0&&j>=0){  //��� �Ykey�ȸ��j�A��}�C����h �ӥB���F����L�����j ��j<0���ɭ԰��� 
		//printf("In while j= %d\n",j);  
		//printf("In while s1[%d]= %s\n",j,s1[j]);
		//printf("In while %c\n",s1[i]);
		strcpy(s1[j+1],s1[j]);   
		//printf("key = %s\n",key);
		//print(7,s1);
		j=j-1;
		//printf("In while j= %d\n",j);
	}
	//printf("�X��while  key = %s\n",key);
	strcpy(s1[j+1],key);
	//printf("s1[j+1]= %s\n",s1[j+1]);
}

void Insort(char s1[][128],int n){
	int i;
		for(i=1;i<n;i++){   //key�� �ѯx�}�ĤG��}�l����]  j�bkey�ȫe 
			Insert(s1,s1[i],i-1);    
			print(6,s1); 
		}
	}	

void print(int n,char p[][128]){  //�i��C�L 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		//puts("");
		printf("%s  ",p[i]);
	}
	printf("\n");
}

