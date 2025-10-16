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

int main(){
	node *root;
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

