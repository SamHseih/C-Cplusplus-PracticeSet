#include <stdio.h>
#include <stdlib.h>
#include "safe.h"

int safe(int array[5][5]){
    int direction=0,i,j,x_main,y_main;  //x_main,y_main �_�l��m 
    int x,y;// �ܰʪ���m 
    int min=5;//����ۦP�̤p���|���@�� ��̤pvalue����,�H���A���ۦP�� 
    int d[4]={0};
	for(i=0;i<5;i++){      //��X�_�l��m 
    	for(j=0;j<5;j++){
    		if(array[i][j]==2){
    			x_main=j;
    			y_main=i;
			}
		}
	}
    for(i=1;i<=4;i++){  //���Ӷ��ǧ�X�w���I 1�W 2�k 3�U 4�� 
    	x=x_main;
    	y=y_main;
		switch(i){
			case 1:{ 
				while(array[y][x]!=1){  //���1�Y�����}�j��æs�U���|�� 
					if(y>0){
					y--;++d[i-1];
					}	
					if(y==0&&array[y][x]!=1){d[i-1]=0;break;} //��F�̫�@�I�åB�S�����w���I,���|=0 �����} 
				}
				//printf("�V�W��%d��F�w���I\n",d[i-1]);
				break;
			}
			case 2:{
				while(array[y][x]!=1){
					if(x<4){x++;++d[i-1];}
					if(x==4&&array[y][x]!=1){d[i-1]=0;break;}
				}
				//printf("�V�k��%d��F�w���I\n",d[i-1]);
				break;	
			}
			case 3:{
				while(array[y][x]!=1){
					if(y<4){y++;++d[i-1];}	
					if(y==4&&array[y][x]!=1){d[i-1]=0;break;}
				}
				//printf("�V�U��%d��F�w���I\n",d[i-1]);
				break;
			}
			case 4:{
				while(array[y][x]!=1){
					if(x>0){x--;++d[i-1];}	
					if(x==0&&array[y][x]!=1){d[i-1]=0;break;}
				}
				//printf("�V����%d��F�w���I\n",d[i-1]);
				break;
			}
		}
	}
	for(i=0;i<4;i++){
		if(d[i]<min&&d[i]!=0){
		direction=i+1;
		min=d[i];// ���̤p�ȨëO�s
		}  //direct==0 �S����� �Y����1~4�����ѵ� 
	}
return direction;
}
