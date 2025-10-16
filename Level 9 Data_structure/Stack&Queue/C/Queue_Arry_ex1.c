#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

struct _node{
	int data;
	struct _node *next;
}; 
typedef struct _node node;


int front=-1;
int rear=-1;
int size=0;

int queue[MAX_SIZE];


int Enqueue(int value){
	if(size==MAX_SIZE){
		return -1;
	}
	rear++; size++;
	if(rear==MAX_SIZE){
		rear=0;
	}
	queue[rear]=value;
	return 1;
}

int Dequeue(){
	
	if(size==0){
		return -1;
	}
	front++; size--;
	
	if(front==MAX_SIZE){
		front=0;
	}
	
	int temp;
	temp=queue[front];
	queue[front]=0;
	return temp; 
}

int main(){
	
	int data_in=0,data_out=0;

	while(data_in!=-1){
		scanf("%d", &data_in);	
		if(Enqueue(data_in)==-1)
		printf ("佇列已滿\n");
		else
		printf("已存入資料: %d\n", data_in);
	}
	while(data_out!=-1){
		if( (data_out = Dequeue()) == -1 )
		printf("佇列是空的\n");
		else
		printf("取出佇列內容: %d\n", data_out);
	}
}
