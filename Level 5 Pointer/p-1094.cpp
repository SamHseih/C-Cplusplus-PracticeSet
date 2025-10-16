#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int main(){
	int n,i;
	vector<string> s;
	vector<string>::iterator it;
	cin>>n;
	string input;
	for(i=0;i<n;i++){
		cin>>input;
		s.push_back(input);
	}	
	
	sort(s.begin(),s.end());
	
	for(it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}	
	return 0;
}

