#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6
void Insert(char [][128],char r[128],int i);
void Insort(char s1[][128],int n);
void print(int n,char p[][128]);
void swap(char s1[][128],int q,int r); //�P�Ӱ}�Cq�����Pr�洫
int *selectMin(int n,int*p);


int main(){
	
	int i,j,k;
	char s1[N][128];
	for(i=0;i<N;i++)
	scanf("%s",s1[i]);
	//print(N,s1);
	
	
	//puts("�п�J\n(1) �w�j�ƧǪk\n(2) ��ܱƧǪk (��̤j������̫e)\n(3) ���J�ƧǪk (�q�}�C��[1]�}�l������y��key)");
	scanf("%d",&k);
	switch (k){
		case 1:{
			//puts("�i�h�w�j�Ƨ��o\n");
			
				for(i=N-1;i>=1;i=i-1){
						//printf("pass [%d] =>\n",(N-i));
	 				for(j=0;j<i;j++){
						if(strcmp(s1[j],s1[j+1])<0){
							//puts("����o3");
							swap(s1,j,j+1);
							//printf("run [%d] => ",(j));
							//print(N,s1);
						}
					}
				//puts("�X���o");
				print(N,s1);
				}
			print(N,s1);	
			break;
		}
		
		case 2:{
			int Max;
			//puts("�i�h�o");
				for(i=0;i<5;i++){
					//printf("pass [%d] =>\n",(i+1));
					Max=selectMax(6-i,&s1[i]);
					swap(s1,Max+i,i);
					print(6,s1);
					}
					//puts("�X���o");
					print(6,s1);
			break;
		}
		
		case 3:{
			//puts("�i�h���J�Ƨ��o\n");
				Insort(s1,6);	
				print(6,s1);
			break;
		}
	}
	return 0;
}

void swap(char s1[][128],int q,int r){ // ) �Y�}�C , ��q���P��r���洫 
	
	char temp[128];
	strcpy(temp,s1[q]);
	strcpy(s1[q],s1[r]);
	strcpy(s1[r],temp);
	
}


void Insort(char s1[][128],int n){
	int i;
		for(i=1;i<n;i++){   //key�� �ѯx�}�ĤG��}�l����]  j�bkey�ȫe 
			Insert(s1,s1[i],i-1);    
			print(6,s1); 
		}
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


void print(int n,char p[][128]){  //�i��C�L 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		//puts("");
		printf("%s ",p[i]);
	}
	printf("\n");
	
}

int selectMax(int n,char s1[][128]){ //selection �� 
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
	
