#include<stdio.h>
#include<stdlib.h>


struct binary_tree_node
{
int data;
struct binary_tree_node *left;
struct binary_tree_node *right;
};
typedef struct binary_tree_node node;

node *search(node *ptr,int n);

int main(){
	int n;
	node *ptr;
	node *root;
	//Level 1
	root=(node*)malloc(sizeof(node));
	root->data=5; 
	
	//Level 2
	root->left=(node*)malloc(sizeof(node));
	root->left->data=4;//���l��
	root->left->left=NULL;
	root->left->right=NULL;
	
	root->right=(node*)malloc(sizeof(node));
	root->right->data=6;//�k�l��
	root->right->left=NULL;
	root->right->right=NULL;

	//Level 3
	root->left->left=(node*)malloc(sizeof(node));
	root->left->left->data=2; //���l�� 
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	
	root->right->right=malloc(sizeof(node));
	root->right->right->data=8;//�k�l��
	root->right->right->left=NULL;
	root->right->right->right=NULL;
	
	//Level 4
	root->left->left->left=(node*)malloc(sizeof(node));
	root->left->left->left->data=1; //���l
	root->left->left->left->left=NULL;
	root->left->left->left->right=NULL;
	
	root->left->left->right=(node*)malloc(sizeof(node));
	root->left->left->right->data=3; //�k�l 
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
					
	//puts("��J�M��Ʀr : 0~30");
	scanf("%d",&n);
	ptr=search(root,n);
	
	if(ptr!=NULL)printf("\nfound %d",ptr->data);
	if(ptr==NULL){
		printf("\nnot found");
	}
	
	return 0;
}

node *search(node *ptr,int n){
	
	node *temp;
		
	if(ptr!=NULL){
		
		if(ptr->data==n){
			printf("%d ",ptr->data);
			return ptr;
		}

		else	
		{
			printf("%d ",ptr->data);
			temp=search(ptr->left,n);
				if(temp!=NULL){
					return temp;
				}	
			temp=search(ptr->right,n);
				if(temp!=NULL){
					return temp;
				}
		}
	}
	return NULL;
}
