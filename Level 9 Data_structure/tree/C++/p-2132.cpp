#include<iostream>
#include<cstdlib>   // �ݭn�Ψ�exit�����Y��
using namespace std;
class Binarytree_node{ //node �w�q 
	friend class Binarytree;
	private:
		int data;
		Binarytree_node *left;
		Binarytree_node *right;
};
typedef Binarytree_node node;
class Binarytree{  //�G����class
	
	public:
	Binarytree();
	void insert_node(int value);
	void Inorder();
	void Preorder();
	void Postorder();
	void Search(int value);
	void Deleranode(int value);
	
	private:
	node *root;
	node *Binsearch(node *ptr,int n);
	void print_Inorder(node *ptr);
	void print_preorder(node *ptr);
	void print_postorder(node *ptr);
	node *findparent(node *ptr,int value);
	void *deletenode(node *root,int value);
};
Binarytree::Binarytree(){ //��l�ƫغc�� 
	root=NULL;
}
void Binarytree::insert_node(int value){ //���J�禡 
	node *new_node;
	node *current;
	node *parent;
	new_node=new node;
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
void Binarytree::Inorder(){  //���ǦC�L�]�� 
	print_Inorder(root);
}
void Binarytree::Preorder(){ //�e�ǦC�L�]�� 
	print_preorder(root);
}
void Binarytree::Postorder(){ //��ǦC�L�]�� 
	print_postorder(root);
}
void Binarytree::Search(int value){ //�j�M�]�� 

	if(Binsearch(root,value)==NULL)
		cout<<"not found"<<endl;
		else 	cout<<"found: "<<value<<endl;
}
void Binarytree::Deleranode(int value){  //�R���]�� 
	deletenode(root,value);
}
void Binarytree::print_Inorder(node *ptr){   //���ǦC�L�禡 
	if(ptr!=NULL){
		print_Inorder(ptr->left);
		cout<<ptr->data<<" ";//printf("%d ",ptr->data);
		print_Inorder(ptr->right);
	}
}
void Binarytree::print_preorder(node *ptr){ //�e�ǦC�L�禡 
	if(ptr!=NULL){
		cout<<ptr->data<<" ";//printf("%d ",ptr->data);		
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}
}
void Binarytree::print_postorder(node *ptr){ //��ǦC�L�禡 
	if(ptr!=NULL){
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		cout<<ptr->data<<" "; //printf("%d ",ptr->data);	
	}
}
node *Binarytree::Binsearch(node *ptr,int n){  //�G���j�M�禡 
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
node *Binarytree::findparent(node *ptr,int value){  //�qptr�}�l��Y�� �����I�禡 
	node *parent;

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
void *Binarytree::deletenode(node *root,int value){ //�R���`�I�禡 
	
	node *ptr,*parent,*next;
	
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
int main(){
	
	int i,value;
	char c;
	Binarytree b;
	while(1){
		cin>>c;
		switch(c){
			case 'i':{
				cin>>value;
				b.insert_node(value);
				//cout<<"���}��"<<i<<"���J"<<endl; 
				break;
			}
			case 'l':{
				//cout<<"In-order:"<<endl;
				b.Inorder();cout<<endl;
				break;
			}
			case 'm':{
				//cout<<"Pre-order:"<<endl;
				b.Preorder();cout<<endl;
				break;
			}
			case 'n':{
				//cout<<"Post-order:"<<endl;
				b.Postorder();cout<<endl;
				break;
			}
			case 'd':{
				cin>>value;
				b.Deleranode(value);
				break;
			}
			case 'f':{
				cin>>value;
				b.Search(value);
				break;
			}
			case 'q':{
				exit(0);
				break;
			}
		}
	}
	return 0;
}
