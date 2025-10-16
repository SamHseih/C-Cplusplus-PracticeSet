#include<stdio.h>
#include<stdlib.h>

#include<math.h>

struct _node{
	int data;
	struct _node *next;
};
typedef struct _node node;

node *getnode();

//以下釋放節點
node freenode (node *p){
	free(p);
} 
//以下宣告函式 
node *insert_node(node *head,node *pte,node input);
void printlist(node *ptr);
node *search_node(node *head,int num);

int main(){
	char a;
	node *head,*ptr;
	head= ptr = NULL;	
	node input;
	while(1){
	//printf("s 新增資料即排序 (由小到大) q 離開 l 列印\n");
	scanf(" %c",&a);
	
	switch(a){
		case 's':{
				ptr=head;
				scanf("%d",&input.data);
				
				if(head==NULL){ 
					head=insert_node(head,ptr,input);
					//printf("第一種插入完成\n");
					}
				else{
				
					if(input.data==ptr->data){ 
						head=insert_node(head,ptr,input);
						//printf("第二種插入完成\n");
						}
					else if(input.data<ptr->data){
						head=head=insert_node(head,NULL,input);
						//printf("第三種插入完成\n");
					}
					
					
					else {
						
						while(ptr->next!=NULL){
							//printf("我卡在這...\n");
							//printf("%d",ptr->data);
							if(input.data>ptr->next->data){
							ptr=ptr->next;
							}
							else if(input.data<=ptr->next->data){break;}
							else if(input.data==ptr->data){break;}
						}	
						head=insert_node(head,ptr,input);
						//printf("第四種插入完成\n");
					}		
				}
			
			break;
		}
		case 'l':{
			ptr=head;
			printlist(ptr);
			break;
		}
		
		case 'q':{
			exit(0);
			break;
		}
	}
	
	
	
	
	}
}
//以下新增節點 
node *getnode(){
	node *p;
	p=(node*)malloc(sizeof(node));
		if(p==NULL){
			printf("記憶體空間不足..\n");
			exit(1);
		}
	return p;
}

//以下列印list
void printlist(node *ptr){
		
		//ptr=head;
		if(ptr==NULL){
			printf("請新增資料...");
		}
		else{
		
			while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->next;		
			}
		}
	puts("");
}

//以下插入節點 
node *insert_node(node *head,node *ptr,node input){
		node *new_node; /* 新節點指標變數*/
		new_node = getnode(); /* 建立新節點,取得一個可用節點*/
		*new_node = input; /* 建立節點內容*/   //前面  星號+指標變數  = 指標位置的整塊資料  含Data與指標   ((運用在多重data時，可使用此寫法 例如有 data1 座號 data2 地址 dat3 身分證 此寫法包了全部 
		new_node->next = NULL; /* 設定指標初值*/ 
	
	if(ptr==NULL){/* 指標ptr是否是NULL */
		
		/* 第一種情況: 插入第一個節點*/
		new_node->next = head; /* 新節點成為串列開始*/
		head = new_node;
	}
	else {
		if(ptr->next==NULL)/* 是否是串列結束*/
		/* 第二種情況: 插入最後一個節點*/
			ptr->next=new_node; /* 最後指向新節點*/
			
		else {
			
		/* 第三種情況: 插入成為中間節點*/
			new_node->next=ptr->next;/* (3) 新節點指向下一節點(3)*/		
			ptr->next=new_node;/* 節點ptr指向新節點(4)*/
			}
	
	} 
	return head;
}


//以下尋找節點
node *search_node(node *head,int num){
	node *ptr;
	ptr=head;
	//printf("尋找值為 -> %d\n",num);
	//printf("目前值為 -> %d\n",ptr->data);
	while(ptr->data!=num){
	//	printf("ptr data -> %d \ninput data ->%d\n",ptr->data,num);
		ptr=ptr->next;
		if(ptr==NULL)break;
		
	}
	//printf("搜尋完成...跳出search迴圈 \n");
    return ptr;
}



 
