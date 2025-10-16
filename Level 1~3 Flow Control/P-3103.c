//

#include<stdio.h>
int main(){
int ans,guess; 
int l=1,r=100;
scanf("%d",&ans);
printf("%d < ? < %d\n",l,r);
do{
	
	scanf("%d",&guess);
	if(ans<guess&&guess<r){
	
		r=guess;
		printf("wrong answer, guess smaller\n");
		printf("%d < ? < %d\n",l,r);
		}
	else if(ans>guess&&guess>l){
		l=guess;
		printf("wrong answer, guess larger\n");
		printf("%d < ? < %d\n",l,r);}
	else if(guess>=r||guess<=l){
		printf("out of range\n");
		printf("%d < ? < %d\n",l,r);}

}while(ans!=guess);

	printf("bingo answer is %d",ans);
	
return 0;	
}
