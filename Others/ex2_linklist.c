#include<stdio.h>
#include<stdlib.h>
#define N 5 
struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

int main(){
	node *head=NULL;
	node *ptr=NULL;
	
	int i,k=0;
		head=(node*)malloc(sizeof(node));
		ptr=head;
	for(i=0;i<N;i++){
		scanf("%d",&k);
		ptr->data=k;
		if(i!=(N-1)){
			ptr->next=(node*)malloc(sizeof(node));}
		else {
			ptr->next=NULL;}
		ptr=ptr->next;
		}
	ptr=head;

	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;		
	}
	
	free(head);

}
