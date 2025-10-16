#include<stdio.h>
#include<stdlib.h>
struct _student{
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
 		scanf("%d",&num);
 		switch (num){
 			case 1:	{
			 		scanf("%d",&s[i].math);
			 			Avgma+=s[i].math;
			 		scanf("%d",&s[i].english);
			 			Avgeng+=s[i].english;
			 		scanf("%d",&s[i].computer);
			 			Avgcp+=s[i].computer;			 			
						i++;
						k++;
						break;
					}
			 case 2:{
			 		scanf("%d",&num);
			 		printf("%d\n",s[num-1].math);
			 		printf("%d\n",s[num-1].english);
			 		printf("%d\n",s[num-1].computer);
						break;
			 		}
			 case 3:{
			 		scanf("%d",&num);
			 		scanf("%d",&s[num-1].math);
			 		scanf("%d",&s[num-1].english);
			 		scanf("%d",&s[num-1].computer);
						break;
					}
			 case 4:{
			 		for(j=0;j<i;j++){
			 			printf("%d\n",s[j].math);
			 			printf("%d\n",s[j].english);
			 			printf("%d\n",s[j].computer);
					 	}
						break;
					}
			 case 5:{
			 		printf("%.2f\n",Avgma/i);
			 		printf("%.2f\n",Avgeng/i);
			 		printf("%.2f\n",Avgcp/i);
						break;
					 }
			 case 6:{
				 	scanf("%d",&num);
				  	float tem=0;
					tem=(float)(s[num-1].math+s[num-1].english+s[num-1].computer)/3;
					printf("%.2f\n",tem);
						break;
					}
		}
	}while(num!=0);
return 0;
 }
