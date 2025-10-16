#include "decode.h"
#include <string.h>
int ans_A(char s1[],char s2[]){
    int a=0,i;
    for(i=0; i<strlen(s2); i++){
        if(s1[i]==s2[i]){
            a++;
        }
    }
    return a;
}
 
int ans_B(char s1[],char s2[]){
    int b=0,i;
    int c[128]={0}; //記錄號碼的數量
    for(i=0;i<strlen(s1);i++){
        if(s1[i]!=s2[i]){
		c[s1[i]]++;
		}
    }
    for(int i=0;i<strlen(s1);i++){
        if(c[s2[i]]>0&&s1[i]!=s2[i]){
            c[s2[i]]--;
            b++;
        }
    }
    return b;
}
