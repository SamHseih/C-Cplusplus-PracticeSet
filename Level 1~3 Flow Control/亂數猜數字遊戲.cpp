#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  
  int guess=0;
  srand((unsigned)time(NULL));
  int ans=rand()%5+1;
  printf("Enter your guess number \n");
  scanf("%d",&guess);
  if(guess==ans){
  	printf("bingo answer is %d\n",guess);
  }
  else {
  	printf("wrong answer, answer is %d",ans);
  }
}
