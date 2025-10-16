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
	
	
while(1){//puts("1 新增 2線性搜尋 3二元搜尋 4列印 5離開");
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
	if(i<=n&&strcmp(key,a[i])==0){ //走到這代表搜到最底端停止 再度確認尾巴與key值是否相符 
	printf("%d: %s\n",i,a[i]);
	printf("found: %s\n",a[i]);
	}
}

void BinSearch(char a[][128],char key[128],int n){
	int u,l,m;
	l=0; 
	u=n; //max 上限比data值 多1 
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

void print(char a[][128],int n){  //進行列印 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%s ",a[i]);
	}
	printf("\n");
	
}
