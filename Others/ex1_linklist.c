#include<stdio.h>
#include<stdlib.h>
//此完單一創造鏈結串列 

struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

int main(){
	
	node A; //靜態宣告節點 
	node *head;  //動態宣告節點  step1 
	head=(node*)malloc(sizeof(node)); //動態宣告節點  step2
	
	A.data=10;
	A.next=NULL;
	
	head->data=10;
	head->next=NULL;
	
	node *ptr;
	ptr=head;
	
	ptr->data=10;
	ptr->next=(node*)malloc(sizeof(node));
	ptr=ptr->next;
	
	ptr->data=20;
	ptr->next=(node*)malloc(sizeof(node));
	ptr=ptr->next;
	
	ptr->data=30;
	ptr->next=NULL;
	ptr=head;
	
	while(ptr!=NULL){
		printf("Data : %d\nMem: %d\n",ptr->data,ptr->next);
		ptr=ptr->next;
	}	
	
	
	head=NULL ; // 養成好習慣 沒用到的指標設定成NULL
	 
	free(head);
}
