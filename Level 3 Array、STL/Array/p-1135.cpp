#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	int n,i,value=0;
	float ans;
	cin>>n;
	float *p=new float[n];
	for(i=0;i<n;i++){
		cin>>value;
		p[i]=value;
	}

	
	if(n%2==0){
		ans=round((p[n/2-1]+p[n/2])/2);
	}
	else{
		ans=p[n/2];
	}
	cout<<ans<<endl;
    return 0;
}