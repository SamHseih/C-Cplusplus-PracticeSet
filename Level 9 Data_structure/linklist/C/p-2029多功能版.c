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

node *insert_node(node *head,node *pte,node input);
void printlist(node *ptr);
int length(node *head);
node *search_node(node *head,int num);
node *delete_node(node *head,node *ptr);

int main(){
	
	char a;
	node *head,*ptr;
	head= ptr = NULL;	
	node input;
	while(1){
	printf("i �s�W\nl�C�L\nf�j�M\nd�R��\nq���}\n");
	scanf(" %c",&a);
	switch(a){
		case 'i':{
			printf("��J�n���J����m �̫e->f �̲�->m �̫�->r\n");
			scanf(" %c",&a);
				switch(a){
					case 'f':{
						ptr=head;
						printf("�п�JData��: ");
						scanf("%d",&input.data);
						head=insert_node(head,NULL,input);
						if(head->next==NULL){
							ptr=head;
						}
						else{
							ptr=ptr->next;
						}
						break;
					}
					case 'm':{
						if(length(head)<=1){printf("�L����Data�i���J,�п�ܴ��J�̫e��");break;}
						else {
							ptr=head;
							int i;
							float n=(float)length(head);
							n=round(n/2);
							for(i=1;i<(int)n;i++){
								ptr=ptr->next;
							}
							printf("�п�JData��: ");
							scanf("%d",&input.data);
							head=insert_node(head,ptr,input);
							if(head->next==NULL){
								ptr=head;
								}
							else{
								ptr=ptr->next;
								}
						}
						
						break;
					}
					case 'r':{
							if(head!=NULL){
							ptr=head;
							while(ptr->next!=NULL){ptr=ptr->next;}
							}
						printf("�п�JData��: ");
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
				}
				
			break;
		}
		
		case 'l':{
			ptr=head;
			printlist(ptr);
			
			printf("�ثe���׬� = %d",length(head));
			break;
					}
					
		case 'f':{
			
			ptr=head;
			printf("�п�J�n�j�M���Ʀr...\n");
			scanf("%d",&a);
			ptr=search_node(head,a);
			
			printf("�^��D�{��..");
			if(ptr!=NULL)printf("�j�M����Ʀr��==>%d   \n",ptr->data);
			else if(ptr==NULL){printf("�S���M��\n");}
			ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			break;
		}
		
		case 'd':{
			printf("�п�J�n�R�����Ʀr...\n");
			scanf("%d",&a);
			ptr=search_node(head,a);
			
			printf("�^��D�{��..\n");
			if(ptr!=NULL){
				printf("�Y�N���R���Ʀr��==>%d   \n",ptr->data);
				head=delete_node(head,ptr);}
			else if(ptr==NULL){printf("�L���Ʀr�i�R\n");}
			
	
			printf("�R������..�аO�o�˹�..");
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
	printf("�M��Ȭ� -> %d\n",num);
	printf("�ثe�Ȭ� -> %d\n",ptr->data);
	while(ptr->data!=num){
		printf("ptr data -> %d \ninput data ->%d\n",ptr->data,num);
		ptr=ptr->next;
		if(ptr==NULL)break;
		
	}
	printf("�j�M����...���Xsearch�j�� \n");
    return ptr;
}
 
//�H�U�R���`�I
 node *delete_node(node *head,node *ptr){   //�^�ǭ�=head !!�]�����i��|��s��head�I�I 
	node *previous;
	if(ptr==head){
		puts("�Ĥ@��..");
		head=head->next;

		}
	else {
		previous=head;
		while(previous->next!=ptr){
			previous=previous->next;
			}
		
		if(ptr->next==NULL){
				puts("�ĤG��..");
				previous->next=NULL;
		}
		
		else{
			puts("�ĤT��..");
				previous->next=ptr->next;
		}
	
	}
	puts("�R����...");
	freenode(ptr);
	return(head);

} 

//�H�U�p���쵲���� 
int length(node *head){
 	int l=1;
 	if(head==NULL)return 0;
 	while(head->next!=NULL){
 		l++;
 		head=head->next;
	}	
return l;
} 
