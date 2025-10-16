#include<iostream>
#include<cstdlib>   // 需要用到exit的標頭檔
#include<stdlib.h>
#include<string.h>
using namespace std;
class Binarytree_node { //node 定義
		friend class Binarytree;
	private:
		char phonenumber[15];
		char name[128];
		int mark;
		Binarytree_node *left;
		Binarytree_node *right;
};
typedef Binarytree_node node;
class Binarytree { //二元樹class

	public:
		Binarytree();
		void Insert(char Name[128],char number[15]);
		void Inorder();
		void Preorder();
		void Postorder();
		void Search_name(char n[128]);
		void Search_mark(int n);
		void parent_name(char p[128]);
		void parent_mark(int n);
		void delete_name(char a[128]);
		void delete_mark(int n);

	private:
		node *root;
		int mark;
		node *insert_node(node *root,node data);
		void print_Inorder(node *ptr);
		void print_preorder(node *ptr);
		void print_postorder(node *ptr);
		node *Binsearch_name(node *root,char n[128]);
		node *PreorderSearch_mark(node *ptr,int value);
		node *findparent_name(node *ptr,char name[128],int *pos);
		node *findparent_mark(node *ptr,node *parent,int value);
		void deletenode_name(node *root, char name[128]);
		void deletenode_mark(node *root,int value);

};
Binarytree::Binarytree() { //初始化建構式
	root=NULL;
	mark=0;
}
void Binarytree::Inorder() { //中序列印包裝
	print_Inorder(root);

}
void Binarytree::Preorder() { //前序列印包裝
	print_preorder(root);
}
void Binarytree::Postorder() { //後序列印包裝
	print_postorder(root);
}
void Binarytree::Insert(char Name[128],char number[15]) {   //插入函式包裝
	node new_node;
	strcpy(new_node.phonenumber,number);
	strcpy(new_node.name,Name);
	mark ++;
	new_node.mark=mark;
	root=insert_node(root,new_node);
}
void Binarytree::Search_name(char n[128]) { //搜尋名字包裝
	node *ptr;
	ptr=Binsearch_name(root,n);
	if(ptr==NULL) {
		cout<<"CanNot found"<<endl;
	} else {
		cout<<"found"<<endl;
		cout<<"Name :"<<ptr->name<<endl;
		cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
		cout<<"Mark :"<<ptr->mark<<endl;
	}
}
void Binarytree::Search_mark(int n) { //搜尋編號包裝
	node *p=NULL;
	p=PreorderSearch_mark(root,n);
	if(p==NULL) {
		cout<<"CanNot found"<<endl;
	} else {
		cout<<"found"<<endl;
		cout<<"Name :"<<p->name<<endl;
		cout<<"Phonenumber :"<<p->phonenumber<<endl;
		cout<<"Mark :"<<p->mark<<endl;
	}
}
void Binarytree::parent_name(char p[128]) { //尋找名字的父點包裝
	node *ptr;
	int pos=0;
	ptr=findparent_name(root,p,&pos);
	if(ptr==NULL)cout<<"no parents"<<endl;
	else {
		cout<<"Parent Name :"<<ptr->name<<endl;
		cout<<"Pos :"<<pos<<endl;
	}
}
void Binarytree::parent_mark(int n) { //尋找編號的父點包裝
	node *ptr;
	ptr=findparent_mark(root,root,n);
	if(ptr==NULL)cout<<"no parents"<<endl;
	else {
		cout<<"Parent Mark :"<<ptr->mark<<endl;
	}
}
void Binarytree::delete_name(char a[128]) { //刪除名字節點包裝
	deletenode_name(root,a);
}
void Binarytree::delete_mark(int n) { //刪除編號節點包裝
	deletenode_mark(root,n);
}
void Binarytree::print_Inorder(node *ptr) {  //中序列印函式
	if(ptr!=NULL) {
		print_Inorder(ptr->left);
		cout<<"Name :"<<ptr->name<<endl;
		cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
		cout<<"Mark :"<<ptr->mark<<endl<<endl;
		print_Inorder(ptr->right);
	}
}
void Binarytree::print_preorder(node *ptr) { //前序列印函式
	if(ptr!=NULL) {
		cout<<"Name :"<<ptr->name<<endl;
		cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
		cout<<"Mark :"<<ptr->mark<<endl<<endl;
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}
}
void Binarytree::print_postorder(node *ptr) { //後序列印函式
	if(ptr!=NULL) {
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		cout<<"Name :"<<ptr->name<<endl;
		cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
		cout<<"Mark :"<<ptr->mark<<endl<<endl;
	}
}
node *Binarytree::insert_node(node *root,node data) { //插入函式
	node *new_node;
	node *current;
	node *parent;
	new_node= new node;
	*new_node=data;
	new_node->left=NULL;
	new_node->right=NULL;
	if(root == NULL) {
		root=new_node;   //return new_node;
	} else {
		current = root;
		while(current != NULL) {
			parent = current;
			if(strcmp(current->name,new_node->name)>0)   //current->data > value
				current = current->left;
			else
				current = current->right;
		}
		if(strcmp(parent->name,new_node->name)>0)
			parent->left = new_node;
		else
			parent->right = new_node;
	}
	return root;
}
node *Binarytree::Binsearch_name(node *ptr,char n[128]) { //二元搜尋名字函式
	if(ptr!=NULL) {
		if(strcmp(ptr->name,n)==0) { //root->name==n
			//printf("found %d",root->data);
			return ptr;
		}
		if(strcmp(ptr->name,n)>0) { //n<root->data
			//printf("往左邊找中...\n");
			ptr=Binsearch_name(ptr->left,n);

		} else if(strcmp(ptr->name,n)<0) { //n>root->data
			//printf("往右邊找中...\n");
			ptr=Binsearch_name(ptr->right,n);
		}
	} else {
		return NULL;
	}

}
node *Binarytree::PreorderSearch_mark(node *ptr,int value) { //前序尋找標籤函式
	node *target=NULL;
	if(ptr!=NULL) {
		if(ptr->mark==value) return ptr;
		else {
			if(ptr->left!=NULL) {
				target=PreorderSearch_mark(ptr->left,value);
				if(target!=NULL&&target->mark==value) return target;
				if(ptr->right!=NULL) {
					target=PreorderSearch_mark(ptr->right,value);
					if(target!=NULL&&target->mark==value) return target;
				}
			}
			return target;
		}
	} else {
		return NULL;
	}
}
node *Binarytree::findparent_name(node *ptr,char name[128],int *pos) { //尋找名字的父點函式


	node *parent;
	parent = ptr;	// 從ptr開始找
	*pos = 0;
	while(ptr!=NULL) {
		if(strcmp(ptr->name,name)==0)	// 找到目標 //ptr->data == value
			return parent;		// 回傳此節點之父節點
		else {
			parent = ptr;
			if(strcmp(ptr->name,name)>0) { //ptr->data > value
				*pos = -1;			// ptr在parent左子樹
				ptr = ptr->left;	// 往左找
			} else {
				*pos = 1;			// ptr在parent右子樹
				ptr = ptr->right;	// 往右找
			}
		}
	}
	return NULL;	// 找不到
}
node *Binarytree::findparent_mark(node *ptr,node *parent,int value) { // 尋找編號的父點函式
	if(ptr!=NULL) {
		node *target=NULL;
		if(ptr->mark==value)return parent;
		else {
			parent=ptr;
			if(ptr->left!=NULL) {
				target=findparent_mark(ptr->left,parent,value);
			}
			if(ptr->right!=NULL&&target==NULL) {
				target=findparent_mark(ptr->right,parent,value);
			}
			return target;
		}
	}
}
void Binarytree::deletenode_name(node *root, char name[128]) { //刪除名字節點函式 
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = findparent_name(root, name, &pos);	// 從root開始,找value之父節點
	if(parent != NULL) {	// 有找到, 準備刪除
		switch(pos) {	// 判斷目前節點再父節點左邊或右邊
			case -1:
				ptr = parent->left;
				break;
			case 1:
				ptr = parent->right;
				break;
			case 0:
				ptr = parent;
				break;
		}
		if(ptr->left == NULL) {	// 情況1: 節點沒有左子樹 如果要刪的是根節點
			if(parent == ptr)	// 如果要刪的是根節點
				root = root->right;
			else {			// 其他
				if( pos == 1 ) {
					//要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的右節點
					parent->right = ptr->right;
				} else {
					//要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的右節點
					parent->left = ptr->right;
				}
			}
			
			cout<<"Name :"<<ptr->name<<endl;
			cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
			cout<<"Mark :"<<ptr->mark<<endl<<endl;
			cout<<"delete "<<ptr->name<<" OK"<<endl;
			delete ptr;
		} else if(ptr->right == NULL) {	// 情況2: 節點沒有右子樹
			if(parent != ptr) {
				if( pos == 1 ) {
					//要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的左節點
					parent->right = ptr->left;
				} else {
					//要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的左節點
					parent->left = ptr->left;
				}
			} else
				root = root->left;
			cout<<"Name :"<<ptr->name<<endl;
			cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
			cout<<"Mark :"<<ptr->mark<<endl<<endl;
			cout<<"delete "<<ptr->name<<" OK"<<endl;
			delete ptr;
		} else {					// 情況3: 節點有左右子樹
			parent = ptr;
			next = ptr->left;	// 找取代點next, 從ptr左邊開始找
			if(next->right!=NULL) {
				while(next->right != NULL) {	// 往左子節點之右子樹找最大值當取代點
					parent = next;		// parent為next之父節點
					next = next->right;
				}
				parent->right = next->left; // 繞過next節點
			} else {
				ptr->left=next->left;
			}
			cout<<"Name :"<<ptr->name<<endl;
			cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
			cout<<"Mark :"<<ptr->mark<<endl<<endl;
			cout<<"delete "<<ptr->name<<" OK"<<endl;
			strcpy(ptr->name,next->name);//ptr->data = next->data;		// 取代!!
			strcpy(ptr->phonenumber,next->phonenumber);
			ptr->mark=next->mark;
			delete next;// 刪除next (注意: 不是刪除ptr)
		}
	} else {
		cout<<"cannot delete"<<endl;
	}
}
void Binarytree::deletenode_mark(node *root,int value) { //刪除編號節點函式

	node *ptr,*parent,*next;
	ptr=PreorderSearch_mark(root,value); //ptr指向刪除點位置
	if(ptr==NULL)printf("cannot delete\n");
	else {
		if(ptr->mark==value&&ptr->left==NULL) { //case 1 沒有左子樹
			if(ptr==root) {
				root=root->right;  
					cout<<"Name :"<<ptr->name<<endl;
					cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
					cout<<"Mark :"<<ptr->mark<<endl<<endl;
					cout<<"delete "<<ptr->mark<<" OK"<<endl; 
					delete ptr;   //刪除點為root case1.1
			} else {
				parent=findparent_mark(root,root,value);//指出父點位置
				if(ptr==parent->left) { //刪除點位於父點左邊 case 1.2
					cout<<"Name :"<<ptr->name<<endl;
					cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
					cout<<"Mark :"<<ptr->mark<<endl<<endl;
					cout<<"delete "<<ptr->mark<<" OK"<<endl;
					delete ptr;
				} else if(ptr==parent->right) { //刪除點位於父點右邊 case 1.3
					parent->right=ptr->right;
					cout<<"Name :"<<ptr->name<<endl;
					cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
					cout<<"Mark :"<<ptr->mark<<endl<<endl;
					cout<<"delete "<<ptr->mark<<" OK"<<endl;
					delete ptr;
				}
			}

		}

		else if(ptr->mark==value&&ptr->right==NULL) { //case 2 沒有右子樹
			if(ptr==root) {
				root=root->left; 
				
				cout<<ptr->mark<<" "<<endl; 
				cout<<"Name :"<<ptr->name<<endl;
				cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
				cout<<"Mark :"<<ptr->mark<<endl<<endl;
				cout<<"delete "<<ptr->mark<<" OK"<<endl;
				delete ptr;   //刪除點為root case2.1
			} else {
				parent=findparent_mark(root,root,value);//指出父點位置
				if(ptr==parent->left) { //刪除點位於父點左邊 case 2.2
					parent->left=ptr->left;
				cout<<"Name :"<<ptr->name<<endl;
				cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
				cout<<"Mark :"<<ptr->mark<<endl<<endl;
				cout<<"delete "<<ptr->mark<<" OK"<<endl;
					delete ptr;
				} else if(ptr==parent->right) { //刪除點位於父點右邊 case 2.3
					parent->right=ptr->left;
				cout<<"Name :"<<ptr->name<<endl;
				cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
				cout<<"Mark :"<<ptr->mark<<endl<<endl;
				cout<<"delete "<<ptr->mark<<" OK"<<endl;
					delete ptr;
				}
			}

		} else { //有左子樹也有右子樹  //運用左子樹最大代替

			next=ptr->left;
			if(next->right!=NULL) {
				while(next->right!=NULL) {
					next=next->right;
				}
				parent=findparent_mark(root,root,next->mark);
				parent->right=next->right;
			} else {
				ptr->left=next->left;
			}
			cout<<"Name :"<<ptr->name<<endl;
			cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
			cout<<"Mark :"<<ptr->mark<<endl<<endl;
			cout<<"delete "<<ptr->mark<<" OK"<<endl;
			strcpy(ptr->phonenumber,next->phonenumber);
			ptr->mark=next->mark;
			strcpy(ptr->name,next->name);
			delete next;
		}
	}
}
int main() {
	int i,value;
	char a;
	Binarytree b;
	while(1) {
		cout<<"i 新增 d刪除(名字) r刪除(編號) f搜尋(姓名) l前/中/後列印 q離開"<<endl;
		cin>>a;
		switch(a) {
			case 'i': {  //新增節點,可輸入姓名, 電話,並自動加入編號依據姓名字母順序插入節點(假設輸入之姓名不會重覆)
				char Name[128],number[15];	
				cout<<"請輸入姓名,電話:"<<endl;
				cin>>Name>>number;
				b.Insert(Name,number);
				cout<<"插入完畢..."<<endl;
				break;
			}
			case 'd': {
				char d[128];
				cout<<"請輸入需刪除的姓名:"<<endl;
				cin>>d;
				b.delete_name(d);
				break;
			}
			case 'r': {
				cout<<"請輸入需刪除的編號:"<<endl;
				int n;
				cin>>n;
				b.delete_mark(n);
				break;
			}
			case 'f': {
				cout<<"請輸入尋找的姓名:"<<endl;
				char n[128];
				cin>>n;
				b.Search_name(n);
				break;
			}
			case 'l': { //可依據姓名字母順序、前/中/後序印出所有節點內容
				cout<<" Preorder :"<<endl<<endl;
				b.Preorder();
				cout<<" Inorder :"<<endl<<endl;
				b.Inorder();
				cout<<" Postorder :"<<endl<<endl;
				b.Postorder();
				break;
			}
			case 'q': {
				return 0;
				break;
			}
		}
		system("pause");
		system("cls");
		
	}
}
