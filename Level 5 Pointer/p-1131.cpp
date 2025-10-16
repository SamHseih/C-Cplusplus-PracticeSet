#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	vector<float> v;
	vector<float>::iterator it;
	int i,n,value;
	int rating,mid;
	cin>>n>>rating;
	for(i=0;i<n;i++){
		cin>>value;
		v.push_back(value);
	}
	
	if(n%2==0){
		mid=v[n/2-1];
	}
	else{
		mid=v[n/2];
	}
	cout<<mid<<endl;
	if(rating>mid)cout<<"WINNER WINNER CHICKEN DINNER!"<<endl;
	else cout<<"BETTER LUCK NEXT TIME!";
return 0;
}
