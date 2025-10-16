#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct _node{
	char name[128];
	int number;
	char email[128];
	struct _node *next;
};	
typedef struct _node node;

node *getnode(){
	
	node *new_node;
	new_node=(node*)malloc(sizeof(node));
	return new_node;
}

node freenode(node *ptr){
	free(ptr);
}

//�H�U�ŧi�禡
node *insert_node(node *head,node *pte,node input);
void printlist(node *ptr);
int length(node *head);
node *search_node(node *head,char s1[]);
node *delete_node(node *head,node *ptr);

int main(){
	
	char a;
	char s2[128];
	node *head,*ptr;
	head= ptr = NULL;	
	node input;
	while(1){
	//printf("i �s�W\nl�C�L\nf�j�M\nd�R��\ng��Ƽ�\nq���}\n");
	scanf(" %c",&a);
	switch(a){
		case 'i':{

						if(head!=NULL){  
							ptr=head;
							while(ptr->next!=NULL){ptr=ptr->next;}
							}  //��ptr �û����̫�@����� 
						else if(head==NULL){ptr=head;};  //�p�G�R���̫�@��head�� NULL�� ��ptr�]����NULL 
						scanf("%s",&input.name);
						scanf("%s",&input.email);
						scanf("%d",&input.number);
						
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
			
			//printf("�ثe���׬� = %d",length(head));
			break;
					}
					
		case 'f':{
			
			ptr=head;
			//printf("�п�J�n�j�M���W�r...\n");
			scanf("%s",s2);
			ptr=search_node(head,s2);
			
			//printf("�^��D�{��..\n");
			if(ptr!=NULL){
			printf("found\n");	
			printf("%s\n",ptr->name);
			printf("%s\n",ptr->email);
			printf("%010d\n\n",ptr->number);
			
			}
			else if(ptr==NULL){printf("Not found\n");}
			ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			break;
		}
		
		case 'd':{
			//printf("�п�J�n�R�����W�r...\n");
			scanf("%s",&s2);
			ptr=search_node(head,s2);
			
			//printf("�^��D�{��..\n");
			if(ptr!=NULL){
			
				head=delete_node(head,ptr);
				printf("Delete ok\n");}
			else if(ptr==NULL){printf("Can not delete\n");}
			
	
			//printf("�R������..�аO�o�˹�..");
			break;
		}
		/*case 'g':{
				printf("%d\n",length(head));
			break;
		}*/
		case 'q':{
			exit(0);
					}

		}

	system("pause");
	system("cls");	
	
	}

}



//�H�U�C�Llist
void printlist(node *ptr){
		
		//ptr=head;
		if(ptr==NULL){
			printf("�зs�W���...");
		}
		else{
		
			while(ptr!=NULL){
			printf("%s\n",ptr->name);
			printf("%s\n",ptr->email);
			printf("%010d\n\n",ptr->number);
			
			 //�C�L10�ӼƦr ��J����10��۰ʸ�0 
			
			ptr=ptr->next;		
			}
		}
	//puts("");
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
node *search_node(node *head,char s1[]){
	node *ptr;
	ptr=head;
	//printf("�M��Ȭ� -> %s\n",s1);
	//printf("�ثe�Ȭ� -> %s\n",ptr->name);
	while(strcmp(ptr->name,s1)!=0){
		//printf("�ثe�Ȭ� -> %s\n",ptr->name);
		ptr=ptr->next;
		if(ptr==NULL)break;
		
	}
	//printf("�j�M����...���Xsearch�j�� \n");
    return ptr;
}
 
//�H�U�R���`�I
 node *delete_node(node *head,node *ptr){   //�^�ǭ�=head !!�]�����i��|��s��head�I�I 
	node *previous;
	if(ptr==head){
		//puts("�Ĥ@��..");
		head=head->next;

		}
	else {
		previous=head;
		while(previous->next!=ptr){
			previous=previous->next;
			}
		
		if(ptr->next==NULL){
				//puts("�ĤG��..");
				previous->next=NULL;
		}
		
		else{
			//puts("�ĤT��..");
				previous->next=ptr->next;
		}
	
	}
	//puts("�R����...");
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
