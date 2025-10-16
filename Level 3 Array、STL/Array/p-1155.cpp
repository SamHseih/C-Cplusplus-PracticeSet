#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	int n,i,value=0,j;
	int target,tem;
	cin>>n;
	int *p=new int[n];
	for(i=0;i<n;i++){
		cin>>value;
		p[i]=value;
	}
    cin>>target;
    int *s=new int[target]();  //加上() 為初始化動態陣列 
        for(j=0;j<n;j++){
            tem=p[j]%target;
            s[tem]++;
        }
    
    for(i=0;i<target;i++){
        cout<<s[i]<<endl;
    }
    
    return 0;
}
