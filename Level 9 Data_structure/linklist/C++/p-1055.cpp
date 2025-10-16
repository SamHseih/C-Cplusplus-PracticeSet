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
		void find(T value);
		void Delete(T value);


	private:
		node<T> *head;
		node<T> *tail;
		node<T> *getnode();
		void insert_node(node<T> *ptr,node<T> input);
		node<T> *find_node(T &num);
		void delete_node(node<T> *ptr);
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
void linklist<T>::find(T value){//�H�U�M��]�� 
	node<T> *ptr;
	ptr=find_node(value);
	cout<<"Find "<<value<<endl;
	if(ptr!=NULL){
		
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
}
template <class T>  
void linklist<T>::Delete(T value){//�H�U�R���]��
	node<T> *ptr;
	ptr=find_node(value);
	if(ptr!=NULL){
		cout<<"Delete "<<ptr->data<<endl;
		delete_node(ptr);
		printlist();
	}
	//cout<<"can't delete"<<endl;
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
node<T> *linklist<T>::find_node(T &num){//�H�U�M��`�I 
	node<T> *ptr;
	ptr = head; /* ���V��C�_�l */
	while ( ptr != NULL ) /* ���X��C */
	{ 
		if ( ptr->data == num ) /* ��Mdata */
		return (ptr);
		ptr = ptr->next; /* ���V�U�@�`�I */
	} 
	return (ptr);
}
template <class T>
void linklist<T>::delete_node(node<T> *ptr) { //��ptr�O�w�g���D��m //�H�U�R���`�I

	node<T> *previous; /* ���V�e�@�`�I */
	if ( ptr == head ) /* �O�_�O��C�}�l */
	/* �Ĥ@�ر��p: �R���Ĥ@�Ӹ`�I */
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while ( previous->next != ptr ) /* ��`�Iptr���e�`�I */
			previous = previous->next;
		if ( ptr->next == NULL ) /* �O�_�O��C���� */
		/* �ĤG�ر��p: �R���̫�@�Ӹ`�I */
			previous->next = NULL; /* �̫�@�Ӹ`�I */
		else
		/* �ĤT�ر��p: �R�������`�I */
			previous->next = ptr->next; /* ��(3)���B�J(1) */
	}
	
	delete ptr; /* ����ƱN�`�I�k�ٵ��O���� */
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
	cin>>value;
	s1.Delete(value);
	cin>>value;
	s1.find(value);
	do {
		cin>>a;
		if(a!="q")s2.insertLast(a);
	} while(a!="q");
	s2.printlist();
	cin>>a;
	s2.Delete(a); 

	cin>>a;
	s2.find(a);
	
	return 0;
}


