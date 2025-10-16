#include<stdio.h>
#include<string.h>
#define N 100

void print(char a[][128],int n);
void LinearSearch(char a[][128],char key[128],int n);
void BinSearch(char a[][128],char key[128],int n);

int main(){
	char a[N][128];
	char f[128];
	int i=0,j=0;
	int n=0;
	
	
while(1){//puts("1 �s�W 2�u�ʷj�M 3�G���j�M 4�C�L 5���}");
	scanf("%d",&i);
	switch(i){
		case 1:{
				scanf("%s",f);
			if(n==0){strcpy(a[j],f);n++;break;}
			else {
			for(j=n-1;(strcmp(f,a[j])<0)&&j>=0;j--){
				strcpy(a[j+1],a[j]);
			}
			n++;
			strcpy(a[j+1],f);
			break;
			}
		}
		case 2:{
			scanf("%s",f);
			LinearSearch(a,f,n);
			break;
		}
		
		case 3:{
			scanf("%s",f);
			BinSearch(a,f,n);
			break;
		}
		case 4:{
			print(a,n);
			break;
		}
		case 5:{
			
			return 0;
		}
	}
}
	
	
	return 0;
}

void LinearSearch(char a[][128],char key[128],int n){
	int i=0;
	while(strcmp(key,a[i])!=0){
	
		if(i>n-1){puts("not found");
		break;}	
		printf("%d: %s\n",i,a[i]);
		i++;
	}
	if(i<=n&&strcmp(key,a[i])==0){ //����o�N��j��̩��ݰ��� �A�׽T�{���ڻPkey�ȬO�_�۲� 
	printf("%d: %s\n",i,a[i]);
	printf("found: %s\n",a[i]);
	}
}

void BinSearch(char a[][128],char key[128],int n){
	int u,l,m;
	l=0; 
	u=n; //max �W����data�� �h1 
	while(l<=u){
		m=(u+l)/2;
		printf("%d: %s\n",m,a[m]);
		if(strcmp(a[m],key)==0){
			printf("found: %s\n",a[m]);
			break;
		}
		else if(strcmp(a[m],key)<0){
			l=m+1;
		}
		else if(strcmp(a[m],key)>0){
			u=m-1;
		}
	}
	if(l>u)printf("not found\n");
}

void print(char a[][128],int n){  //�i��C�L 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%s ",a[i]);
	}
	printf("\n");
	
}
