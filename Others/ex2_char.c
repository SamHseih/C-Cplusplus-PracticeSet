#include<stdio.h>
#include<string.h>
// 此為字元陣列練習 
int main(){
	
	char a[6]={'a',' ','p','p','l','e'};   //字元陣列初始化範例一  
	int i;
	for(i=0;i<=5;i++)
	printf("%c  mem:%d \n",a[i],&a[i]);  
		printf("\n");
		
		
	char b[]={"C program"};  //字元陣列初始化範例二  
	for(i=0;i<=8;i++)
	printf("%c",b[i]);
		printf("\n");
		
		
	char c[]="abcd !$%^";   //字元陣列初始化範例三 
	for(i=0;i<=8;i++)
	printf("%c",c[i]);
		printf("\n");
		
		
	printf("\n\na=> %s\nb=> %s\nc=> %s",a,b,c); //注意在本例的printf函數中，使用的格式字串為“%s”，表示輸出的是一個字串。而在輸出表列中給出陣列名稱則可。不能寫為：printf("%s",c[]);d


//對一個字元陣列，如果不作初始化賦值，則必須說明陣列長度。

//當用scanf函數輸入字串時，字串中不能含有空格，否則將以空格作為串的結束符。
	printf("\n");
	//char st1[2],st2[2],st3[2];
	//printf("input string:\n");
	//scanf("%s%s%s",st1,st2,st3);   //特別注意 陣列輸入  宣告前面不需要&，因為陣列本身就是起始位置，故不需要再輸入位置 
	//printf("st1=>%s\nst2=>%s\nst3=>%s\n",st1,st2,st3);
	// 輸入若有空白鍵 代表一個字串的結束 \0 
	
	//以下為字元函數示範
	static char st4[30]="My name is ";

 	char st5[10];

  	printf("input your name:\n");

 	gets(st5);  //輸入字串 

  	strcat(st4,st5);  //合併字串 

 	 puts(st4);  //輸出字串 
	
	
	
}
