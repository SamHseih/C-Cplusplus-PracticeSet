#include<stdio.h>
#include<stdlib.h>


struct binary_tree_node
{
int data;
struct binary_tree_node *left;
struct binary_tree_node *right;
};
typedef struct binary_tree_node node;

node *Insertnode(node *ptr,int input);
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
				root=Insertnode(root,n);
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

node *Insertnode(node *root,int input){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->data=input;
		root->left=NULL;
		root->right=NULL;	
	}
	else{
		if(root->data<input){
			root->right=Insertnode(root->right,input);
		}
		else if(root->data>input){
			root->left=Insertnode(root->left,input);
		}
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

