#include<iostream>
#include<cstdlib>   // �ݭn�Ψ�exit�����Y��
#include<string>
#include<string.h>
using namespace std;
template <class T>
class node{ //node �w�q 
	template <class T2> friend class Binarytree;
	private:
		T data;
		node<T> *left;
		node<T> *right;
};

template <class T>
class Binarytree{  //�G����class
	
	public:
	Binarytree();
	void insert_node(T value);
	void Inorder();
	void Preorder();
	void Postorder();
	void Search(T value);
	void Delete(T value);
	
	private:
	node<T> *root;
	node<T> *Binsearch(node<T> *ptr,T n);
	void print_Inorder(node<T> *ptr);
	void print_preorder(node<T> *ptr);
	void print_postorder(node<T> *ptr);
	node<T> *findparent(node<T> *ptr,T value);
	void *deletenode(node<T> *root,T value);
};

template <class T>
Binarytree<T>::Binarytree(){ //��l�ƫغc�� 
	root=NULL;
}
template <class T>
void Binarytree<T>::insert_node(T value){ //���J�禡 
	node<T> *new_node;
	node<T> *current;
	node<T> *parent;
	new_node=new node<T>;
	new_node->data=value;
	new_node->left=NULL;
	new_node->right=NULL;
	if(root == NULL)
		{root=new_node;} //return new_node;
	else
		{
			current = root;
			while(current != NULL)
			{
				parent = current;
				if(current->data>value)   
					current = current->left; 
				else
					current = current->right; 
			}
			if(parent->data>value)
				parent->left = new_node;
			else
				parent->right = new_node;
		}
}
template <class T>
void Binarytree<T>::Inorder(){  //���ǦC�L�]�� 
	print_Inorder(root);
}
template <class T>
void Binarytree<T>::Preorder(){ //�e�ǦC�L�]�� 
	print_preorder(root);
}
template <class T>
void Binarytree<T>::Postorder(){ //��ǦC�L�]�� 
	print_postorder(root);
}
template <class T>
void Binarytree<T>::Search(T value){ //�j�M�]�� 
	
	if(Binsearch(root,value)==NULL)
		cout<<"not found"<<endl;
		else 	cout<<"found: "<<value<<endl;
}
template <class T>
void Binarytree<T>::Delete(T value){  //�R���]�� 
	deletenode(root,value);
}
template <class T>
void Binarytree<T>::print_Inorder(node<T> *ptr){   //���ǦC�L�禡 
	if(ptr!=NULL){
		print_Inorder(ptr->left);
		cout<<ptr->data<<" ";//printf("%d ",ptr->data);
		print_Inorder(ptr->right);
	}
}
template <class T>
void Binarytree<T>::print_preorder(node<T> *ptr){ //�e�ǦC�L�禡 
	if(ptr!=NULL){
		cout<<ptr->data<<" ";//printf("%d ",ptr->data);		
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}
}
template <class T>
void Binarytree<T>::print_postorder(node<T> *ptr){ //��ǦC�L�禡 
	if(ptr!=NULL){
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		cout<<ptr->data<<" "; //printf("%d ",ptr->data);	
	}
}
template <class T>
node<T> *Binarytree<T>::Binsearch(node<T> *ptr,T n){  //�G���j�M�禡 
	if(ptr!=NULL){
		if(ptr->data==n){
			//cout<<"found "<<ptr->data<<endl;
			//cout<<"Yes"<<endl;
			return ptr;
		}
		if(n<ptr->data){
			//printf("������䤤...\n");
			ptr=Binsearch(ptr->left,n);
			
		}
		else if(n>ptr->data){
			//printf("���k��䤤...\n");
			ptr=Binsearch(ptr->right,n);
		}
	}
	//if(ptr==NULL)cout<<"No"<<endl;
	return ptr;
}
template <class T>
node<T> *Binarytree<T>::findparent(node<T> *ptr,T value){  //�qptr�}�l��Y�� �����I�禡 
	node<T> *parent;

		parent=NULL;
	while(ptr!=NULL){
		
	if(ptr->data==value){
		return parent;
		}
		parent=ptr;
	if(ptr->data>value){ //�������M��

		ptr=ptr->left;
		} 
	else if(ptr->data<value) { //���k�M��

		ptr=ptr->right;
		}	
	}
	return NULL;
}
template <class T> 
void *Binarytree<T>::deletenode(node<T> *root,T value){ //�R���`�I�禡 
	
	node<T> *ptr,*parent,*next;
	
	ptr=Binsearch(root,value); //ptr���V�R���I��m 
if(ptr==NULL)cout<<"cannot delete"<<endl;
else{
		if(ptr->data==value&&ptr->left==NULL){ //case 1 �S�����l�� 
			if(ptr==root){root=root->right;cout<<"delete "<<ptr->data<<" ok"<<endl;delete(ptr);} //�R���I��root case1.1
			else {
				parent=findparent(root,value);//���X���I��m 
					if(ptr==parent->left){ //�R���I�����I���� case 1.2 
						parent->left=ptr->right;
						cout<<"delete "<<ptr->data<<" ok"<<endl;
						delete(ptr);
					}
					else if(ptr==parent->right){ //�R���I�����I�k�� case 1.3
						parent->right=ptr->right;
						cout<<"delete "<<ptr->data<<" ok"<<endl;
						delete(ptr);
					}
			}
			
		}
		else if(ptr->data==value&&ptr->right==NULL){ //case 2 �S���k�l�� 
			if(ptr==root){root=root->left;cout<<"delete "<<ptr->data<<" ok"<<endl;delete(ptr);} //�R���I��root case2.1
			else {
				parent=findparent(root,value);//���X���I��m 
					if(ptr==parent->left){ //�R���I�����I���� case 2.2 
						parent->left=ptr->left;
						cout<<"delete "<<ptr->data<<" ok"<<endl;
						delete(ptr);
					}
					else if(ptr==parent->right){ //�R���I�����I�k�� case 2.3 
						parent->right=ptr->left;
						cout<<"delete "<<ptr->data<<" ok"<<endl;
						delete(ptr);
					}
			}
			
		}
		else {  //�����l��]���k�l��  //�B�Υ��l��̤j�N�� 
			
				next=ptr->left;
				if(next->right!=NULL){
				while(next->right!=NULL){
					next=next->right;
				}
				parent=findparent(ptr,next->data);
				parent->right=next->right;
				}
				else{
					ptr->left=next->left;
				}
			cout<<"delete "<<ptr->data<<" ok"<<endl;
			ptr->data=next->data;	
			delete(next);
		}
	}
}

template<class T>
void uselist(T value){

	char key;
	Binarytree<T> list;
	while(1)
		{
			cin>>key;
			switch(key){
				case 'i':
					//cout << "��J���J��Ƥ��e: ";
					cin >> value;
					list.insert_node(value);
					break;
				case 'd':
					//cout << "��J�R����Ƥ��e: ";
					cin >> value;
					list.Delete(value);
				break;
				case 'f':
					//cout << "��J�M���Ƥ��e: ";
					cin >> value;
					list.Search(value);
					break;
				case 'l':
					list.Inorder();cout<<endl;
					break;
				case 'n':
					list.Postorder();cout<<endl;
					break;
				case 'm':
					list.Preorder();cout<<endl;
					break;
				case 'q':
					exit(0);
				default:
					cout << "��J�ȿ��~!" << endl; 
			}
		}
}

int main(){
	
	int sel;
    cin >> sel;
    switch(sel)
    {
        case 1://int
            cout <<"<Integer BST>" << endl;
            uselist(1);           
 
        break;
        case 2://double
            cout <<"<Double BST>" << endl;   
            uselist(1.1);
 
        break;
        case 3://char
            cout <<"<Char BST>" << endl;
            uselist('A');           
 
        break;
        case 4://string
            string s;
            cout <<"<String BST>" << endl;
            uselist(s);           
 
        break;
    }
	return 0;
}
