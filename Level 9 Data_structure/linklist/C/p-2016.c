#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#define N 5 

// ��������Link list����

 
struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;


int main(){
	
	node *head=NULL;
	node *ptr=NULL;
	node *end=NULL;
	int i,k=0;
		head=(node*)malloc(sizeof(node));
		ptr=head;
	for(i=0;i<N;i++){
		scanf("%d",&k);
		ptr->data=k;
		if(i!=(N-1)){
			ptr->next=(node*)malloc(sizeof(node));	
			ptr=ptr->next;}
		else {
			ptr->next=NULL;}
		}
	ptr=head;
	
	
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
