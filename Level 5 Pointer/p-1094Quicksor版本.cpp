#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

void swap(string *a,string *b);
void quickSort(string *mains,int low,int high);	


int main(){
	int n,i;
	string input;
	cin>>n;
	string *p=new string[n]; 
	for(i=0;i<n;i++){
		cin>>input;		
		p[i]=input;
	}	

	quickSort(p,0,n-1);
	for(i=0;i<n;i++)
	cout<<p[i]<<" ";
	cout<<endl;
	
	return 0;
}

void swap(string *a,string *b){
	string temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void quickSort(string *mains,int low,int high){
	
	int i,j,l;
	string pivot;
	i=low+1; //直接跳過 pivot 不會多做一次 
	j=high; //n-1
	pivot=mains[low];
	
	//printf("pivot = %d  low= %d high= %d\n",pivot,low,high);
	
	do{
		while((mains[i].compare(pivot)<0)&&i<high){ //numbers[i]<pivot&&i<high
			i++;
			//printf("i = %d\n",i);
		}
		while((mains[j].compare(pivot)>0)&&j>=0){  //numbers[j]>pivot&&j>=0
			j--;
			//printf("j = %d\n",j);
		}
		if(i<j){
			swap(mains[i],mains[j]);
			//puts("交換1次");

		}
	}while(i<j);
	//printf("我是準備跟pivot交換的J=%d  值為=\n",j,numbers[j]); 
	/*for(i=0;i<6;i++){
		cout<<"  "<<mains[i];
	}cout<<endl;*/
	mains[low]=mains[j];
	mains[j]=pivot;

	if(j-1>low){
		quickSort(mains,low,j-1);
	}
	if(j+1<high){
		quickSort(mains,j+1,high);
	}
}

