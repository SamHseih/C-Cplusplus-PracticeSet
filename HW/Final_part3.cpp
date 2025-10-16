#include<iostream>
#include <stdio.h>
#include <string.h>
#include<string>
using namespace std;
class node {
		friend class linklist;
		friend class stack;
	private:
		int data;
		node *next;

};
class linklist {
	public:
		linklist();



	protected:
		node *tail;
		void printlist();
		node *getnode();
		void insert_node(node *ptr,node input);
		node freenode (node *p);
		node *head;
		int delete_node(int value);
		void search_node(int num);
};
class stack:public linklist {
	public:
		void push(int value);
		int pop();
		void reverse_print(int size);
	protected:
		int printstack(node *ptr);
};
linklist::linklist() {
	head=NULL;
	tail=NULL;
}
node *linklist::getnode() { //�H�U�s�W�`�I
	node *p;
	p=new node;
	/*if(p==NULL){
		exit(1);
	}*/
	return p;
}
void linklist::printlist() { //�H�U�C�Llist

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
void linklist::insert_node(node *ptr,node input) { //�H�U���J�`�I //�bC++�� head�i�H������ܼƨϥ� �T�M���ݭn�A��head��@�Ѽ�
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
node linklist::freenode (node *p) { //�H�U����`�I
	delete p;
}
void linklist::search_node(int num) {//�H�U�M��`�I
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
int linklist::delete_node(int value) {//�H�U�R���`�I
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
void stack::push(int value) {
	node input;
	input.data=value;
	insert_node(NULL,input);
}
int stack::pop() {
	if(head==NULL) {
		return -1;
	}
	int temp;
	node *ptr;
	ptr=head;
	temp=head->data;
	head=head->next;

	delete ptr;
	return temp;
}
int stack::printstack(node *ptr) { //�ϧǦC�Lstack�禡
	int count=0;
	if(ptr==NULL)return 0;
	while(ptr->next!=NULL) {
		count=count+printstack(ptr->next);
		break;
	}
	cout<<ptr->data<<"  ";
	count++;
	return count;
}
void stack::reverse_print(int size) { //�]�˦C�L�A�B����size�� 0
	int count;
	count=printstack(head);
	while(count!=size) {
		cout<<"0  ";
		count++;
	}
	cout<<endl;
}
void hanoi(int n,string from,string mid,string to,stack &froms,stack &mids,stack &tos,int size) {
	if(n>=1) {
		hanoi(n-1,from,to,mid,froms,tos,mids,size);
		cout<<"��L "<<n<<"�q"<<from<<"�� -> "<<to<<"��"<<endl;
		tos.push(froms.pop());
		if(from.compare(mid)<0) { //from<mid
			if(from.compare(to)<0) { //from<to
				if(mid.compare(to)<0) { //from<mid<to == A<B<C
					cout<<"Tower A: ";
					froms.reverse_print(size);
					cout<<"Tower B: ";
					mids.reverse_print(size);
					cout<<"Tower C: ";
					tos.reverse_print(size);
				} else { //from<to<mid == A<B<C
					cout<<"Tower A: ";
					froms.reverse_print(size);
					cout<<"Tower B: ";
					tos.reverse_print(size);
					cout<<"Tower C: ";
					mids.reverse_print(size);
				}
			} else {			//to<from<mid== A<B<C
				cout<<"Tower A: ";
				tos.reverse_print(size);
				cout<<"Tower B: ";
				froms.reverse_print(size);
				cout<<"Tower C: ";
				mids.reverse_print(size);
			}
		} else { 	//mid<from
			if(from.compare(to)<0) {	// mid<from<to ==A<B<C
				cout<<"Tower A: ";
				mids.reverse_print(size);
				cout<<"Tower B: ";
				froms.reverse_print(size);
				cout<<"Tower C: ";
				tos.reverse_print(size);
			} else {	//to<from
				if(mid.compare(to)<0) { //mid<to<from == A<B<C
					cout<<"Tower A: ";
					mids.reverse_print(size);
					cout<<"Tower B: ";
					tos.reverse_print(size);
					cout<<"Tower C: ";
					froms.reverse_print(size);
				} else {		//to<mid<from == A<B<C
					cout<<"Tower A: ";
					tos.reverse_print(size);
					cout<<"Tower B: ";
					mids.reverse_print(size);
					cout<<"Tower C: ";
					froms.reverse_print(size);
				}
			}
		}
		cout<<endl;
		hanoi(n-1,mid,from,to,mids,froms,tos,size);
	}
}
int main() {
	int n,i;
	cout<<"<< �e����C�� 2.0 >>"<<endl<<endl;
	cout<<"�п�J��L��:";
	cin>>n;
	stack A;
	stack B;
	stack C;
	for(i=0; i<n; i++) {
		A.push(n-i);
	}
	cout<<"Tower A: ";
	A.reverse_print(n);
	cout<<"Tower B: ";
	B.reverse_print(n);
	cout<<"Tower C: ";
	C.reverse_print(n);
	cout<<endl;
	hanoi(n,"A","B","C",A,B,C,n);
}
