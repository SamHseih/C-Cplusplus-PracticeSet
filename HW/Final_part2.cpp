#include<iostream>
#include<cstdlib>   // �ݭn�Ψ�exit�����Y��
#include<stdlib.h>
#include<string.h>
using namespace std;
class Binarytree_node { //node �w�q
		friend class Binarytree;
	private:
		char phonenumber[15];
		char name[128];
		int mark;
		Binarytree_node *left;
		Binarytree_node *right;
};
typedef Binarytree_node node;
class Binarytree { //�G����class

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
Binarytree::Binarytree() { //��l�ƫغc��
	root=NULL;
	mark=0;
}
void Binarytree::Inorder() { //���ǦC�L�]��
	print_Inorder(root);

}
void Binarytree::Preorder() { //�e�ǦC�L�]��
	print_preorder(root);
}
void Binarytree::Postorder() { //��ǦC�L�]��
	print_postorder(root);
}
void Binarytree::Insert(char Name[128],char number[15]) {   //���J�禡�]��
	node new_node;
	strcpy(new_node.phonenumber,number);
	strcpy(new_node.name,Name);
	mark ++;
	new_node.mark=mark;
	root=insert_node(root,new_node);
}
void Binarytree::Search_name(char n[128]) { //�j�M�W�r�]��
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
void Binarytree::Search_mark(int n) { //�j�M�s���]��
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
void Binarytree::parent_name(char p[128]) { //�M��W�r�����I�]��
	node *ptr;
	int pos=0;
	ptr=findparent_name(root,p,&pos);
	if(ptr==NULL)cout<<"no parents"<<endl;
	else {
		cout<<"Parent Name :"<<ptr->name<<endl;
		cout<<"Pos :"<<pos<<endl;
	}
}
void Binarytree::parent_mark(int n) { //�M��s�������I�]��
	node *ptr;
	ptr=findparent_mark(root,root,n);
	if(ptr==NULL)cout<<"no parents"<<endl;
	else {
		cout<<"Parent Mark :"<<ptr->mark<<endl;
	}
}
void Binarytree::delete_name(char a[128]) { //�R���W�r�`�I�]��
	deletenode_name(root,a);
}
void Binarytree::delete_mark(int n) { //�R���s���`�I�]��
	deletenode_mark(root,n);
}
void Binarytree::print_Inorder(node *ptr) {  //���ǦC�L�禡
	if(ptr!=NULL) {
		print_Inorder(ptr->left);
		cout<<"Name :"<<ptr->name<<endl;
		cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
		cout<<"Mark :"<<ptr->mark<<endl<<endl;
		print_Inorder(ptr->right);
	}
}
void Binarytree::print_preorder(node *ptr) { //�e�ǦC�L�禡
	if(ptr!=NULL) {
		cout<<"Name :"<<ptr->name<<endl;
		cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
		cout<<"Mark :"<<ptr->mark<<endl<<endl;
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}
}
void Binarytree::print_postorder(node *ptr) { //��ǦC�L�禡
	if(ptr!=NULL) {
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		cout<<"Name :"<<ptr->name<<endl;
		cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
		cout<<"Mark :"<<ptr->mark<<endl<<endl;
	}
}
node *Binarytree::insert_node(node *root,node data) { //���J�禡
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
node *Binarytree::Binsearch_name(node *ptr,char n[128]) { //�G���j�M�W�r�禡
	if(ptr!=NULL) {
		if(strcmp(ptr->name,n)==0) { //root->name==n
			//printf("found %d",root->data);
			return ptr;
		}
		if(strcmp(ptr->name,n)>0) { //n<root->data
			//printf("������䤤...\n");
			ptr=Binsearch_name(ptr->left,n);

		} else if(strcmp(ptr->name,n)<0) { //n>root->data
			//printf("���k��䤤...\n");
			ptr=Binsearch_name(ptr->right,n);
		}
	} else {
		return NULL;
	}

}
node *Binarytree::PreorderSearch_mark(node *ptr,int value) { //�e�ǴM����Ҩ禡
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
node *Binarytree::findparent_name(node *ptr,char name[128],int *pos) { //�M��W�r�����I�禡


	node *parent;
	parent = ptr;	// �qptr�}�l��
	*pos = 0;
	while(ptr!=NULL) {
		if(strcmp(ptr->name,name)==0)	// ���ؼ� //ptr->data == value
			return parent;		// �^�Ǧ��`�I�����`�I
		else {
			parent = ptr;
			if(strcmp(ptr->name,name)>0) { //ptr->data > value
				*pos = -1;			// ptr�bparent���l��
				ptr = ptr->left;	// ������
			} else {
				*pos = 1;			// ptr�bparent�k�l��
				ptr = ptr->right;	// ���k��
			}
		}
	}
	return NULL;	// �䤣��
}
node *Binarytree::findparent_mark(node *ptr,node *parent,int value) { // �M��s�������I�禡
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
void Binarytree::deletenode_name(node *root, char name[128]) { //�R���W�r�`�I�禡 
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = findparent_name(root, name, &pos);	// �qroot�}�l,��value�����`�I
	if(parent != NULL) {	// �����, �ǳƧR��
		switch(pos) {	// �P�_�ثe�`�I�A���`�I����Υk��
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
		if(ptr->left == NULL) {	// ���p1: �`�I�S�����l�� �p�G�n�R���O�ڸ`�I
			if(parent == ptr)	// �p�G�n�R���O�ڸ`�I
				root = root->right;
			else {			// ��L
				if( pos == 1 ) {
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I���k�`�I
					parent->right = ptr->right;
				} else {
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I���k�`�I
					parent->left = ptr->right;
				}
			}
			
			cout<<"Name :"<<ptr->name<<endl;
			cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
			cout<<"Mark :"<<ptr->mark<<endl<<endl;
			cout<<"delete "<<ptr->name<<" OK"<<endl;
			delete ptr;
		} else if(ptr->right == NULL) {	// ���p2: �`�I�S���k�l��
			if(parent != ptr) {
				if( pos == 1 ) {
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I�����`�I
					parent->right = ptr->left;
				} else {
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I�����`�I
					parent->left = ptr->left;
				}
			} else
				root = root->left;
			cout<<"Name :"<<ptr->name<<endl;
			cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
			cout<<"Mark :"<<ptr->mark<<endl<<endl;
			cout<<"delete "<<ptr->name<<" OK"<<endl;
			delete ptr;
		} else {					// ���p3: �`�I�����k�l��
			parent = ptr;
			next = ptr->left;	// ����N�Inext, �qptr����}�l��
			if(next->right!=NULL) {
				while(next->right != NULL) {	// �����l�`�I���k�l���̤j�ȷ���N�I
					parent = next;		// parent��next�����`�I
					next = next->right;
				}
				parent->right = next->left; // ¶�Lnext�`�I
			} else {
				ptr->left=next->left;
			}
			cout<<"Name :"<<ptr->name<<endl;
			cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
			cout<<"Mark :"<<ptr->mark<<endl<<endl;
			cout<<"delete "<<ptr->name<<" OK"<<endl;
			strcpy(ptr->name,next->name);//ptr->data = next->data;		// ���N!!
			strcpy(ptr->phonenumber,next->phonenumber);
			ptr->mark=next->mark;
			delete next;// �R��next (�`�N: ���O�R��ptr)
		}
	} else {
		cout<<"cannot delete"<<endl;
	}
}
void Binarytree::deletenode_mark(node *root,int value) { //�R���s���`�I�禡

	node *ptr,*parent,*next;
	ptr=PreorderSearch_mark(root,value); //ptr���V�R���I��m
	if(ptr==NULL)printf("cannot delete\n");
	else {
		if(ptr->mark==value&&ptr->left==NULL) { //case 1 �S�����l��
			if(ptr==root) {
				root=root->right;  
					cout<<"Name :"<<ptr->name<<endl;
					cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
					cout<<"Mark :"<<ptr->mark<<endl<<endl;
					cout<<"delete "<<ptr->mark<<" OK"<<endl; 
					delete ptr;   //�R���I��root case1.1
			} else {
				parent=findparent_mark(root,root,value);//���X���I��m
				if(ptr==parent->left) { //�R���I�����I���� case 1.2
					cout<<"Name :"<<ptr->name<<endl;
					cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
					cout<<"Mark :"<<ptr->mark<<endl<<endl;
					cout<<"delete "<<ptr->mark<<" OK"<<endl;
					delete ptr;
				} else if(ptr==parent->right) { //�R���I�����I�k�� case 1.3
					parent->right=ptr->right;
					cout<<"Name :"<<ptr->name<<endl;
					cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
					cout<<"Mark :"<<ptr->mark<<endl<<endl;
					cout<<"delete "<<ptr->mark<<" OK"<<endl;
					delete ptr;
				}
			}

		}

		else if(ptr->mark==value&&ptr->right==NULL) { //case 2 �S���k�l��
			if(ptr==root) {
				root=root->left; 
				
				cout<<ptr->mark<<" "<<endl; 
				cout<<"Name :"<<ptr->name<<endl;
				cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
				cout<<"Mark :"<<ptr->mark<<endl<<endl;
				cout<<"delete "<<ptr->mark<<" OK"<<endl;
				delete ptr;   //�R���I��root case2.1
			} else {
				parent=findparent_mark(root,root,value);//���X���I��m
				if(ptr==parent->left) { //�R���I�����I���� case 2.2
					parent->left=ptr->left;
				cout<<"Name :"<<ptr->name<<endl;
				cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
				cout<<"Mark :"<<ptr->mark<<endl<<endl;
				cout<<"delete "<<ptr->mark<<" OK"<<endl;
					delete ptr;
				} else if(ptr==parent->right) { //�R���I�����I�k�� case 2.3
					parent->right=ptr->left;
				cout<<"Name :"<<ptr->name<<endl;
				cout<<"Phonenumber :"<<ptr->phonenumber<<endl;
				cout<<"Mark :"<<ptr->mark<<endl<<endl;
				cout<<"delete "<<ptr->mark<<" OK"<<endl;
					delete ptr;
				}
			}

		} else { //�����l��]���k�l��  //�B�Υ��l��̤j�N��

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
		cout<<"i �s�W d�R��(�W�r) r�R��(�s��) f�j�M(�m�W) l�e/��/��C�L q���}"<<endl;
		cin>>a;
		switch(a) {
			case 'i': {  //�s�W�`�I,�i��J�m�W, �q��,�æ۰ʥ[�J�s���̾کm�W�r�����Ǵ��J�`�I(���]��J���m�W���|����)
				char Name[128],number[15];	
				cout<<"�п�J�m�W,�q��:"<<endl;
				cin>>Name>>number;
				b.Insert(Name,number);
				cout<<"���J����..."<<endl;
				break;
			}
			case 'd': {
				char d[128];
				cout<<"�п�J�ݧR�����m�W:"<<endl;
				cin>>d;
				b.delete_name(d);
				break;
			}
			case 'r': {
				cout<<"�п�J�ݧR�����s��:"<<endl;
				int n;
				cin>>n;
				b.delete_mark(n);
				break;
			}
			case 'f': {
				cout<<"�п�J�M�䪺�m�W:"<<endl;
				char n[128];
				cin>>n;
				b.Search_name(n);
				break;
			}
			case 'l': { //�i�̾کm�W�r�����ǡB�e/��/��ǦL�X�Ҧ��`�I���e
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
