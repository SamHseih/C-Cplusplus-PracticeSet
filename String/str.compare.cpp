#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	
	string pivot="	cde";
	int n,i;
	string input;
	cin>>n;
	string *p=new string[n]; 
	for(i=0;i<n;i++){
		cin>>input;		
		p[i]=input;
	}	
	
	cout<<p[2].compare(pivot);
} 
