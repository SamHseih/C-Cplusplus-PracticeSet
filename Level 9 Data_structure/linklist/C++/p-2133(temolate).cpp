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
		int length();
		int size;


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
	size=0;
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
	if(ptr!=NULL){
		cout<<"found "<<value<<endl;
	}
	else cout<<"No found"<<endl;
}
template <class T>  
void linklist<T>::Delete(T value){//�H�U�R���]��
	node<T> *ptr;
	ptr=find_node(value);
	if(ptr!=NULL){
		cout<<"Delete ok"<<endl;
		delete_node(ptr);
	
	}
	//cout<<"can't delete"<<endl;
}
template <class T>
int linklist<T>::length(){
	return size;
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
	size++;
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
	size--;
	delete ptr; /* ����ƱN�`�I�k�ٵ��O���� */
}

int main() {
	linklist<int> l1;
	linklist<double> l2;
	linklist<char> l3;
	linklist<string> l4;
	int value;
	double x;
	string s;
	char f;
	int type;
	char key;
		
		cin>>type;
		switch(type){
			case 1:{
				cout<<"<Integer List>"<<endl;
					while(1)
					{
						cin>>key;
						switch(key){
							case 'i':
								//cout << "��J���J��Ƥ��e: ";
								cin >> value;
								l1.insertLast(value);
								break;
							case 'd':
								//cout << "��J�R����Ƥ��e: ";
								cin >> value;
								l1.Delete(value);
								break;
							case 'f':
								//cout << "��J�M���Ƥ��e: ";
								cin >> value;
								l1.find(value);
								break;
							case 'l':
								l1.printlist();
								break;
							case 'c':
								cout <<l1.length()<< endl;
							case 'q':
								exit(0);
							default:
								cout << "��J�ȿ��~!" << endl; 
						}
					}
				break;
			}
			case 2:{
				cout<<"<Double List>"<<endl;
					while(1)
					{
						cin>>key;
						switch(key){
							case 'i':
								//cout << "��J���J��Ƥ��e: ";
								cin >> x;
								l2.insertLast(x);
								break;
							case 'd':
								//cout << "��J�R����Ƥ��e: ";
								cin >> x;
								l2.Delete(x);
								break;
							case 'f':
								//cout << "��J�M���Ƥ��e: ";
								cin >> x;
								l2.find(x);
								break;
							case 'l':
								l2.printlist();
								break;
							case 'c':
								cout <<l2.length()<< endl;
							case 'q':
								exit(0);
							default:
								cout << "��J�ȿ��~!" << endl; 
						}
					}
				break;
			}
			case 3:{
				cout<<"<Char List>"<<endl;
						while(1)
						{
							cin>>key;
						switch(key){
							case 'i':
								//cout << "��J���J��Ƥ��e: ";
								cin >> f;
								l3.insertLast(f);
								break;
							case 'd':
								//cout << "��J�R����Ƥ��e: ";
								cin >> f;
								l3.Delete(f);
								break;
							case 'f':
								//cout << "��J�M���Ƥ��e: ";
								cin >> f;
								l3.find(f);
								break;
							case 'l':
								l3.printlist();
								break;
							case 'c':
								cout <<l3.length()<< endl;
							case 'q':
								exit(0);
							default:
								cout << "��J�ȿ��~!" << endl; 
						}
					}
				break;
			}
			case 4:{
				cout<<"<String List>"<<endl;
						while(1)
						{
							cin>>key;
						switch(key){
							case 'i':
								//cout << "��J���J��Ƥ��e: ";
								cin >> s;
								l4.insertLast(s);
								break;
							case 'd':
								//cout << "��J�R����Ƥ��e: ";
								cin >> s;
								l4.Delete(s);
								break;
							case 'f':
								//cout << "��J�M���Ƥ��e: ";
								cin >> s;
								l4.find(s);
								break;
							case 'l':
								l4.printlist();
								break;
							case 'c':
								cout <<l4.length()<< endl;
							case 'q':
								exit(0);
							default:
								cout << "��J�ȿ��~!" << endl; 
						}
					}
				break;
			}
		}
return 0;
}


