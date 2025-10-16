#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans_A(char s1[],char s2[]){
    int a=0,i;
    for(i=0; i<strlen(s2); i++){
        if(s1[i]==s2[i]){   //字符可以直接運用operator比較 
            a++;
        }
    }
    return a;
}
 
int ans_B(char s1[],char s2[]){
    int i,b=0;
    int c[128]={0}; //記錄號碼的數量
    for(i=0;i<strlen(s1);i++){
        if(s1[i]!=s2[i]){  //若不是A 
		c[s1[i]]++; //  矩陣c 某格++, 代表s1矩陣的某字元的值 
		}
    }
    /*for(i=0;i<128;i++){
    	printf("C[%d]: %d\n",i,c[i]);
		//cout<<"C["<<i<<"]: "<<c[i]<<endl;
	}*/
    // i:0123
  //s1[]:1234
  //s2[]:1345
   //c[]:0123456789 10111213141516.....
	//  :??001????? ?
	
	// i:0123
  //s1[]:12a2 
  //s2[]:212b
   //c[]:0123456789 10111213141516.....
	//  :121
	//1=0->0
	//2=1->0
	//a=2->1
	
	
    for(i=0;i<strlen(s1);i++){
        if(c[s2[i]]>0&&s1[i]!=s2[i]){// 檢查s2[i]代表字元的值在c[i]有沒有加1 ，有的話在s1時會被加1 && 排除A 
        	//printf("i:%d",i);
            c[s2[i]]--;
            b++;
        }
    }
   
    return b;
}
int main() {
    char s1[11]={0}, s2[11]={0};
    int A=0, B=0;
    scanf("%s%s", s1, s2);
    A=ans_A(s1,s2);
    B=ans_B(s1,s2);
    printf("%dA%dB\n", A, B);
    return 0;
}
