#include<stdio.h>
#include<stdlib.h>

	struct _student{
		int math;
		int english;
		int computer;
	};
	typedef struct _student student;
int sum(int);

int main(){
	float ma=0,eng=0,cp=0;
	student *ptr;
	int n=5,i=0,k;
	//printf("請輸入學生數 : ");
	//scanf("%d",&n);
	ptr=(student*)malloc(sizeof(student)*n);
	
	do{
		scanf("%d",&k);
		ptr[i].math=k;
		ma=ma+k;
		scanf("%d",&k);
		ptr[i].english=k;
		eng=eng+k;
		scanf("%d",&k);	
		ptr[i].computer=k;
		cp=cp+k;
		i++;
	}while(i!=n);
	printf("%.2f\n%.2f\n%.2f",ma/n,eng/n,cp/n);
//	printf("數學平均= %.2f\n英文平均= %.2f\n電腦平均= %.2f\n",ma/n,eng/n,cp/n);
	
	/*
	for(i=0;i<n;i++){
		printf("S[%d] math -> %d\n",i,ptr[i].math);
		printf("S[%d] english -> %d\n",i,ptr[i].english);
		printf("S[%d] computer -> %d\n",i,ptr[i].computer);
	}*/
	
	free(ptr);
	return 0;
}

