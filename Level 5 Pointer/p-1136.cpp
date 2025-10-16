#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main(){
	vector<int> v;
	vector<int>::iterator it;
	int i,n,value;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>value;
		v.push_back(value);
	}
	
	for(i=0;i<n;i=i+2){
		swap(v[i],v[i+1]);		
	}
	
	for(i=0;i<n;i++){
		cout<<v[i]<<" ";
	}cout<<endl;
	
return 0;
}
