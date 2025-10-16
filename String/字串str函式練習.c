#include<stdio.h>
#include<string.h>

int main(){
	  // 也可以改成 char str[] = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char *str = ""\;  
    char *substr = "天";
    int count=0;
	do{	printf("--------\n");
		printf("一開始 %s\n", str);
		
		str= strstr(str, substr);
		if(str==NULL)break;
		printf("尋找下一個 %s\n", str);
		count++;
		str++;str++;
		
		printf("前進一格 %s\n", str);
		printf("--------\n");
	}while(str!=NULL);
    printf("count= %d",count);
    return 0;
}
