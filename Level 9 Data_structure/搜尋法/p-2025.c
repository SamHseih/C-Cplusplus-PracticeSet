#include<stdio.h>
#define N 1000
int BinSearch(int a[],int key,int n); // ��n���}�C�����ݦ�m, �`�@n+1��data 
int linearSearch(int a[],int key,int n);  
void print(int n,int *p); //n��Data 

int main(){
	int a[N]={0};
	int i=0,j=0,k=0,key; //i���ثedata�ƥ�  

	while(1){
		//puts("1 �s�W 2�u�ʷj�M 3�G���j�M 4�C�L 0���}");
		scanf("%d",&k);
	switch(k){
		case 1:{
			scanf("%d",&key);
			for(j=i-1;key<a[j]&&j>=0;j--){// �Ndata key ���J�w�ƧǦn�}�Ca���� i��a��data�`�� �Ykey�p��ثe�ȩ��e���A�j�󩹫ᮿ 
					a[j+1]=a[j];} //�Ჾ 
					i++; //i==0 �Ldata ���J��i= data�� 
					a[j+1]=key; //�Nkey��J���T��m 
				//print(i,a);
			break;
		}
		case 2:{
			scanf("%d",&k);
			k=linearSearch(a,k,i);
			if( k==-1)puts("not found\n");
			else printf("found %d\n",a[k]);
			break;
		}
		
		case 3:{
			scanf("%d",&k);
			k=BinSearch(a,k,i);
			if( k==-1)puts("not found\n");
			else printf("found %d\n",a[k]);
			break;
		}
		case 4:{
			print(i,a);
			break;
		}
		case 5:{
			return 0;
		}
	}
  }
}
int linearSearch(int a[],int key,int n){ //�u�ʷj�M 
	int i=0;
	while(key!=a[i]){
		printf("%d: %d\n",i,a[i]);
		i++;
		if(key==a[i]){printf("%d: %d\n",i,a[i]);
		return i;
		}
		else if(i>=n-1){printf("%d: %d\n",i,a[i]);
		break;
		}
	}
	return -1;
}

int BinSearch(int a[],int key,int n){  //�G���j�M 
	int l,u,m;
	//print(n,a);
	l=0;
	u=n;
		while(l<=u){
			m=(l+u)/2;
			//printf("�ڬO���߭� %d\n",a[m]);
			printf("%d: %d\n",m,a[m]);
			if(a[m]==key){
				
				return m;
			}
			else if(a[m]>key){
				u=m-1;
				
				//printf("�ڬO�W�� %d\n",a[u]);
			}
			else if(a[m]<key){
				l=m+1;
				//printf("�ڬO�U�� %d\n",a[l]);
			}	
		}
	return -1;
}

void print(int n,int *p){  //�i��C�L 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	
}
