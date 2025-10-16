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
node *freenode(node *root);
node *Binsearch(node *root,int n);
node *find_max(node *root);
node *find_min(node *root);
int main(){
	
	node *root,*max,*min;
	int n;
	char a;
	root=NULL;
	
	while(1){
		//printf("i 新增 l中序 m前序 n後序  d刪除全節點 q離開\n");
		scanf(" %c",&a);
		switch(a){
			case 'i':{
				scanf("%d",&n);
				root=Insertnode(root,n);
				break;
			}
			
			case 'l':{
					/*if(root==NULL){
					puts("請新增data");
					break;
					}*/
					//printf("print_Inorder :");
					print_Inorder(root); puts("");
				break;
			}
			
			case 'm':{
					/*if(root==NULL){
					puts("請新增data");
					break;
					}*/
					//printf("print_preorder :");
					print_preorder(root);puts("");
				break;
			}
			
			case 'n':{
					/*if(root==NULL){
					puts("請新增data");
					break;
					}*/
					//printf("print_postorder :");
					print_postorder(root);puts("");
				
				break;
			}
			
			case 'd':{
					node *ptr;
					ptr=root;
					printf("輸入刪除數字 :\n");
					scanf("%d",&n);
					ptr=Binsearch(root,n);
					if(ptr==NULL)
						printf("cannot delete");
					else
						ptr=freenode(ptr);
					
			}
			
			case 'f':{
					node *ptr;
					ptr=root;
					
					ptr=find_max(ptr);
					printf("最大值: %d",ptr->data);
					ptr=root;
					ptr=find_min(ptr);
					printf("最小值: %d",ptr->data);
					
					ptr=root;
					printf("輸入尋找數字 :\n");
					scanf("%d",&n);
					ptr=Binsearch(root,n);
					if(ptr!=NULL)
						printf("%d\n",ptr->data);
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

node *Binsearch(node *root,int n){ //二元搜尋樹寫法 
	
	if(root!=NULL){
		if(root->data==n){
			//printf("found %d",root->data);
			return root;
		}
		if(n<root->data){
			//printf("往左邊找中...\n");
			root=Binsearch(root->left,n);
			
		}
		else if(n>root->data){
			//printf("往右邊找中...\n");
			root=Binsearch(root->right,n);
		}
	}
	return root;
}

node *freenode(node *root){ //此刪除為刪除所有節點 
	node *ptr;
	ptr=root;
	if(root!=NULL){
		if(root->left!=NULL){
			root->left=freenode(root->left);
		}
		if(root->right!=NULL){
			root->right=freenode(root->right);
		}
		free(root);
	}
	return NULL;
}

node *find_max(node *root){
	node *max;
	while(root!=NULL){
		if(root->right!=NULL){
			root=root->right;
		}
	}
	retrun root;
}

node *find_min(node *root){
	node *min;
	while(root->right!=NULL){
			root=root->right;
	}
	retrun root;
	
}
