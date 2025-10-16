#include<iostream>
#include<cstdlib>   // 需要用到exit的標頭檔
using namespace std;
class Binarytree_node{ //node 定義 
	friend class Binarytree;
	private:
		int data;
		Binarytree_node *left;
		Binarytree_node *right;
};
typedef Binarytree_node node;
class Binarytree{  //二元樹class
	
	public:
	Binarytree();
	void insert_node(int value);
	void Inorder();
	void Preorder();
	void Postorder();
	void Search(int value);
	void Deleranode(int value);
	
	private:
	node *root;
	node *Binsearch(node *ptr,int n);
	void print_Inorder(node *ptr);
	void print_preorder(node *ptr);
	void print_postorder(node *ptr);
	node *findparent(node *ptr,int value);
	void *deletenode(node *root,int value);
};
Binarytree::Binarytree(){ //初始化建構式 
	root=NULL;
}
void Binarytree::insert_node(int value){ //插入函式 
	node *new_node;
	node *current;
	node *parent;
	new_node=new node;
	new_node->data=value;
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
				if(current->data>value)   
					current = current->left; 
				else
					current = current->right; 
			}
			if(parent->data>value)
				parent->left = new_node;
			else
				parent->right = new_node;
		}
}
void Binarytree::Inorder(){  //中序列印包裝 
	print_Inorder(root);
}
void Binarytree::Preorder(){ //前序列印包裝 
	print_preorder(root);
}
void Binarytree::Postorder(){ //後序列印包裝 
	print_postorder(root);
}
void Binarytree::Search(int value){ //搜尋包裝 

	if(Binsearch(root,value)==NULL)
		cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
}
void Binarytree::Deleranode(int value){  //刪除包裝 
	deletenode(root,value);
}
void Binarytree::print_Inorder(node *ptr){   //中序列印函式 
	if(ptr!=NULL){
		print_Inorder(ptr->left);
		cout<<ptr->data<<" ";//printf("%d ",ptr->data);
		print_Inorder(ptr->right);
	}
}
void Binarytree::print_preorder(node *ptr){ //前序列印函式 
	if(ptr!=NULL){
		cout<<ptr->data<<" ";//printf("%d ",ptr->data);		
		print_preorder(ptr->left);
		print_preorder(ptr->right);
	}
}
void Binarytree::print_postorder(node *ptr){ //後序列印函式 
	if(ptr!=NULL){
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		cout<<ptr->data<<" "; //printf("%d ",ptr->data);	
	}
}
node *Binarytree::Binsearch(node *ptr,int n){  //二元搜尋函式 
	if(ptr!=NULL){
		if(ptr->data==n){
			//cout<<"found "<<ptr->data<<endl;
			//cout<<"Yes"<<endl;
			return ptr;
		}
		if(n<ptr->data){
			//printf("往左邊找中...\n");
			ptr=Binsearch(ptr->left,n);
			
		}
		else if(n>ptr->data){
			//printf("往右邊找中...\n");
			ptr=Binsearch(ptr->right,n);
		}
	}
	//if(ptr==NULL)cout<<"No"<<endl;
	return ptr;
}
node *Binarytree::findparent(node *ptr,int value){  //從ptr開始找某值 的父點函式 
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
void *Binarytree::deletenode(node *root,int value){ //刪除節點函式 
	
	node *ptr,*parent,*next;
	
	ptr=Binsearch(root,value); //ptr指向刪除點位置 
if(ptr==NULL); //printf("cannot delete\n");
else{
		if(ptr->data==value&&ptr->left==NULL){ //case 1 沒有左子樹 
			if(ptr==root){root=root->right;/*printf("delete %d ok",ptr->data);*/free(ptr);} //刪除點為root case1.1
			else {
				parent=findparent(root,value);//指出父點位置 
					if(ptr==parent->left){ //刪除點位於父點左邊 case 1.2 
						parent->left=ptr->right;
						//printf("delete %d ok",ptr->data);
						free(ptr);
					}
					else if(ptr==parent->right){ //刪除點位於父點右邊 case 1.3
						parent->right=ptr->right;
						//printf("delete %d ok",ptr->data);
						free(ptr);
					}
			}
			
		}
		
		else if(ptr->data==value&&ptr->right==NULL){ //case 2 沒有右子樹 
			if(ptr==root){root=root->left;/*printf("delete %d ok",ptr->data);*/free(ptr);} //刪除點為root case2.1
			else {
				parent=findparent(root,value);//指出父點位置 
					if(ptr==parent->left){ //刪除點位於父點左邊 case 2.2 
						parent->left=ptr->left;
						//printf("delete %d ok",ptr->data);
						free(ptr);
					}
					else if(ptr==parent->right){ //刪除點位於父點右邊 case 2.3 
						parent->right=ptr->left;
						//printf("delete %d ok",ptr->data);
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
			//printf("delete %d ok",ptr->data);
			ptr->data=next->data;	
			free(next);
		}
	}
}
int main(){
	
	int i,N,value;
	node *ptr;
   //new運算子會配置一個int所需要的空間，並傳回該空間的位址，所以您使用指標p來儲存這個位址
	
	cin>>N;
	//cout<<"N ="<<N<<endl;;
	Binarytree *p=new Binarytree[N];

	 
	for(i=0;i<N;i++){
		do{	
			cin>>value;
			if(value!=-1)p[i].insert_node(value);
		}while(value!=-1);
		//cout<<"離開第"<<i<<"次入"<<endl; 
	}
	cout<<"In-order:"<<endl;
	for(i=0;i<N;i++){
		p[i].Inorder();cout<<endl;
		}
	cout<<"Pre-order:"<<endl;	
	for(i=0;i<N;i++){
		p[i].Preorder();cout<<endl;
		}
	cout<<"Post-order:"<<endl;
	for(i=0;i<N;i++){
		p[i].Postorder();
		cout<<endl;	
		}

	cin>>value;
	cout<<"Delete "<<value<<endl;
	for(i=0;i<N;i++){
		p[i].Deleranode(value);
		}
		
	for(i=0;i<N;i++){p[i].Inorder();cout<<endl;}
	
	cin>>value;
	cout<<"Find "<<value<<endl;
	
	for(i=0;i<N;i++){
		p[i].Search(value);
	}
	delete p;
	
	
	return 0;
}
