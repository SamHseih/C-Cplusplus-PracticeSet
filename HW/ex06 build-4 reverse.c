#include<stdio.h>
#include<stdlib.h>


 struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

int main(){
//以下為新增節點 輸入非-1新增節點 輸入-1結束 
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
				if(ptr->next!=ptr2&&ptr!=ptr2)ptr=ptr->next;  //ptr  晚ptr2 一步前進 
			}
			}
	ptr=head;

// 以下為反轉linklist 
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
