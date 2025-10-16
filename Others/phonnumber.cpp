#include<stdio.h>
#include<string.h>

int main(){
	
	char s1[11]={0};
	int i;
	for(i=0;i<10;i++){
		s1[i]='0';
	}
	int k=0;
	scanf("%d",&k);
	printf("%010d\n",k);
	printf("%s\n",s1);
	char s2[11];
	scanf("%s",s1);
	printf("%s",s1);
}
