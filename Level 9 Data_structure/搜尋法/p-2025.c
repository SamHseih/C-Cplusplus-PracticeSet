#include<stdio.h>
#define N 1000
int BinSearch(int a[],int key,int n); // 此n為陣列的末端位置, 總共n+1個data 
int linearSearch(int a[],int key,int n);  
void print(int n,int *p); //n筆Data 

int main(){
	int a[N]={0};
	int i=0,j=0,k=0,key; //i為目前data數目  

	while(1){
		//puts("1 新增 2線性搜尋 3二元搜尋 4列印 0離開");
		scanf("%d",&k);
	switch(k){
		case 1:{
			scanf("%d",&key);
			for(j=i-1;key<a[j]&&j>=0;j--){// 將data key 插入已排序好陣列a之中 i為a之data總數 若key小於目前值往前插，大於往後挪 
					a[j+1]=a[j];} //後移 
					i++; //i==0 無data 插入後i= data數 
					a[j+1]=key; //將key填入正確位置 
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
int linearSearch(int a[],int key,int n){ //線性搜尋 
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

int BinSearch(int a[],int key,int n){  //二元搜尋 
	int l,u,m;
	//print(n,a);
	l=0;
	u=n;
		while(l<=u){
			m=(l+u)/2;
			//printf("我是中心值 %d\n",a[m]);
			printf("%d: %d\n",m,a[m]);
			if(a[m]==key){
				
				return m;
			}
			else if(a[m]>key){
				u=m-1;
				
				//printf("我是上限 %d\n",a[u]);
			}
			else if(a[m]<key){
				l=m+1;
				//printf("我是下限 %d\n",a[l]);
			}	
		}
	return -1;
}

void print(int n,int *p){  //進行列印 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	
}
