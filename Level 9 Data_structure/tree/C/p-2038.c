#include<stdio.h>
#include<stdlib.h>


struct binary_tree_node
{
int data;
struct binary_tree_node *left;
struct binary_tree_node *right;
};
typedef struct binary_tree_node node;

node *insert_node(node *root, int value);
void print_Inorder(node *root);
void print_preorder(node *ptr);
void print_postorder(node *ptr);
node *Binsearch(node *root,int n);
node *findparent(node *root,int value); //�^�Ǥ��I��m 
void  *deletenode(node *root,int value);

int main(){
	node *root,*ptr;
	int n;
	char a;
	root=NULL;
	while(1){
		scanf(" %c",&a);
		switch(a){
			case 'i':{
				scanf("%d",&n);
				root=insert_node(root,n);
				break;
			}
			
			case 'l':{
					print_Inorder(root); 
					puts("");
				break;
			}
			
			case 'm':{
					print_preorder(root);
					puts("");
				break;
			}
			
			case 'n':{
					print_postorder(root);
					puts("");
				
				break;
			}
			case 'd':{
					scanf("%d",&n);
					deletenode(root,n);	
					break;	
			}
			
				case 'f':{
					scanf("%d",&n);
					ptr=Binsearch(root,n);
					if(ptr!=NULL)
						printf("found: %d\n",ptr->data);
					if(ptr==NULL)
						printf("not found");

				break;
			}
			case 'q':{
				return 0;
			}	
		}
		
	}
}

node *insert_node(node *root, int value)
{
	node *new_node;
	node *current;
	node *parent;
	new_node = (node *)malloc(sizeof(node));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if(root == NULL)
		{root = new_node;} //return new_node;
	else
		{
			current = root;
			while(current != NULL)
			{
				parent = current;
				if(current->data > value)
					current = current->left;
				else
					current = current->right;
			}
			if(parent->data > value)
				parent->left = new_node;
			else
				parent->right = new_node;
		}
	return root;
}

void print_Inorder(node *ptr){
	if(ptr!=NULL){
		print_Inorder(ptr->left);
		printf("%d ",ptr->data);
		print_Inorder(ptr->right);
	}
}

void print_preorder(node *ptr){
	if(ptr!=NULL){
		printf("%d ",ptr->data);		
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}
}


void print_postorder(node *ptr){
	if(ptr!=NULL){
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		printf("%d ",ptr->data);	
	}
}

node *Binsearch(node *root,int n){ //�G���j�M��g�k 
	
	if(root!=NULL){
		if(root->data==n){
			//printf("found %d",root->data);
			return root;
		}
		if(n<root->data){
			//printf("������䤤...\n");
			root=Binsearch(root->left,n);
			
		}
		else if(n>root->data){
			//printf("���k��䤤...\n");
			root=Binsearch(root->right,n);
		}
	}
	return root;
}


node *findparent(node *ptr,int value){ //�qptr�}�l��Y�Ȫ����I 
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


void *deletenode(node *root,int value){
	
	node *ptr,*parent,*next;
	
	ptr=Binsearch(root,value); //ptr���V�R���I��m 
if(ptr==NULL) printf("cannot delete\n");
else{
	if(ptr->data==value&&ptr->left==NULL){ //case 1 �S�����l�� 
		if(ptr==root){root=root->right;printf("delete %d ok\n",ptr->data);free(ptr);} //�R���I��root case1.1
		else {
			parent=findparent(root,value);//���X���I��m 
				if(ptr==parent->left){ //�R���I�����I���� case 1.2 
					parent->left=ptr->right;
					printf("delete %d ok\n",ptr->data);
					free(ptr);
				}
				else if(ptr==parent->right){ //�R���I�����I�k�� case 1.3
					parent->right=ptr->right;
					printf("delete %d ok\n",ptr->data);
					free(ptr);
				}
		}
		
	}
	
	else if(ptr->data==value&&ptr->right==NULL){ //case 2 �S���k�l�� 
		if(ptr==root){root=root->left;printf("delete %d ok\n",ptr->data);free(ptr);} //�R���I��root case2.1
		else {
			parent=findparent(root,value);//���X���I��m 
				if(ptr==parent->left){ //�R���I�����I���� case 2.2 
					parent->left=ptr->left;
					printf("delete %d ok\n",ptr->data);
					free(ptr);
				}
				else if(ptr==parent->right){ //�R���I�����I�k�� case 2.3 
					parent->right=ptr->left;
					printf("delete %d ok\n",ptr->data);
					free(ptr);
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
			parent->right=next->left;
			}
			else{
				ptr->left=next->left;
			}
		printf("delete %d ok\n",ptr->data);
		ptr->data=next->data;	
		free(next);
	}
}
}

