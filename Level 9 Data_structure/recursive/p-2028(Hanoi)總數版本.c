/*������C�Ӷ�L��3�ӥ���,
	�Ĥ@�� �b���ʥh�ؼж𤧫e��񥦤p����L �� ���ʥh������ 
 	�ĤG�� ���ʨ�ؼж�
	�ĤT��  �Ⲿ�줤���𪺶�L ���h�ؼж�  

	�ҥH�n�������j
		 

*/


#include<stdio.h>

int hanoi(int n,char from,char mid,char to);


int main(){
	int n,i;
	scanf("%d",&n);
	n=hanoi(n,'A','B','C');
	printf("%d",n);
	return 0;
}

int hanoi(int n,char from,char mid,char to){  // n�� �b�h�ʲ�n�Ӷ�L��
	int count=0;
	if(n==0){return 0;}
	count=hanoi(n-1,from,to,mid);// ���N��n-1�Ӷ�L�h�졨������/�ؼж�
	count++;printf("��L%2d�q%c��-> %c��\n",n,from,to);// �N�ۤv�h�졨�ؼж�
	count=count+hanoi(n-1,mid,from,to);// �A�N��n-1�Ӷ�L�q�������𡨷h�^��		
	return count;
}
