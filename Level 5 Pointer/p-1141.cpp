#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> v;
	vector<int>::iterator it;
	int i,n,value;
	int avg=0;
	int ans=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>value;
		avg=avg+value;
		v.push_back(value);
	}
	avg=avg/n;

	for(i=0;i<n;i++){
		if(avg<v[i])ans++;
	}
	cout<<ans;
	
return 0;
}
