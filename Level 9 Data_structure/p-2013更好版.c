#include<stdio.h>
#define N 5
struct _student{
	int math;
	int english;
	int computer;
};
typedef struct _student student;

float ma=0,eng=0,pc=0;
int main(){
	student s[N]={0};
	int i=0;
	for(i=0;i<5;i++){
		scanf("%d",&s[i].math);
		ma+=s[i].math;
		scanf("%d",&s[i].english);
		eng+=s[i].english;
		scanf("%d",&s[i].computer);
		pc+=s[i].computer;	
	}
	printf("數學平均=%.2f\n英文平均=%.2f\n電腦平均=%.2f\n",ma/N,eng/N,pc/N);
	
	return 0; 
}

