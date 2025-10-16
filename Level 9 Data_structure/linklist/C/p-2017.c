#include<stdio.h>
#include<stdlib.h>

//此程式-1 直接當機  資料數必須大於1 

 struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

int main(){
	node *head=NULL;
	node *ptr=NULL;
	
	int i,k=0;
	node *ptr2;
		head=(node*)malloc(sizeof(node));
		ptr=head;
		ptr->next=NULL;
		ptr2=head;
		
		
		while(1){
			scanf("%d",&k);
			if(k==-1){
				free(ptr2);
				if(head!=ptr2)ptr->next=NULL;
				break;
			}
			else{
				ptr2->data=k;
				ptr2->next=malloc(sizeof(node));
				ptr2=ptr2->next;
				ptr2->next=NULL;
				if(ptr->next!=ptr2&&ptr!=ptr2)ptr=ptr->next;  //ptr  晚ptr2 一步前進 
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
