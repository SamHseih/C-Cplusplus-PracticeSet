#include<stdio.h>
#include<stdlib.h>
struct _student{
	int number;
	int math;
	int english;
	int computer;
};
typedef struct _student student;


 int main(){
 	int num=0;
 	int i=0,k=1,j;	
	student s[5]={0};
	float Avgma=0,Avgeng=0,Avgcp=0;
 	do{ 
 		printf("目前學生數 : %d\n",i);
		printf("請選擇 1新增 2列印 3修改 4印全部 5算術平均 6算數平均(同學) 0離開:\n");
 		scanf("%d",&num);
 		
 		switch (num){
 			case 1:	{
 				printf("新增同學中..請輸入數學，英文，電腦 :\n");
			 	if(i==5){printf("人數已滿");break;}
				else{
					s[i].number=k;
			 		scanf("%d",&s[i].math);
			 			Avgma+=s[i].math;
			 		scanf("%d",&s[i].english);
			 			Avgeng+=s[i].english;
			 		scanf("%d",&s[i].computer);
			 			Avgcp+=s[i].computer;			 			
					i++;
					k++;
					break;}
			 }
			 case 2:{
			 	printf("列印同學成績中..請輸入座號\n");
			 	scanf("%d",&num);
			 	printf("數學: %d\n",s[num-1].math);
			 	printf("英文: %d\n",s[num-1].english);
			 	printf("電腦: %d\n",s[num-1].computer);
				break;
			 }
			 case 3:{
			 	printf("修改同學成績中..請輸入座號\n");
			 	scanf("%d",&num);
			 		scanf("%d",&s[num-1].math);
			 		scanf("%d",&s[num-1].english);
			 		scanf("%d",&s[num-1].computer);
				break;
			 }
			 case 4:{
			 	printf("列印所有同學成績中..\n");
			 	for(j=0;j<i;j++){
			 		printf("數學: %d\n",s[j].math);
			 		printf("英文: %d\n",s[j].english);
			 		printf("電腦: %d\n",s[j].computer);
				 }
				break;
			 }
			 case 5:{
			 	printf("列印平均成績中..\n"); 
			 		printf("數學平均: %.2f\n",Avgma/i);
			 		printf("英文平均: %.2f\n",Avgeng/i);
			 		printf("電腦平均: %.2f\n",Avgcp/i);
				break;
			 }
			 case 6:{
			 	printf("列印某位同學平均成績中..請輸入座號\n");
				 	scanf("%d",&num);
				  	float tem=0;
					tem=(float)(s[num-1].math+s[num-1].english+s[num-1].computer)/3;
				  	printf("平均成績: %.2f\n",tem);
				break;
			 }
		}
	}while(num!=0);
return 0;
 }
