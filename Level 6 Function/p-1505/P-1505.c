#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans_A(char s1[],char s2[]){
    int a=0,i;
    for(i=0; i<strlen(s2); i++){
        if(s1[i]==s2[i]){   //�r�ťi�H�����B��operator��� 
            a++;
        }
    }
    return a;
}
 
int ans_B(char s1[],char s2[]){
    int i,b=0;
    int c[128]={0}; //�O�����X���ƶq
    for(i=0;i<strlen(s1);i++){
        if(s1[i]!=s2[i]){  //�Y���OA 
		c[s1[i]]++; //  �x�}c �Y��++, �N��s1�x�}���Y�r������ 
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
        if(c[s2[i]]>0&&s1[i]!=s2[i]){// �ˬds2[i]�N��r�����Ȧbc[i]���S���[1 �A�����ܦbs1�ɷ|�Q�[1 && �ư�A 
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
