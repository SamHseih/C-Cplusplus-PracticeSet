#include<stdio.h>



int main(){
	
	char a;
	
	
	
	while(1){
		
		scanf(" %c",&a);
		
	switch(a){
		case 'i':{
			printf("�A��Ji");

			break;
					}
		
		case 'l':{
			printf("�A��Jf");
			break;
					}
		
		case 'q':{
			printf("�A��Jq");
			break;
					}
		default :{
			printf("�Э��s��J i f q\n");
			break;
					}
		}
	}
	return 0;
}
