#include<stdio.h>
#include<string.h>
// �����r���}�C�m�� 
int main(){
	
	char a[6]={'a',' ','p','p','l','e'};   //�r���}�C��l�ƽd�Ҥ@  
	int i;
	for(i=0;i<=5;i++)
	printf("%c  mem:%d \n",a[i],&a[i]);  
		printf("\n");
		
		
	char b[]={"C program"};  //�r���}�C��l�ƽd�ҤG  
	for(i=0;i<=8;i++)
	printf("%c",b[i]);
		printf("\n");
		
		
	char c[]="abcd !$%^";   //�r���}�C��l�ƽd�ҤT 
	for(i=0;i<=8;i++)
	printf("%c",c[i]);
		printf("\n");
		
		
	printf("\n\na=> %s\nb=> %s\nc=> %s",a,b,c); //�`�N�b���Ҫ�printf��Ƥ��A�ϥΪ��榡�r�ꬰ��%s���A��ܿ�X���O�@�Ӧr��C�Ӧb��X��C�����X�}�C�W�٫h�i�C����g���Gprintf("%s",c[]);d


//��@�Ӧr���}�C�A�p�G���@��l�ƽ�ȡA�h���������}�C���סC

//���scanf��ƿ�J�r��ɡA�r�ꤤ����t���Ů�A�_�h�N�H�Ů�@���ꪺ�����šC
	printf("\n");
	//char st1[2],st2[2],st3[2];
	//printf("input string:\n");
	//scanf("%s%s%s",st1,st2,st3);   //�S�O�`�N �}�C��J  �ŧi�e�����ݭn&�A�]���}�C�����N�O�_�l��m�A�G���ݭn�A��J��m 
	//printf("st1=>%s\nst2=>%s\nst3=>%s\n",st1,st2,st3);
	// ��J�Y���ť��� �N��@�Ӧr�ꪺ���� \0 
	
	//�H�U���r����ƥܽd
	static char st4[30]="My name is ";

 	char st5[10];

  	printf("input your name:\n");

 	gets(st5);  //��J�r�� 

  	strcat(st4,st5);  //�X�֦r�� 

 	 puts(st4);  //��X�r�� 
	
	
	
}
