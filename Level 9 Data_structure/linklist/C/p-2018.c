#include<stdio.h>
#include<stdlib.h>


 struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

int main(){
//�H�U���s�W�`�I ��J�D-1�s�W�`�I ��J-1���� 
	node *head=NULL;
	node *ptr=NULL;
	
	int i,k=0;
	node *ptr2;
		head=(node*)malloc(sizeof(node));
		ptr=head;
		ptr->next=NULL;
		ptr2=head;
		
		
		while(k!=-1){
			
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
				if(ptr->next!=ptr2&&ptr!=ptr2)ptr=ptr->next;  //ptr  ��ptr2 �@�B�e�i 
			}
			}
	ptr=head;

// �H�U������linklist 
	node *f,*r;
	r=NULL; 
	f=ptr->next; //f�e�i 
	//printf("f= %d r= %d\n",r->data,f->data);
	
	do{
	ptr->next=r; //��V 
	r=ptr; //r �e�i 
	ptr=f; //ptr�e�i 
	if(f!=NULL)f=f->next;  //f�e�i  ��f �w���A�ö] 
	}while(ptr!=NULL);
	
	head=r;
	ptr=head;

		while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;		
	}
	
	free(head);
return 0;
}
