#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 52
#define PEOPLE 4
#define HAND 13
#define SUIT 4

// // 3�R�� 4�٧� 5���� 6�®� 
int stack[MAX_SIZE];
int top=-1;
int push(int value);
int pop();
void reshuffle(int *p);
void Insert(int *p,int key,int i);
void Insort(int *a,int n);
int style[4]={5,4,3,6};

int main(){
	
	int i,j,k=0;
	int player[SUIT][HAND];
	for(i=0;i<MAX_SIZE;i++){stack[i]=i;}//��l�ƵP�� 
	
	//�~�P�é�J�P��
	reshuffle(stack);  
	//�o�P
	for(i=0;i<HAND;i++){          
		for(j=0;j<PEOPLE;j++){
			player[j][i]=pop();    
		}
	}
	for(i=0;i<PEOPLE;i++){
		printf("Player%d:\n",i+1); 
		for(j=0;j<HAND;j++){
		printf("[%c%2d] ",style[(player[i][j]/HAND)],player[i][j]%HAND+1);
		k++;
		}puts("\n");
	}  
	//�Ʀr�Ƨ�
	for(i=0;i<PEOPLE;i++)Insort(player[i],HAND);   
	puts("");
	//�C�L
	for(i=0;i<PEOPLE;i++){
		printf("Player%d:\n",i+1); 
		for(j=0;j<HAND;j++){
		printf("[%c%2d] ",style[(player[i][j]/HAND)],player[i][j]%HAND+1);
		k++;
		}puts("\n");
	}  
	return 0;
}

int push(int value){
	if(top==MAX_SIZE-1){
		return -1;
	}	
		top++;
		stack[top]=value;
	
	return 1;
}

int pop(){
	int temp;
	if(top==-1){
		return -1;
	}
	temp=stack[top];
	stack[top]=0; //�ݸ�ƬO�_�ӷP�A���B�J�i�M�i���M
	top--;
	return temp; 
}	

void reshuffle(int *p){
	
	srand(time(NULL));
	int i,r;
	int dim=MAX_SIZE;
	int a[MAX_SIZE];
	for(i=0;i<MAX_SIZE;i++){
		a[i]=p[i];
	}
	
	for(i=0;i<MAX_SIZE;i++){
		r=rand()%dim;
		push(a[r]);
		a[r]=a[dim-1];		
		
		dim--;
	}
	
}

void Insert(int *p,int key,int i){  // �Ndata key���J�H�ƧǦn�}�Cp���� �q��i�}�l�P�_ 
	
	int j=i;  
	//printf("�ڬOKey = %d\n",key);
	while(key<p[j]&&j>=0){    // true 2���n����  1. �Y�N���J����m��key�j  2. j���O-1  
		//printf("�ڬO P[%d] = %d\n",j,p[j]);  
		p[j+1]=p[j];  // ����key���e���Ƚƻs�A�ëᲾ��A�л\key�� 
		j=j-1;
	}
	p[j+1]=key; //�Nkey��J���T��m 
}

void Insort(int *a,int n){  
	int i;
	for(i=1;i<n;i++){  //�i�� n-1 ����Insort
		//printf("Pass :%d ==>\n",i); 
		Insert(a,a[i],i-1); //�q�ĤG��data�}�l��key ,��i-1=0 �}�l�P�_ 
		//print(n,a);
	}	
}
