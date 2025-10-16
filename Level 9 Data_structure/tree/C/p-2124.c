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
		//printf("i �s�W l����  d�R���`�I f�M�� q���}\n");
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
					{/*puts("�M����I");  //���I���ҵ{���X 
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

node *Binsearch(node *root,char n[128]){ //�G���j�M��g�k 
	
	if(root!=NULL){
		if(strcmp(root->name,n)==0){ //root->name==n
			//printf("found %d",root->data);
			return root;
		}
		if(strcmp(root->name,n)>0){ //n<root->data
			//printf("������䤤...\n");
			root=Binsearch(root->left,n);
			
		}
		else if(strcmp(root->name,n)<0){ //n>root->data
			//printf("���k��䤤...\n");
			root=Binsearch(root->right,n);
		}
	}

	return root;
}

// ��Y�Ȥ����`�I
node *find_parent(node *ptr,char name[128],int *pos){

	
	node *parent;
	parent = ptr;	// �qptr�}�l��
	*pos = 0;
	while(ptr!=NULL)	
	{
		if(strcmp(ptr->name,name)==0)	// ���ؼ� //ptr->data == value
			return parent;		// �^�Ǧ��`�I�����`�I
		else
		{
			parent = ptr;
			if(strcmp(ptr->name,name)>0) //ptr->data > value
			{
				*pos = -1;			// ptr�bparent���l��
				ptr = ptr->left;	// ������
			}
			else
			{
				*pos = 1;			// ptr�bparent�k�l��
				ptr = ptr->right;	// ���k��
			}
		}
	}
	return NULL;	// �䤣��
}

// �R���`�I
node *delete_node(node *root, char name[128]){
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = find_parent(root, name, &pos);	// �qroot�}�l,��value�����`�I
	if(parent != NULL)	// �����, �ǳƧR��
	{
		switch(pos)	// �P�_�ثe�`�I�A���`�I����Υk��
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
		if(ptr->left == NULL)		// ���p1: �`�I�S�����l�� �p�G�n�R���O�ڸ`�I
		{
			if(parent == ptr)	// �p�G�n�R���O�ڸ`�I
				root = root->right;
			else				// ��L
			{
				if( pos == 1 )
				{
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I���k�`�I
					parent->right = ptr->right;
				}
				else
				{
		 				//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I���k�`�I
					parent->left = ptr->right;
				}
			}
			printf("delete %s ok\n\n",ptr->name);
			free(ptr);
		}
		else if(ptr->right == NULL)	// ���p2: �`�I�S���k�l��
		{
			if(parent != ptr)
			{
				if( pos == 1 )
				{
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I�����`�I
					parent->right = ptr->left;
				}
				else
				{
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I�����`�I
					parent->left = ptr->left;
				}
			}
			else
				root = root->left;
			printf("delete %s ok\n\n",ptr->name);
			free(ptr);
		}
		else						// ���p3: �`�I�����k�l��
		{
			parent = ptr;
			next = ptr->left;	// ����N�Inext, �qptr����}�l��
 		if(next->right!=NULL){
			while(next->right != NULL)	// �����l�`�I���k�l���̤j�ȷ���N�I
			{
				parent = next;		// parent��next�����`�I
				next = next->right;
			}
			parent->right = next->left; // ¶�Lnext�`�I
		}
		else {
			ptr->left=next->left;
		}
		printf("delete %s ok\n\n",ptr->name);
		strcpy(ptr->name,next->name);//ptr->data = next->data;		// ���N!!
		ptr->phonenumber=next->phonenumber;
		free(next);// �R��next (�`�N: ���O�R��ptr)
		}
	}
	else {printf("cannot delete");}
	
	
	return root;	// �^�Ǧ���
}
