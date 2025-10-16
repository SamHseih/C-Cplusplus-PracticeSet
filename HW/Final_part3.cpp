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
int stack::printstack(node *ptr) { //反序列印stack函式
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
void stack::reverse_print(int size) { //包裝列印，且未滿size補 0
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
		cout<<"圓盤 "<<n<<"從"<<from<<"塔 -> "<<to<<"塔"<<endl;
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
	cout<<"<< 河內塔遊戲 2.0 >>"<<endl<<endl;
	cout<<"請輸入圓盤數:";
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
