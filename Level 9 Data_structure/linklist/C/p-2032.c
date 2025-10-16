#include<stdio.h>
#include<stdlib.h>

#include<math.h>

struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

node *getnode();

//�H�U����`�I
node freenode (node *p){
	free(p);
} 
//�H�U�ŧi�禡 
node *insert_node(node *head,node *pte,node input);
void printlist(node *ptr);
node *search_node(node *head,int num);

int main(){
	char a;
	node *head,*ptr;
	head= ptr = NULL;	
	node input;
	while(1){
	//printf("s �s�W��ƧY�Ƨ� (�Ѥp��j) q ���} l �C�L\n");
	scanf(" %c",&a);
	
	switch(a){
		case 's':{
				ptr=head;
				scanf("%d",&input.data);
				
				if(head==NULL){ 
					head=insert_node(head,ptr,input);
					//printf("�Ĥ@�ش��J����\n");
					}
				else{
				
					if(input.data==ptr->data){ 
						head=insert_node(head,ptr,input);
						//printf("�ĤG�ش��J����\n");
						}
					else if(input.data<ptr->data){
						head=head=insert_node(head,NULL,input);
						//printf("�ĤT�ش��J����\n");
					}
					
					
					else {
						
						while(ptr->next!=NULL){
							//printf("�ڥd�b�o...\n");
							//printf("%d",ptr->data);
							if(input.data>ptr->next->data){
							ptr=ptr->next;
							}
							else if(input.data<=ptr->next->data){break;}
							else if(input.data==ptr->data){break;}
						}	
						head=insert_node(head,ptr,input);
						//printf("�ĥ|�ش��J����\n");
					}		
				}
			
			break;
		}
		case 'l':{
			ptr=head;
			printlist(ptr);
			break;
		}
		
		case 'q':{
			exit(0);
			break;
		}
	}
	
	
	
	
	}
}
//�H�U�s�W�`�I 
node *getnode(){
	node *p;
	p=(node*)malloc(sizeof(node));
		if(p==NULL){
			printf("�O����Ŷ�����..\n");
			exit(1);
		}
	return p;
}

//�H�U�C�Llist
void printlist(node *ptr){
		
		//ptr=head;
		if(ptr==NULL){
			printf("�зs�W���...");
		}
		else{
		
			while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->next;		
			}
		}
	puts("");
}

//�H�U���J�`�I 
node *insert_node(node *head,node *ptr,node input){
		node *new_node; /* �s�`�I�����ܼ�*/
		new_node = getnode(); /* �إ߷s�`�I,���o�@�ӥi�θ`�I*/
		*new_node = input; /* �إ߸`�I���e*/   //�e��  �P��+�����ܼ�  = ���Ц�m��������  �tData�P����   ((�B�Φb�h��data�ɡA�i�ϥΦ��g�k �Ҧp�� data1 �y�� data2 �a�} dat3 ������ ���g�k�]�F���� 
		new_node->next = NULL; /* �]�w���Ъ��*/ 
	
	if(ptr==NULL){/* ����ptr�O�_�ONULL */
		
		/* �Ĥ@�ر��p: ���J�Ĥ@�Ӹ`�I*/
		new_node->next = head; /* �s�`�I������C�}�l*/
		head = new_node;
	}
	else {
		if(ptr->next==NULL)/* �O�_�O��C����*/
		/* �ĤG�ر��p: ���J�̫�@�Ӹ`�I*/
			ptr->next=new_node; /* �̫���V�s�`�I*/
			
		else {
			
		/* �ĤT�ر��p: ���J���������`�I*/
			new_node->next=ptr->next;/* (3) �s�`�I���V�U�@�`�I(3)*/		
			ptr->next=new_node;/* �`�Iptr���V�s�`�I(4)*/
			}
	
	} 
	return head;
}


//�H�U�M��`�I
node *search_node(node *head,int num){
	node *ptr;
	ptr=head;
	//printf("�M��Ȭ� -> %d\n",num);
	//printf("�ثe�Ȭ� -> %d\n",ptr->data);
	while(ptr->data!=num){
	//	printf("ptr data -> %d \ninput data ->%d\n",ptr->data,num);
		ptr=ptr->next;
		if(ptr==NULL)break;
		
	}
	//printf("�j�M����...���Xsearch�j�� \n");
    return ptr;
}



 
