#include<iostream>

using namespace std;

class node {
		friend class linklist;
	private:
		int data;
		node *next;

}
class linklist {
	public:
		linklist();
		void insertLast(int value);
		void printlist();
		void search_node(int num);
		int delete_node(int value);

	private:
		node *head;
		node *tail;
		node *getnode();
		void insert_node(node *ptr,node input);
		node freenode (node *p);

};

linklist::linklist() {
	head=NULL;
	tail=NULL;
}

void linklist::insertLast(int value) {
	node input;
	input.data=value;
	insert_node(tail,input);
	if(tail==NULL) {
		tail=head;
	} else {
		tail=tail->next;
	}
}

//�H�U�s�W�`�I
node *linklist::getnode() {
	node *p;
	p=new node;
	/*if(p==NULL){
		exit(1);
	}*/
	return p;
}

//�H�U�C�Llist
void linklist::printlist() {

	node *ptr=head;
	if(ptr==NULL) {
		//printf("�зs�W���...");
	} else {

		while(ptr!=NULL) {
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
}

//�H�U���J�`�I
void linklist::insert_node(node *ptr,node input) {  //�bC++�� head�i�H������ܼƨϥ� �T�M���ݭn�A��head��@�Ѽ�
	node *new_node; /* �s�`�I�����ܼ�*/
	new_node = getnode(); /* �إ߷s�`�I,���o�@�ӥi�θ`�I*/
	*new_node = input; /* �إ߸`�I���e*/   //�e��  �P��+�����ܼ�  = ���Ц�m��������  �tData�P����   ((�B�Φb�h��data�ɡA�i�ϥΦ��g�k �Ҧp�� data1 �y�� data2 �a�} dat3 ������ ���g�k�]�F����
	new_node->next = NULL; /* �]�w���Ъ��*/

	if(ptr==NULL) { /* ����ptr�O�_�ONULL */

		/* �Ĥ@�ر��p: ���J�Ĥ@�Ӹ`�I*/
		new_node->next = head; /* �s�`�I������C�}�l*/
		head = new_node;
	} else {
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
node linklist::freenode (node *p) {
	delete p;
}

//�H�U�M��`�I
void linklist::search_node(int num) {
	node *ptr;
	ptr=head;
	//printf("�M��Ȭ� -> %d\n",num);
	//printf("�ثe�Ȭ� -> %d\n",ptr->data);
	while(ptr->data!=num) {
		//printf("ptr data -> %d \ninput data ->%d\n",ptr->data,num);
		ptr=ptr->next;
		if(ptr==NULL)break;

	}
	//printf("�j�M����...���Xsearch�j�� \n");
	if(ptr==NULL)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;

}

//�H�U�R���`�I
int linklist::delete_node(int value) {
	node *previous;
	node *ptr;
	ptr=head;
	if(ptr==NULL) {
		cout<<"�зs�W���..from�R���禡"<<endl;
	} else {

		while(ptr->data!=value) {
			ptr=ptr->next;
			if(ptr==NULL)break;
		}

		if(ptr==NULL) {
			//cout<<"�L��data:"<<value<<endl;
			return 0;
		}

		if(ptr==head) {
			//puts("�Ĥ@��..");
			head=head->next;
			tail=head;

		} else {
			previous=head;
			while(previous->next!=ptr) {
				previous=previous->next;
			}

			if(ptr==tail) {
				//puts("�ĤG��..");
				previous->next=NULL;
				tail=previous;
			}

			else {
				//puts("�ĤT��..");
				previous->next=ptr->next;
			}

		}
		//puts("�R����...");
		delete ptr;
	}
}



int main() {

	int i,N,value;

	//new�B��l�|�t�m�@��int�һݭn���Ŷ��A�öǦ^�ӪŶ�����}�A�ҥH�z�ϥΫ���p���x�s�o�Ӧ�}

	cin>>N;
	//cout<<"N ="<<N<<endl;;
	linklist *p=new linklist[N];


	for(i=0; i<N; i++) {
		do {
			cin>>value;
			if(value!=-1)p[i].insertLast(value);
		} while(value!=-1);
		//cout<<"���}��"<<i<<"���J"<<endl;
	}
	for(i=0; i<N; i++) {
		p[i].printlist();
	}

	cin>>value;
	cout<<"Delete "<<value<<endl;
	for(i=0; i<N; i++) {
		p[i].delete_node(value);
	}

	for(i=0; i<N; i++) {
		p[i].printlist();
	}

	cin>>value;
	cout<<"Find "<<value<<endl;

	for(i=0; i<N; i++) {
		p[i].search_node(value);
	}


	delete p;


	return 0;
}


