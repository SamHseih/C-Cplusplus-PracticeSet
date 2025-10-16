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
node *findparent(node *root,int value); //回傳父點位置 
void print_Inorder(node *root);
void print_preorder(node *ptr);
void print_postorder(node *ptr);
node *Binsearch(node *root,int n);
void  *deletenode(node *root,int value);

int main(){ //
	
	int k=13;
	int a[13]={10,7,4,8,20,15,31,6,11,17,29,28,27};
	node *root,*parent,*ptr;
	int i,n=0;
	root=NULL;
	for(i=0;i<k;i++){root=Insertnode(root,a[i]);}
	printf("print_Inorder :");
	print_Inorder(root); puts("");
	printf("print_preorder :");
	print_preorder(root);puts("");
	
	scanf("%d",&n);
	deletenode(root,n);
	
	
	printf("print_Inorder :");
	print_Inorder(root); puts("");
	printf("print_preorder :");
	print_preorder(root);puts("");
	
	{ //驗證程式碼群  
	/*scanf("%d",&n);
	puts("");
ptr=Binsearch(root,n);
					if(ptr!=NULL)
						printf("found %d\n",ptr->data);
					if(ptr==NULL)
						printf("not found");*/ //驗證Binsearchtree程式碼 
	
	/*puts("尋找父點");
	scanf("%d",&n);
	parent=findparent(root,n,&pos);
	
	if(parent!=NULL){
		printf("parent's data is %d\n",parent->data);
	}
	else 
		{printf("Can not find parent\n");}*/ //驗證父點程式碼
		
	/*printf("print_Inorder :");
	print_Inorder(root); puts("");
	printf("print_preorder :");
	print_preorder(root);puts("");
	printf("print_postorder :");
	print_postorder(root);puts("");*/ //驗證是否成功建立 tree
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

node *findparent(node *ptr,int value){ //從ptr開始找某值 
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

void *deletenode(node *root,int value){
	
	node *ptr,*parent,*next;
	
	ptr=Binsearch(root,value); //ptr指向刪除點位置 
if(ptr==NULL) printf("cannot delete\n");
else{
	if(ptr->data==value&&ptr->left==NULL){ //case 1 沒有左子樹 
		if(ptr==root){root=root->right;printf("delete %d ok",ptr->data);free(ptr);} //刪除點為root case1.1
		else {
			parent=findparent(root,value);//指出父點位置 
				if(ptr==parent->left){ //刪除點位於父點左邊 case 1.2 
					parent->left=ptr->right;
					printf("delete %d ok",ptr->data);
					free(ptr);
				}
				else if(ptr==parent->right){ //刪除點位於父點右邊 case 1.3
					parent->right=ptr->right;
					printf("delete %d ok",ptr->data);
					free(ptr);
				}
		}
		
	}
	
	else if(ptr->data==value&&ptr->right==NULL){ //case 2 沒有右子樹 
		if(ptr==root){root=root->left;printf("delete %d ok",ptr->data);free(ptr);} //刪除點為root case2.1
		else {
			parent=findparent(root,value);//指出父點位置 
				if(ptr==parent->left){ //刪除點位於父點左邊 case 2.2 
					parent->left=ptr->left;
					printf("delete %d ok",ptr->data);
					free(ptr);
				}
				else if(ptr==parent->right){ //刪除點位於父點右邊 case 2.3 
					parent->right=ptr->left;
					printf("delete %d ok",ptr->data);
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
			parent->right=next->right;
			}
			else{
				ptr->left=next->left;
			}
		printf("delete %d ok",ptr->data);
		ptr->data=next->data;	
		free(next);
	}
}
}

