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
node *Binsearch(node *ptr,int n);

void freetree(node *ptr);

int main(){
	int n;
	node *ptr;
	node *root;
	root=(node*)malloc(sizeof(node));
	root->data=10; //root
	root->left=(node*)malloc(sizeof(node));
		root->left->data=7;//左子樹 
		root->left->left=(node*)malloc(sizeof(node));
			root->left->left->data=3; //左子樹 
			root->left->left->left=(node*)malloc(sizeof(node));
				root->left->left->left->data=0; //左子 
				root->left->left->left->left=NULL;
				root->left->left->left->right=NULL;
			root->left->left->right=(node*)malloc(sizeof(node));
				root->left->left->right->data=5; //右子 
				root->left->left->right->left=NULL;
				root->left->left->right->right=NULL;
		root->left->right=NULL;
	root->right=(node*)malloc(sizeof(node));
		root->right->data=15;//右子樹 
		root->right->left=NULL;
		root->right->right=malloc(sizeof(node));
				root->right->right->data=20;//右子樹 
				root->right->right->left=malloc(sizeof(node));
					root->right->right->left->data=17;
					root->right->right->left->left=NULL;
					root->right->right->left->right=NULL;	
				root->right->right->right=malloc(sizeof(node));
					root->right->right->right->data=25;
					root->right->right->right->left=NULL;
					root->right->right->right->right=NULL;
	puts("This is Preorder traversal");
	print_preorder(root);  // 前序: 5,4,2,1,3,6,8,7,9
	puts("\nThis is Inorder traversal");
	print_Inorder(root);  // 中序: 1,2,3,4,5,6,7,8,9 
	puts("\nThis is postorder traversal");
	print_postorder(root); // 後序: 1,3,2,4,7,9,8,6,5
	
	puts("\n輸入尋找數字 : 0~30");
	scanf("%d",&n);
	ptr=Binsearch(root,n);
	
	if(ptr!=NULL)printf("\n123 %d\n",ptr->data);
	
	if(ptr==NULL){
		printf("not found");
		
	}
	
	return 0;
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

node *Binsearch(node *ptr,int n){ //二元搜尋樹寫法 
	
	if(ptr!=NULL){
		if(ptr->data==n){
			printf("found %d",ptr->data);
			return ptr;
		}
		if(n<ptr->data){
			printf("往左邊找中...\n");
			Binsearch(ptr->left,n);
		}
		else if(n>ptr->data){
			printf("往右邊找中...\n");
			Binsearch(ptr->right,n);
		}
	}
	return NULL;
}

void freetree(node *ptr){
	if(ptr!=NULL){
		if(ptr->left!=NULL){
			freetree(ptr->left);
		}
		if(ptr->right!=NULL){
			freetree(ptr->right);
		}
		free(ptr);	
		
	}
}
