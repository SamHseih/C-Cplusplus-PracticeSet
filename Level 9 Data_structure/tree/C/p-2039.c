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
	//Level 1
	root=(node*)malloc(sizeof(node));
	root->data=5; 
	
	//Level 2
	root->left=(node*)malloc(sizeof(node));
	root->left->data=4;//ⅹ쨖언
	root->left->left=NULL;
	root->left->right=NULL;
	
	root->right=(node*)malloc(sizeof(node));
	root->right->data=6;//쩵쨖언
	root->right->left=NULL;
	root->right->right=NULL;

	//Level 3
	root->left->left=(node*)malloc(sizeof(node));
	root->left->left->data=2; //ⅹ쨖언 
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	
	root->right->right=malloc(sizeof(node));
	root->right->right->data=8;//쩵쨖언
	root->right->right->left=NULL;
	root->right->right->right=NULL;
	
	//Level 4
	root->left->left->left=(node*)malloc(sizeof(node));
	root->left->left->left->data=1; //ⅹ쨖
	root->left->left->left->left=NULL;
	root->left->left->left->right=NULL;
	
	root->left->left->right=(node*)malloc(sizeof(node));
	root->left->left->right->data=3; //쩵쨖 
	root->left->left->right->left=NULL;
	root->left->left->right->right=NULL;
	
	root->right->right->left=malloc(sizeof(node));
	root->right->right->left->data=7;
	root->right->right->left->left=NULL;
	root->right->right->left->right=NULL;	
	
	root->right->right->right=malloc(sizeof(node));
	root->right->right->right->data=9;
	root->right->right->right->left=NULL;
	root->right->right->right->right=NULL;
					
	//puts("This is Preorder traversal");
	print_preorder(root);  // 첿㎸: 5,4,2,1,3,6,8,7,9
		puts("");
	//puts("\nThis is Inorder traversal");
	print_Inorder(root);  // ㄴ㎸: 1,2,3,4,5,6,7,8,9 
		puts("");
	//puts("\nThis is postorder traversal");
	print_postorder(root); // メ㎸: 1,3,2,4,7,9,8,6,5
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

