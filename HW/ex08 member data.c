#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct _node{
	char name[128];
	int number;
	char email[128];
	struct _node *next;
};	
typedef struct _node node;

node *getnode(){
	
	node *new_node;
	new_node=(node*)malloc(sizeof(node));
	return new_node;
}

node freenode(node *ptr){
	free(ptr);
}

//以下宣告函式
node *insert_node(node *head,node *pte,node input);
void printlist(node *ptr);
int length(node *head);
node *search_node(node *head,char s1[]);
node *delete_node(node *head,node *ptr);

int main(){
	
	char a;
	char s2[128];
	node *head,*ptr;
	head= ptr = NULL;	
	node input;
	while(1){
	//printf("i 新增\nl列印\nf搜尋\nd刪除\ng資料數\nq離開\n");
	scanf(" %c",&a);
	switch(a){
		case 'i':{

						if(head!=NULL){  
							ptr=head;
							while(ptr->next!=NULL){ptr=ptr->next;}
							}  //把ptr 永遠放到最後一筆資料 
						else if(head==NULL){ptr=head;};  //如果刪除最後一筆head為 NULL時 讓ptr也等於NULL 
						scanf("%s",&input.name);
						scanf("%s",&input.email);
						scanf("%d",&input.number);
						
						head=insert_node(head,ptr,input);
						if(head->next==NULL){
							ptr=head;
						}
						else{
							ptr=ptr->next;
						}
						break;
					}
		
		case 'l':{
			ptr=head;
			printlist(ptr);
			
			//printf("目前長度為 = %d",length(head));
			break;
					}
					
		case 'f':{
			
			ptr=head;
			//printf("請輸入要搜尋的名字...\n");
			scanf("%s",s2);
			ptr=search_node(head,s2);
			
			//printf("回到主程式..\n");
			if(ptr!=NULL){
			printf("found\n");	
			printf("%s\n",ptr->name);
			printf("%s\n",ptr->email);
			printf("%010d\n\n",ptr->number);
			
			}
			else if(ptr==NULL){printf("Not found\n");}
			ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			break;
		}
		
		case 'd':{
			//printf("請輸入要刪除的名字...\n");
			scanf("%s",&s2);
			ptr=search_node(head,s2);
			
			//printf("回到主程式..\n");
			if(ptr!=NULL){
			
				head=delete_node(head,ptr);
				printf("Delete ok\n");}
			else if(ptr==NULL){printf("Can not delete\n");}
			
	
			//printf("刪除完成..請記得檢察..");
			break;
		}
		/*case 'g':{
				printf("%d\n",length(head));
			break;
		}*/
		case 'q':{
			exit(0);
					}

		}

	system("pause");
	system("cls");	
	
	}

}



//以下列印list
void printlist(node *ptr){
		
		//ptr=head;
		if(ptr==NULL){
			printf("請新增資料...");
		}
		else{
		
			while(ptr!=NULL){
			printf("%s\n",ptr->name);
			printf("%s\n",ptr->email);
			printf("%010d\n\n",ptr->number);
			
			 //列印10個數字 輸入未滿10格自動補0 
			
			ptr=ptr->next;		
			}
		}
	//puts("");
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
node *search_node(node *head,char s1[]){
	node *ptr;
	ptr=head;
	//printf("尋找值為 -> %s\n",s1);
	//printf("目前值為 -> %s\n",ptr->name);
	while(strcmp(ptr->name,s1)!=0){
		//printf("目前值為 -> %s\n",ptr->name);
		ptr=ptr->next;
		if(ptr==NULL)break;
		
	}
	//printf("搜尋完成...跳出search迴圈 \n");
    return ptr;
}
 
//以下刪除節點
 node *delete_node(node *head,node *ptr){   //回傳值=head !!因為有可能會更新到head！！ 
	node *previous;
	if(ptr==head){
		//puts("第一種..");
		head=head->next;

		}
	else {
		previous=head;
		while(previous->next!=ptr){
			previous=previous->next;
			}
		
		if(ptr->next==NULL){
				//puts("第二種..");
				previous->next=NULL;
		}
		
		else{
			//puts("第三種..");
				previous->next=ptr->next;
		}
	
	}
	//puts("刪除中...");
	freenode(ptr);
	return(head);

} 

//以下計算鏈結長度 
int length(node *head){
 	int l=1;
 	if(head==NULL)return 0;
 	while(head->next!=NULL){
 		l++;
 		head=head->next;
	}	
return l;
} 
