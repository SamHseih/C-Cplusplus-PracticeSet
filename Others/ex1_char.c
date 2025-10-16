#include<stdio.h>



int main(){
	
	char a;
	
	
	
	while(1){
		
		scanf(" %c",&a);
		
	switch(a){
		case 'i':{
			printf("你輸入i");

			break;
					}
		
		case 'l':{
			printf("你輸入f");
			break;
					}
		
		case 'q':{
			printf("你輸入q");
			break;
					}
		default :{
			printf("請重新輸入 i f q\n");
			break;
					}
		}
	}
	return 0;
}
