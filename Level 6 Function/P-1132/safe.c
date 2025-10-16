#include <stdio.h>
#include <stdlib.h>
#include "safe.h"

int safe(int array[5][5]){
    int direction=0,i,j,x_main,y_main;  //x_main,y_main 起始位置 
    int x,y;// 變動的位置 
    int min=5;//防止有相同最小路徑的作用 把最小value紀錄,以防再次相同值 
    int d[4]={0};
	for(i=0;i<5;i++){      //找出起始位置 
    	for(j=0;j<5;j++){
    		if(array[i][j]==2){
    			x_main=j;
    			y_main=i;
			}
		}
	}
    for(i=1;i<=4;i++){  //按照順序找出安全點 1上 2右 3下 4左 
    	x=x_main;
    	y=y_main;
		switch(i){
			case 1:{ 
				while(array[y][x]!=1){  //找到1即刻離開迴圈並存下路徑長 
					if(y>0){
					y--;++d[i-1];
					}	
					if(y==0&&array[y][x]!=1){d[i-1]=0;break;} //到達最後一點並且沒有找到安全點,路徑=0 並離開 
				}
				//printf("向上走%d到達安全點\n",d[i-1]);
				break;
			}
			case 2:{
				while(array[y][x]!=1){
					if(x<4){x++;++d[i-1];}
					if(x==4&&array[y][x]!=1){d[i-1]=0;break;}
				}
				//printf("向右走%d到達安全點\n",d[i-1]);
				break;	
			}
			case 3:{
				while(array[y][x]!=1){
					if(y<4){y++;++d[i-1];}	
					if(y==4&&array[y][x]!=1){d[i-1]=0;break;}
				}
				//printf("向下走%d到達安全點\n",d[i-1]);
				break;
			}
			case 4:{
				while(array[y][x]!=1){
					if(x>0){x--;++d[i-1];}	
					if(x==0&&array[y][x]!=1){d[i-1]=0;break;}
				}
				//printf("向左走%d到達安全點\n",d[i-1]);
				break;
			}
		}
	}
	for(i=0;i<4;i++){
		if(d[i]<min&&d[i]!=0){
		direction=i+1;
		min=d[i];// 找到最小值並保存
		}  //direct==0 沒有找到 若等於1~4有找到解答 
	}
return direction;
}
