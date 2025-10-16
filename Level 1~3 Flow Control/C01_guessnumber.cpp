#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  
  int guess;
  int ans;
  scanf("%d",&ans);
  scanf("%d",&guess);
  if(guess==ans){
  	printf("bingo answer is %d",guess);
  }
  else {
  	printf("wrong answer, answer is %d",ans);
  }
  return 0 ;
  
}
