#include<stdio.h>
#include<stdlib.h>
#define N 6  
void Insert(int *p,int key,int i);
void Insort(int *a,int n);
void print(int n,int *p);
void callbyaddress_swap(int *a,int *b);
int *selectMin(int n,int*p);


int main(){
	int i,j,k=1;
	int *Min;
	int p[N]={0};
	
	for(i=0;i<N;i++){
		scanf("%d",&p[i]);
	}
	print(N,p);
	puts("�п�J\n(1) �w�j�ƧǪk\n(2) ��ܱƧǪk (��̤p������̫e)\n(3) ���J�ƧǪk (�q�}�C��[1]�}�l������y��key)");
	scanf("%d",&k);
	switch (k){
		case 1:{
			//puts("�i�h�w�j�Ƨ��o\n");
			for(i=N-1;i>=1;i--){
				//printf("pass [%d] =>\n",(N-i));
				 for(j=0;j<i;j++){
					if(p[j]>p[j+1]){
						//puts("����o3");
						callbyaddress_swap(&p[j],&p[j+1]);}
					//printf("run [%d] => ",(j));
					//print(N,p);
			
				}print(N,p);
			}
				//puts("�X���o");
				print(N,p);
			break;
		}
		
		case 2:{
			//puts("�i�h��ܱƧ��o\n");
				for(i=0;i<N-1;i++){
					//printf("pass [%d] =>\n",(i+1));
					Min=selectMin(N-1-i,p+i);
					callbyaddress_swap(&p[i],Min);
					print(N,p);
					}
				//puts("�X���o");
				print(N,p);
			break;
		}
		
		case 3:{
			puts("�i�h���J�Ƨ��o\n");
				Insort(p,N);
				print(N,p);
			break;
		}	
	}
}

void callbyaddress_swap(int *a,int *b){ //SelectionSort�BBubblesort�� 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Insert(int *p,int key,int i){  // �Ndata r ���J  �H�ƧǦn�}�Cp ����  n��p��data�`�� 
	
	int j=i;
	printf("�ڬOKey = %d\n",key);
	while(key<p[j]&&j>=0){
		printf("�ڬO P[%d] = %d\n",j,p[j]);
		p[j+1]=p[j];
		j=j-1;
	}
	p[j+1]=key;
}


void Insort(int *a,int n){  //�i�� n-1 ����Insort
	int i;
	for(i=1;i<n;i++){  
		//printf("Pass :%d ==>\n",i); 
		Insert(a,a[i],i-1);
		print(n,a);
	}	
}

void print(int n,int *p){  //�i��C�L 
	int i=0;
	//printf("a= { ");
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	
}

int *selectMin(int n,int*p){  // SelectionSort �� 
	int i=0;
	int *min=&p[0];
	//printf("Initial = %d\n",p[i]);
	for(i=0;i<n;i++){
		if(*min>p[i+1]){
			min=&p[i+1];
		}
	}//printf("Min= %d\n",*min);
	
	return min;
	}
	
