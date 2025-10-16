#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#define N 5 

// 此為反轉Link list版本

 
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
	f=ptr->next; //f前進 
	//printf("f= %d r= %d\n",r->data,f->data);
	
	do{
	ptr->next=r; //轉向 
	r=ptr; //r 前進 
	ptr=f; //ptr前進 
	if(f!=NULL)f=f->next;  //f前進  讓f 定住不再亂跑 
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
