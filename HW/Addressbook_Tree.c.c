#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct binary_tree_node
{
char name[128];
int phonenumber;
struct binary_tree_node *left;
struct binary_tree_node *right;
};
typedef struct binary_tree_node node;

void print_Inorder(node *ptr);
void print_preorder(node *ptr);
void print_postorder(node *ptr);
node *insert_node(node *root,node data);
node *Binsearch(node *root,char n[128]);
node *find_parent(node *ptr,char name[128],int *pos);
node *delete_node(node *root, char name[128]);


// i ocass 098855221 i gay 55667788 i apple 2233665577 i sex 8899774455 i people 569874511 i veho 09221155447 i hello 2233554488
int main(){
	
	node *root,*ptr,*parent;
	root=NULL;
	node newdata;
	int pos;
	char a;
	char name[128];
	while(1){
		//printf("i 新增 l中序  d刪除節點 f尋找 q離開\n");
		scanf(" %c",&a);
		switch(a){
			case 'i':{
				scanf("%s",&newdata.name);
				scanf("%d",&newdata.phonenumber);
				root=insert_node(root,newdata);
				break;
			}
			
			case 'l':{print_Inorder(root);break;}
			case 'm':{print_preorder(root);break;}		
			case 'n':{print_postorder(root);break;}
			
			case 'd':{
					scanf("%s",&newdata.name);
					root=delete_node(root, newdata.name);
				break;					
			}
			
			case 'f':{
					{/*puts("尋找父點");  //父點驗證程式碼 
					scanf("%s",name);
					parent=find_parent(root,name,&pos);
					
					if(parent!=NULL){
						printf("parent's name is %s\npos= %d",parent->name,pos);
					}
					else 
						printf("Can not find parent\n");*/ 
					} 
					scanf("%s",&newdata.name);	
					ptr=Binsearch(root,newdata.name);
					if(ptr!=NULL){
						printf("found:\n");
						printf("Name: %s\n",ptr->name);
						printf("Phone: %d\n\n",ptr->phonenumber);}
					if(ptr==NULL)
						printf("not found\n");
				break;
			}
			case 'q':{
				return 0;
			}	
		}
	}
}


void print_Inorder(node *ptr){
	if(ptr!=NULL){
		print_Inorder(ptr->left);
		printf("Name: %s\n",ptr->name);
		printf("Phone: %d\n",ptr->phonenumber);puts("");
		print_Inorder(ptr->right);
	}
}

void print_preorder(node *ptr){
	if(ptr!=NULL){
		printf("Name: %s\n",ptr->name);
		printf("Phone: %d\n",ptr->phonenumber);puts("");
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}
}

void print_postorder(node *ptr){
	if(ptr!=NULL){
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		printf("Name: %s\n",ptr->name);
		printf("Phone: %d\n",ptr->phonenumber);puts("");
	}
}


node *insert_node(node *root,node data){
	node *new_node;
	node *current;
	node *parent;
	new_node = (node *)malloc(sizeof(node));
	*new_node=data;
	new_node->left=NULL;
	new_node->right=NULL;
	if(root == NULL)
		{root=new_node;} //return new_node;
	else
		{
			current = root;
			while(current != NULL)
			{
				parent = current;
				if(strcmp(current->name,new_node->name)>0)   //current->data > value
					current = current->left; 
				else
					current = current->right; 
			}
			if(strcmp(parent->name,new_node->name)>0)
				parent->left = new_node;
			else
				parent->right = new_node;
		}
	return root;
}

node *Binsearch(node *root,char n[128]){ //二元搜尋樹寫法 
	
	if(root!=NULL){
		if(strcmp(root->name,n)==0){ //root->name==n
			//printf("found %d",root->data);
			return root;
		}
		if(strcmp(root->name,n)>0){ //n<root->data
			//printf("往左邊找中...\n");
			root=Binsearch(root->left,n);
			
		}
		else if(strcmp(root->name,n)<0){ //n>root->data
			//printf("往右邊找中...\n");
			root=Binsearch(root->right,n);
		}
	}

	return root;
}

// 找某值之父節點
node *find_parent(node *ptr,char name[128],int *pos){

	
	node *parent;
	parent = ptr;	// 從ptr開始找
	*pos = 0;
	while(ptr!=NULL)	
	{
		if(strcmp(ptr->name,name)==0)	// 找到目標 //ptr->data == value
			return parent;		// 回傳此節點之父節點
		else
		{
			parent = ptr;
			if(strcmp(ptr->name,name)>0) //ptr->data > value
			{
				*pos = -1;			// ptr在parent左子樹
				ptr = ptr->left;	// 往左找
			}
			else
			{
				*pos = 1;			// ptr在parent右子樹
				ptr = ptr->right;	// 往右找
			}
		}
	}
	return NULL;	// 找不到
}

// 刪除節點
node *delete_node(node *root, char name[128]){
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = find_parent(root, name, &pos);	// 從root開始,找value之父節點
	if(parent != NULL)	// 有找到, 準備刪除
	{
		switch(pos)	// 判斷目前節點再父節點左邊或右邊
		{
			case -1:
				ptr = parent->left;
				break;
			case 1:
				ptr = parent->right;
				break;
			case 0:
				ptr = parent;
				break;
		}
		if(ptr->left == NULL)		// 情況1: 節點沒有左子樹 如果要刪的是根節點
		{
			if(parent == ptr)	// 如果要刪的是根節點
				root = root->right;
			else				// 其他
			{
				if( pos == 1 )
				{
					//要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的右節點
					parent->right = ptr->right;
				}
				else
				{
		 				//要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的右節點
					parent->left = ptr->right;
				}
			}
			printf("delete %s ok\n\n",ptr->name);
			free(ptr);
		}
		else if(ptr->right == NULL)	// 情況2: 節點沒有右子樹
		{
			if(parent != ptr)
			{
				if( pos == 1 )
				{
					//要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的左節點
					parent->right = ptr->left;
				}
				else
				{
					//要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的左節點
					parent->left = ptr->left;
				}
			}
			else
				root = root->left;
			printf("delete %s ok\n\n",ptr->name);
			free(ptr);
		}
		else						// 情況3: 節點有左右子樹
		{
			parent = ptr;
			next = ptr->left;	// 找取代點next, 從ptr左邊開始找
 		if(next->right!=NULL){
			while(next->right != NULL)	// 往左子節點之右子樹找最大值當取代點
			{
				parent = next;		// parent為next之父節點
				next = next->right;
			}
			parent->right = next->left; // 繞過next節點
		}
		else {
			ptr->left=next->left;
		}
		printf("delete %s ok\n\n",ptr->name);
		strcpy(ptr->name,next->name);//ptr->data = next->data;		// 取代!!
		ptr->phonenumber=next->phonenumber;
		free(next);// 刪除next (注意: 不是刪除ptr)
		}
	}
	else {printf("cannot delete");}
	
	
	return root;	// 回傳此樹
}
