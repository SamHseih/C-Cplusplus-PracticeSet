#include<stdio.h>
#include<stdlib.h>


struct binary_tree_node
{
int data;
struct binary_tree_node *left;
struct binary_tree_node *right;
};
typedef struct binary_tree_node node;

void print_preorder(node *ptr);
void print_Inorder(node *ptr);
void print_postorder(node *ptr);


int main(){
	int n;
	node *ptr;
	node *root;
	root=(node*)malloc(sizeof(node));
	root->data=5; //root
	root->left=(node*)malloc(sizeof(node));
		root->left->data=4;//左子樹
		root->left->left=NULL; 
		root->left->right=NULL;
	root->right=(node*)malloc(sizeof(node));
		root->right->data=6;//右子樹 
		root->right->left=NULL;
		root->right->right=NULL;
		
	print_preorder(root);  // 前序: 5,4,6
	puts("");
	print_Inorder(root);  // 中序: 4,5,6
	puts("");
	print_postorder(root); // 後序: 4,6,5
}


void print_preorder(node *ptr){
	if(ptr!=NULL){
		printf("%d ",ptr->data);		
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}
}

void print_Inorder(node *ptr){
	if(ptr!=NULL){
		print_Inorder(ptr->left);
		printf("%d ",ptr->data);
		print_Inorder(ptr->right);
	}
}

void print_postorder(node *ptr){
	if(ptr!=NULL){
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		printf("%d ",ptr->data);	
	}
}

