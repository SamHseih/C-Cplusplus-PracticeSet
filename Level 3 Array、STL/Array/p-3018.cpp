#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
	int student[5][4]={0};
	int i,j,sum=0,hstudent;
	float havg=0,allavg=0;
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){
			cin>>student[i][j];
			sum=sum+student[i][j];
		}
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){
		student[i][3]=student[i][3]+student[i][j];
		}
	}
	for(i=0;i<5;i++){
	cout<<"student "<<i+1<<endl;
		for(j=0;j<4;j++){	
		if(j==0)cout<<" 1: "<<student[i][j]<<endl;
		if(j==1)cout<<" 2: "<<student[i][j]<<endl;
		if(j==2)cout<<" 3: "<<student[i][j]<<endl;
		if(j==3)cout<<" sum: "<<student[i][j]<<endl;
		if(j==3){
			cout<<" avg: "<<fixed<<setprecision(2)<<(float)student[i][j]/3<<endl;
			allavg=allavg+(float)student[i][j]/3;
		}
		if((float)student[i][j]/3>havg){
			havg=(float)student[i][j]/3;
			hstudent=i+1;
			}
		}
	}
	cout<<"total: "<<sum<<", avg: "<<fixed<<setprecision(2)<<allavg/5<<endl;
	cout<<"highest avg: student "<<hstudent<<": "<<fixed<<setprecision(2)<<havg;
}
