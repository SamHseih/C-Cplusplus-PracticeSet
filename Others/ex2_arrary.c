#include<stdio.h>
#include<time.h> 

//�����j�ֳz�q���}���m�� 

int main(){
	srand(time(NULL));
	int a[48];
	int i;
	for(i=0;i<=47;i++){
		a[i]=i+1;
	}  //��Jarray 1~48�� 
	//for(i=0;i<=47;i++){printf("a[%d] => %d  mem:%p \n",i,a[i],&a[i]);} //��������array�O�_�T���J 
	int ans[7];
	int r,dim;
	dim=47;
	for(i=0;i<=6;i++){
		r=rand()%dim;  //��X�ü�index 
		ans[i]=a[r];    //�N���X��X 
		a[r]=a[dim];    //�N�̫᪺���X�л\��X�����X,�y���d���Y�p�C �ñq����A��X�@�Ӹ��X	 
		dim=dim-1;      //�d���Y�p 
		//printf("r= %d ans[%d]=> %d a[%d]=> %d  dim=%d\n",r,i,ans[i],r,a[r],dim); //���ҩҦ��B�@�O�_���` 
	}
	
		printf("\n�����j�ֳz �q���︹ ���X�p�U:\n");
	for(i=0;i<7;i++){
		if(i<6){printf(" %d ",ans[i]);
		}
		
		else{
		printf("\n");
		printf("�S�O�� : %d",ans[i]);}
	}
	return 0 ;
}
