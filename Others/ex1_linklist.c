#include<stdio.h>
#include<stdlib.h>
//������@�гy�쵲��C 

struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

int main(){
	
	node A; //�R�A�ŧi�`�I 
	node *head;  //�ʺA�ŧi�`�I  step1 
	head=(node*)malloc(sizeof(node)); //�ʺA�ŧi�`�I  step2
	
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
	
	
	head=NULL ; // �i���n�ߺD �S�Ψ쪺���г]�w��NULL
	 
	free(head);
}
