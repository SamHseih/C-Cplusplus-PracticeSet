#include<stdio.h>
#include<string.h>

int main(){
	  // �]�i�H�令 char str[] = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char *str = ""\;  
    char *substr = "��";
    int count=0;
	do{	printf("--------\n");
		printf("�@�}�l %s\n", str);
		
		str= strstr(str, substr);
		if(str==NULL)break;
		printf("�M��U�@�� %s\n", str);
		count++;
		str++;str++;
		
		printf("�e�i�@�� %s\n", str);
		printf("--------\n");
	}while(str!=NULL);
    printf("count= %d",count);
    return 0;
}
