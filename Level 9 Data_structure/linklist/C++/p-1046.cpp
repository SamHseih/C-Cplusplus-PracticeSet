#include<iostream>
#include <string>
#include <stdlib.h>
using namespace std;

template <class T>
class node {
		template <class T2>friend class linklist;
	private:
		T data;
		node<T> *next;
};

template <class T>
class linklist {
	public:
		linklist();
		void insertLast(T value);
		void printlist();


	private:
		node<T> *head;
		node<T> *tail;
		node<T> *getnode();
		void insert_node(node<T> *ptr,node<T> input);
		node<T> freenode (node<T> *p);

};

template <class T>
linklist<T>::linklist() {
	head=NULL;
	tail=NULL;
}
template <class T>
void linklist<T>::insertLast(T value) {//�H�U�s�W�`�I
	node<T> input;
	input.data=value;
	insert_node(tail,input);
	if(tail==NULL) {
		tail=head;
	} else {
		tail=tail->next;
	}
}
template <class T>
node<T> *linklist<T>::getnode() {
	node<T> *p;
	p=new node<T>;
	/*if(p==NULL){
		exit(1);
	}*/
	return p;
}
template <class T>
void linklist<T>::printlist() {//�H�U�C�Llist

	node<T> *ptr=head;
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
template <class T>
void linklist<T>::insert_node(node<T> *ptr,node<T> input) { //�H�U���J�`�I //�bC++�� head�i�H������ܼƨϥ� �T�M���ݭn�A��head��@�Ѽ�
	node<T> *new_node; /* �s�`�I�����ܼ�*/
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
template <class T>
node<T> linklist<T>::freenode (node<T> *p) {//�H�U����`�I
	delete p;
}

int main() {

	int i,value;
	string a;
	linklist<int> s1;
	linklist<string> s2;
	do {
		cin>>value;
		if(value!=-1)s1.insertLast(value);
	} while(value!=-1);
	s1.printlist();
	do {
		cin>>a;
		if(a!="q")s2.insertLast(a);
	} while(a!="q");
	s2.printlist();
	return 0;
}


