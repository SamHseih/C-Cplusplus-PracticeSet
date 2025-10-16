#include<stdio.h>
#include<stdlib.h>


struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

node *getnode();

//�H�U�R���`�I
node freenode (node *p){
	free(p);
} 

node *insert_node(node *head,node *pte,node input);
void printlist(node *ptr);

int main(){
	
	int a;
	node *head,*ptr;
	head= ptr = NULL;	
	node input;
	while(1){
	//printf("i �s�W\nl�C�L\nq���}\n");
	scanf(" %c",&a);
	switch(a){
		case 'i':{
				scanf("%d",&input.data);
				head=insert_node(head,ptr,input);
					if(head->next==NULL){
						ptr=head;
					}
					else{
						ptr=ptr->next;
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
					}

		}
	system("pause");
	system("cls");	
	
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

