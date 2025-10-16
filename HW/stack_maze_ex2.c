#include <stdio.h>
#include <stdlib.h>

// 堆疊結構的宣告
struct stack_node 
{
    int x;
    int y;
    struct stack_node *next;
};
typedef struct stack_node node;

node *path = NULL;

void printlist(node *ptr);
// 堆疊資料的存入
node *push(node *stack, int x, int y)
{
     
    node *new_node;    
    new_node = (node *)malloc(sizeof(node));    
    
    //判斷配置是否成功
    
    if(new_node==NULL) 
    {
        printf("記憶體配置失敗!\n");
        //exit(0);
    }
    
    new_node->x = x;
    new_node->y = y;
    new_node->next = stack;
    stack = new_node;
    
    return stack;
    
}


//堆疊資料的取出
node *pop(node *stack, int *x, int *y)
{
    node *top;

    if( stack != NULL ) //判斷堆疊是否為空的
    {
        top = stack;
        stack = stack->next;
        *x = top->x;
        *y = top->y;
        free(top);
    }
    else 
    {
        *x = -1;
        *y = -1;
    }
    return stack;
}


void walk(int maze[][15], int x, int y)
{
    while(1)
    {
        if(x==1 && y==1) // 是否為出口
        {
            path = push(path, x, y);
            maze[y][x] = 2; // 標示最後一點
            break;
        }
        maze[y][x] = 2; // 標示為走過的路
        if( maze[y-1][x] <= 0 ) // 往上方走
        {
            path = push(path, x, y);
            y--;
        }
        else if( maze[y+1][x] <= 0 ) // 往下方走
        {
            path = push(path, x, y);
            y++;
        }
        else if( maze[y][x-1] <= 0 ) // 往左方走
        {
            path = push(path, x, y);
            x--;
        }
        else if( maze[y][x+1] <= 0 ) // 往右方走
        {
            path = push(path, x, y);
            x++;
        }
        else // 無路可走 => 回朔
        {
            maze[y][x] = 3;
            path = pop(path, &x, &y); // 退回一步
        }
    }
}



// 主程式
int main()
{
    // 宣告
    int i, j;
    node *ptr;
    
    // 輸入
    int maze[10][15] = // x=15, y=10
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1,
		1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1,
		1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    // 計算
    walk(maze, 13, 8);

    // 輸出
    printf("maze:\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<15; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }  
	printf("path:\n");  
	ptr=path;
	printlist(ptr);

    // 結束
    system("pause");
    return 0;
}


void printlist(node *ptr){
	if(ptr->next!=NULL){
		printlist(ptr->next);
	}
	printf("[ %d, %d]\n",ptr->x,ptr->y);
}


