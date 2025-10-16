#include<iostream>
#include <vector>
using namespace std;

int main(){
	
	int i,N=0;
	cin>>N;
	vector<int> v;
	vector<int>::iterator it;
	
	for(i=N;i!=0;i--){
		v.push_back(i);
		
	}
	for(i=0;i!=v.size();i++){
		cout<<"data "<<v[i]<<endl;
	}
	cout<<endl;
	for(it=v.end();it!=v.begin();it--){ //¤]¥i¥H¼g while(!v.empty()){ } 
		cout<<"data "<<v.back()<<endl;
		v.pop_back();
	}
	return 0;
}

