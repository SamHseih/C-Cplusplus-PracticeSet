#include<iostream>
#include<list>
using namespace std;
int main(){
	list<int> l;
	list<int>::iterator it;
	it=l.begin();
	int i,n,value;
	cin>>n;
	
	for(i=0;i<n;i++){
		cin>>value;
		l.push_back(value);
	}
	
	for(it=l.end();it!=l.begin();it--){
		cout<<"data "<<l.back()<<endl;
		l.pop_back();
	}
	cout<<"data "<<l.back()<<endl;
	
}
