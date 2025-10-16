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
		
	//以下新增節點 
node *linklist::getnode(){
	node *p;
	p=new node;
		if(p==NULL){
			exit(1);
		}
	return p;
}

//以下列印list
void linklist::printlist(){
		
		node *ptr=head;
		if(ptr==NULL){
			printf("請新增資料...");
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

//以下插入節點 
void linklist::insert_node(node *ptr,node input){   //在C++中 head可以當全域變數使用 固然不需要再有head當作參數 
		node *new_node; /* 新節點指標變數*/
		new_node = getnode(); /* 建立新節點,取得一個可用節點*/
		*new_node = input; /* 建立節點內容*/   //前面  星號+指標變數  = 指標位置的整塊資料  含Data與指標   ((運用在多重data時，可使用此寫法 例如有 data1 座號 data2 地址 dat3 身分證 此寫法包了全部 
		new_node->next = NULL; /* 設定指標初值*/ 
	
	if(ptr==NULL){/* 指標ptr是否是NULL */
		
		/* 第一種情況: 插入第一個節點*/
		new_node->next = head; /* 新節點成為串列開始*/
		head = new_node;
	}
	else {
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
//以下釋放節點
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


