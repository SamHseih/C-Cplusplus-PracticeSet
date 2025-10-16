#include<stdio.h>
#include<stdlib.h>


 struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

int main(){
	
	node *head,*ptr;
	head=NULL;
	int n;

	while(1){
		scanf("%d",&n); 
	if(n==-1)break;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->data=n;
		head->next=NULL;
		ptr=head;
	}
	else{
		ptr->next=(node*)malloc(sizeof(node));
		ptr=ptr->next;
		ptr->data=n;
		ptr->next=NULL;
		}
	}

	ptr=head;

	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;		
	}
	
	free(head);
return 0;
	
}
