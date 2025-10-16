#include<iostream>
using namespace std; 

int C(int n,int m){
	if(n==1||n==m)return 1;
	if(m==1)return n;
	return C(n-1,m)+C(n-1,m-1);
}

int main(){
	int n,m;
	cin>>n>>m;
	cout<<C(n,m);
}
