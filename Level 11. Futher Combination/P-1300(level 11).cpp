#include<iostream>
#include<string>
#include<list>
using namespace std;


class staff{
	
	public:
		staff();
		void setData(int degree,int firenum,int defencenum);
		bool check(staff s1);
		bool Isbad;
		void show();
	private:
		int Degree;
		int FireDegree;
		int DefenceDegree;
};

staff::staff(){
	Degree=0;
	FireDegree=0;
	DefenceDegree=0;
	Isbad=false;
	
}
void staff::show(){
	if(Isbad==true)cout<<"Bad"<<endl;
	else cout<<"Good"<<endl;
	cout<<"Degree: "<<Degree<<"   ";
	cout<<"FireDegree: "<<FireDegree<<"	  ";
	cout<<"DefenceDegree: "<<DefenceDegree<<endl;
	
}

void staff::setData(int degree,int firenum,int defencenum){
	Degree=degree;
	FireDegree=firenum;
	DefenceDegree=defencenum;
}

bool staff::check(staff s1){
	int flag=0;
	if(FireDegree>s1.DefenceDegree)flag++;
	if(Degree>s1.Degree)flag++;
	if(flag==2)return 1;
	return 0;
}

int main(){
	int i,n;
	cin>>n;
	if(n<1||n>5000)return -1;
	int degree=0,fire=0,defence=0;
	
	staff *p=new staff[n];
	for(i=0;i<n;i++){
		cin>>degree>>fire>>defence;
		if(degree<1||degree>30000)return -1;
		if(fire<1||fire>30000)return -1;
		if(defence<1||defence>30000)return -1;
		p[i].setData(degree,fire,defence);
	}
	
/*	for(i=0;i<n;i++){
		cout<<"Staff: "<<i+1<<"  ";
		p[i].show();
	}puts("");*/
	
	int s;
	cin>>s;
	s=s-1;
	p[s].Isbad=true;
	int badnum=1;
	list<int> l;
	list<int>::iterator it;
	
while(badnum!=0){
	--badnum;
	for(i=0;i<n;i++){
		if(p[s].check(p[i])&&p[i].Isbad==false){
			p[i].Isbad=true;
			l.push_back(i);
			badnum++;
		}
	}
	if(!l.empty()){
			s=l.front();
			l.pop_front();
		}
	
}
	/*for(i=0;i<n;i++){
		cout<<"Staff: "<<i+1<<"  ";
		p[i].show();
	}puts("");*/

	
	int sum=0;
	for(i=0;i<n;i++){
		if(p[i].Isbad)++sum;
	}
	//cout<<"¦h¤Ö¤H§åµû: "<<sum;
	cout<<sum;
	return 0;
}
