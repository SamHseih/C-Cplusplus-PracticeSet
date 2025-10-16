#include<iostream>
using namespace std;
class node {
		friend class linklist;
		friend class stack;
		friend class queue;
	private:
		int data;
		node *next;

};
class linklist {
	public:
		linklist();
		void printlist();
		void search_node(int num);
		int delete_node(int value);

	protected:
		node *head;
		node *tail;
		node *getnode();
		void insert_node(node *ptr,node input);
		node freenode (node *p);

};
class stack:protected linklist {
	public:
		void push(int value);
		int pop();
};
class queue:protected linklist {
	public:
		void enqueue(int value);
		int dequeue();
	private:
		
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
void queue::enqueue(int value) {
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
int queue::dequeue() {
	if(head==NULL){
		return -1;
	}
	node *ptr;
	ptr=head;
	int tmp=ptr->data;
	head=head->next;
	delete ptr;
	return tmp;
}
int main() {
	
	int i,N,M,value,j;
   //new�B��l�|�t�m�@��int�һݭn���Ŷ��A�öǦ^�ӪŶ�����}�A�ҥH�z�ϥΫ���p���x�s�o�Ӧ�}
	cin>>N>>M;
	//cout<<"N ="<<N<<endl;;
	stack *s=new stack[N];   //stack s[N]
	queue *q=new queue[N];	// queue q[N]
	 
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			cin>>value;
			s[j].push(value);
			q[j].enqueue(value);
		}	
		//cout<<"���}��"<<i<<"���J"<<endl; 
	}

	cout<<"Stack Output:"<<endl;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			cout<<s[i].pop()<<" ";
		}cout<<endl;	
	}
	cout<<"Queue Output:"<<endl;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			cout<<q[i].dequeue()<<" ";
		}cout<<endl;
		}
	delete s;
	delete q;
	return 0;
}
