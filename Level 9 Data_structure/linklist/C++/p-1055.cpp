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
void linklist<T>::insertLast(T value) {//以下新增節點
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
void linklist<T>::printlist() {//以下列印list

	node<T> *ptr=head;
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
template <class T> 
void linklist<T>::find(T value){//以下尋找包裝 
	node<T> *ptr;
	ptr=find_node(value);
	cout<<"Find "<<value<<endl;
	if(ptr!=NULL){
		
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
}
template <class T>  
void linklist<T>::Delete(T value){//以下刪除包裝
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
void linklist<T>::insert_node(node<T> *ptr,node<T> input) { //以下插入節點 //在C++中 head可以當全域變數使用 固然不需要再有head當作參數
	node<T> *new_node; /* 新節點指標變數*/
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
template <class T>
node<T> *linklist<T>::find_node(T &num){//以下尋找節點 
	node<T> *ptr;
	ptr = head; /* 指向串列起始 */
	while ( ptr != NULL ) /* 走訪串列 */
	{ 
		if ( ptr->data == num ) /* 找尋data */
		return (ptr);
		ptr = ptr->next; /* 指向下一節點 */
	} 
	return (ptr);
}
template <class T>
void linklist<T>::delete_node(node<T> *ptr) { //此ptr是已經知道位置 //以下刪除節點

	node<T> *previous; /* 指向前一節點 */
	if ( ptr == head ) /* 是否是串列開始 */
	/* 第一種情況: 刪除第一個節點 */
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while ( previous->next != ptr ) /* 找節點ptr的前節點 */
			previous = previous->next;
		if ( ptr->next == NULL ) /* 是否是串列結束 */
		/* 第二種情況: 刪除最後一個節點 */
			previous->next = NULL; /* 最後一個節點 */
		else
		/* 第三種情況: 刪除中間節點 */
			previous->next = ptr->next; /* 圖(3)之步驟(1) */
	}
	
	delete ptr; /* 此函數將節點歸還給記憶體 */
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


