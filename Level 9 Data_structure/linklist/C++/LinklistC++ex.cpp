#include<iostream>

using namespace std;

class node{
	friend class linklist;
	private:
			int data;
			node *next;
	
};

class linklist{
	public:
	linklist();
	void insertLast(int value);
	void printlist();

	
	
	private:
	node *head;
	node *tail;
	node *getnode();	
	void insert_node(node *ptr,node input);		
	node freenode (node *p);	
	
};

linklist::linklist(){
		head=NULL;
		tail=NULL; 
	}
	
void linklist::insertLast(int value){
		node input;
		input.data=value;
		insert_node(tail,input);
		if(tail==NULL){
			tail=head;
		}
		else{
			tail=tail->next;
		}
	}
		
	//�H�U�s�W�`�I 
node *linklist::getnode(){
	node *p;
	p=new node;
		if(p==NULL){
			exit(1);
		}
	return p;
}

//�H�U�C�Llist
void linklist::printlist(){
		
		node *ptr=head;
		if(ptr==NULL){
			printf("�зs�W���...");
		}
		else{
		
			while(ptr!=NULL){
			cout<<ptr->data<<"  ";
			ptr=ptr->next;		
			}
		cout<<endl;
		}
	puts("");
}

//�H�U���J�`�I 
void linklist::insert_node(node *ptr,node input){   //�bC++�� head�i�H������ܼƨϥ� �T�M���ݭn�A��head��@�Ѽ� 
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
}
//�H�U����`�I
node linklist::freenode (node *p){
	delete p;
} 





int main(){
	
	linklist st1,st2;
	
	st1.insertLast(11);
	st1.insertLast(22);
	st1.insertLast(33);
	st1.insertLast(44);
	st1.printlist();
	
	st2.insertLast(10);
	st2.insertLast(20);
	st2.insertLast(30);
	st2.insertLast(40);st2.insertLast(99);
	st2.printlist();
	
	return 0;
}


