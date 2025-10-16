#include<stdio.h>


	struct _student{
		int math;
		int english;
		int computer;
	};
	typedef struct _student student;


int main(){
	
	student s[5]={0};
	student *i;
	int k;
	i=s;
	scanf("%d",&k);
	s[0].math=k;
		printf("S[0] math -> %d~~\n",s[0].math);
	(i+1)->english=18;
		printf("S[1] eng -> %d~~\n",s[1].english);
	(i+2)->computer=20;
		printf("S[2] cp -> %d~~\n",s[2].computer);
	
	printf("S[0] math -> %d~~\n",s[0].math);
	
	
	/*for(i=0;i<5;i++){
		scanf("%d",s[i].math);
		printf("S[%d] math -> %d\n",i,s[i].math);
		scanf("%d",s[i].english);
		scanf("%d",s[i].computer);
	}
	for(i-0;i<5;i++){
		printf("S[%d] math -> %d\n",i,s[i].math);
		printf("S[%d] english -> %d\n",i,s[i].english);
		printf("S[%d] computer -> %d\n",i,s[i].computer);
	}*/
	return 0;
}
