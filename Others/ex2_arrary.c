#include<stdio.h>
#include<time.h> 

//此為大樂透電腦開獎練習 

int main(){
	srand(time(NULL));
	int a[48];
	int i;
	for(i=0;i<=47;i++){
		a[i]=i+1;
	}  //填入array 1~48號 
	//for(i=0;i<=47;i++){printf("a[%d] => %d  mem:%p \n",i,a[i],&a[i]);} //此為驗證array是否確實填入 
	int ans[7];
	int r,dim;
	dim=47;
	for(i=0;i<=6;i++){
		r=rand()%dim;  //抽出亂數index 
		ans[i]=a[r];    //將號碼抽出 
		a[r]=a[dim];    //將最後的號碼覆蓋抽出的號碼,造成範圍縮小。 並從到尾再抽出一個號碼	 
		dim=dim-1;      //範圍縮小 
		//printf("r= %d ans[%d]=> %d a[%d]=> %d  dim=%d\n",r,i,ans[i],r,a[r],dim); //驗證所有運作是否正常 
	}
	
		printf("\n本期大樂透 電腦選號 號碼如下:\n");
	for(i=0;i<7;i++){
		if(i<6){printf(" %d ",ans[i]);
		}
		
		else{
		printf("\n");
		printf("特別號 : %d",ans[i]);}
	}
	return 0 ;
}
