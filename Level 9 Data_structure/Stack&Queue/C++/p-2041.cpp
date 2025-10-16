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
node *linklist::getnode() { //以下新增節點
	node *p;
	p=new node;
	/*if(p==NULL){
		exit(1);
	}*/
	return p;
}
void linklist::printlist() { //以下列印list

	node *ptr=head;
	if(ptr==NULL) {
		//printf("請新增資料...");
	} else {

		while(ptr!=NULL) {
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
}
void linklist::insert_node(node *ptr,node input) { //以下插入節點 //在C++中 head可以當全域變數使用 固然不需要再有head當作參數
	node *new_node; /* 新節點指標變數*/
	new_node = getnode(); /* 建立新節點,取得一個可用節點*/
	*new_node = input; /* 建立節點內容*/   //前面  星號+指標變數  = 指標位置的整塊資料  含Data與指標   ((運用在多重data時，可使用此寫法 例如有 data1 座號 data2 地址 dat3 身分證 此寫法包了全部
	new_node->next = NULL; /* 設定指標初值*/

	if(ptr==NULL) { /* 指標ptr是否是NULL */

		/* 第一種情況: 插入第一個節點*/
		new_node->next = head; /* 新節點成為串列開始*/
		head = new_node;
	} else {
		if(ptr->next==NULL)/* 是否是串列結束*/
			/* 第二種情況: 插入最後一個節點*/
			ptr->next=new_node; /* 最後指向新節點*/

		else {

			/* 第三種情況: 插入成為中間節點*/
			new_node->next=ptr->next;/* (3) 新節點指向下一節點(3)*/
			ptr->next=new_node;/* 節點ptr指向新節點(4)*/
		}

	}
}
node linklist::freenode (node *p) { //以下釋放節點
	delete p;
}
void linklist::search_node(int num) {//以下尋找節點
	node *ptr;
	ptr=head;
	//printf("尋找值為 -> %d\n",num);
	//printf("目前值為 -> %d\n",ptr->data);
	while(ptr->data!=num) {
		//printf("ptr data -> %d \ninput data ->%d\n",ptr->data,num);
		ptr=ptr->next;
		if(ptr==NULL)break;

	}
	//printf("搜尋完成...跳出search迴圈 \n");
	if(ptr==NULL)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;

}
int linklist::delete_node(int value) {//以下刪除節點
	node *previous;
	node *ptr;
	ptr=head;
	if(ptr==NULL) {
		cout<<"請新增資料..from刪除函式"<<endl;
	} else {

		while(ptr->data!=value) {
			ptr=ptr->next;
			if(ptr==NULL)break;
		}

		if(ptr==NULL) {
			//cout<<"無此data:"<<value<<endl;
			return 0;
		}

		if(ptr==head) {
			//puts("第一種..");
			head=head->next;
			tail=head;

		} else {
			previous=head;
			while(previous->next!=ptr) {
				previous=previous->next;
			}

			if(ptr==tail) {
				//puts("第二種..");
				previous->next=NULL;
				tail=previous;
			}

			else {
				//puts("第三種..");
				previous->next=ptr->next;
			}

		}
		//puts("刪除中...");
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
   //new運算子會配置一個int所需要的空間，並傳回該空間的位址，所以您使用指標p來儲存這個位址
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
		//cout<<"離開第"<<i<<"次入"<<endl; 
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
