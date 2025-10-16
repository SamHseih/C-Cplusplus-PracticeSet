#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;
void printlist(node *ptr);
int push(int value);
int pop();

node *stack=NULL;
int top=-1;

int main(){
	int i=1;
	node *ptr;
	int number;
		scanf("%d",&number);
		do {
			push(number);
			scanf("%d",&number);	
		}while(number!=-1);
	
	number=0;	
	/*while(number!=-1){
		number=pop();
		if(number!=-1)printf("pop %d-> %d\n",i,number);
		i++;
	}*/
	ptr=stack; 
	printlist(ptr);
	return 0;
	
}
int push(int value){
	top++;
	if(top>MAX_SIZE-1){
		puts("滿的.");
		top--;
		return 0;
		
	}
	node *new_node;
	new_node=(node*)malloc(sizeof(node));
	new_node->data=value;
	new_node->next=stack;
	stack=new_node;
}

int pop(){
	if(top==-1){
		puts("空的.");
		return -1;
	} 	
	node *ptr;
	int temp;
	temp=stack->data;
	ptr=stack;
	stack=stack->next;
	free(ptr);
	top--;
	return temp;
	
}

void printlist(node *ptr){
	if(ptr->next!=NULL){
		printlist(ptr->next);
	}
	printf("%d",ptr->data);
}


