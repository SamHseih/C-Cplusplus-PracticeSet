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
node *findparent(node *root,int value); //回傳父點位置 
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


node *findparent(node *ptr,int value){ //從ptr開始找某值的父點 
	node *parent;

		parent=NULL;
	while(ptr!=NULL){
		
	if(ptr->data==value){
		return parent;
		}
		parent=ptr;
	if(ptr->data>value){ //往左走尋找

		ptr=ptr->left;
		} 
	else if(ptr->data<value) { //往右尋找

		ptr=ptr->right;
		}	
	}
	return NULL;
}


void *deletenode(node *root,int value){
	
	node *ptr,*parent,*next;
	
	ptr=Binsearch(root,value); //ptr指向刪除點位置 
if(ptr==NULL) printf("cannot delete\n");
else{
	if(ptr->data==value&&ptr->left==NULL){ //case 1 沒有左子樹 
		if(ptr==root){root=root->right;printf("delete %d ok\n",ptr->data);free(ptr);} //刪除點為root case1.1
		else {
			parent=findparent(root,value);//指出父點位置 
				if(ptr==parent->left){ //刪除點位於父點左邊 case 1.2 
					parent->left=ptr->right;
					printf("delete %d ok\n",ptr->data);
					free(ptr);
				}
				else if(ptr==parent->right){ //刪除點位於父點右邊 case 1.3
					parent->right=ptr->right;
					printf("delete %d ok\n",ptr->data);
					free(ptr);
				}
		}
		
	}
	
	else if(ptr->data==value&&ptr->right==NULL){ //case 2 沒有右子樹 
		if(ptr==root){root=root->left;printf("delete %d ok\n",ptr->data);free(ptr);} //刪除點為root case2.1
		else {
			parent=findparent(root,value);//指出父點位置 
				if(ptr==parent->left){ //刪除點位於父點左邊 case 2.2 
					parent->left=ptr->left;
					printf("delete %d ok\n",ptr->data);
					free(ptr);
				}
				else if(ptr==parent->right){ //刪除點位於父點右邊 case 2.3 
					parent->right=ptr->left;
					printf("delete %d ok\n",ptr->data);
					free(ptr);
				}
		}
		
	}
	else {  //有左子樹也有右子樹  //運用左子樹最大代替 
		
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

