#include<stdio.h>
#include<stdlib.h>
//�ϧǦC�L  II ���e�[��ƪ��� 

struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;


int main(){
	
	int n;
	node *head,*ptr;
	head=NULL;
	ptr=head;
	
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
			head=(node*)malloc(sizeof(node));
			head->data=n;
			head->next=ptr;
			ptr=head;
		}
	}
	
	//��²�u�g�k	
	/*while(1){
		scanf("%d",&n);
		if(n==-1)break;
			head=(node*)malloc(sizeof(node));
			head->data=n;
			if(head==NULL)head->next=NULL;
			if(head!=NULL)head->next=ptr;
			ptr=head;
	} */
	
		while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;		
	}
	//�H�U�^���O���� 
	
	ptr=head;
	node *p4d;

	while(ptr!=NULL){
		p4d=ptr->next;
		free(ptr);
		ptr=p4d;
	} 
	
	return 0;
}
	
	
