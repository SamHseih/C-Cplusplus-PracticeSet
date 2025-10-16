#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Pokemon
{
public:
    
 	string Name;
 	int Lv;
 	int HpMax;	
 	int HpCur;
	void ShowInfo();
	void Attack(Pokemon &Target);
	void Defence(int n);
	void Cure();
	void setData(string name, int lv, int hp);
};
void Pokemon::ShowInfo(){
    cout<<"Name: "<<Name<<endl;
    cout<<"Lv: "<<Lv<<endl;
    cout<<"HP: "<<HpCur<<"/"<<HpMax<<endl;
}
void Pokemon::Attack(Pokemon &Target){
	if(HpCur==0){
		//cout<<Name<<" is unable to attack."<<endl;
	}
	else if(Target.HpCur==0){
		//cout<<Name<<" cannot attack fainted target "<<Target.Name<<"."<<endl;
	}
	else{
		if(Target.HpCur>Lv){
		Target.HpCur=Target.HpCur-Lv;
		cout<<Name<<" Attack "<<Target.Name<<" "<<Lv<<" Points."<<endl;//Mewtwo Attack Pikachu 30 Points.	
		}
		else {
			if(Target.HpCur>0)cout<<Name<<" Attack "<<Target.Name<<" "<<Lv<<" Points."<<endl;
			Target.HpCur=0;
			cout<<Target.Name<<" Seriously Injured."<<endl;
			cout<<Name<<" Win, "<<Target.Name<<" Lose."<<endl;
			cout<<Target.Name<<" is unable to attack."<<endl;
		}
		
	}
	
}
void Pokemon::Defence( int n ){
		if(n>HpCur)cout<<Name<<" is fainted."<<endl;
	}
void Pokemon::Cure(){
	HpCur=HpMax;
	//cout<<Name<<" has restore health."<<endl;	
	}
void Pokemon::setData(string name, int lv, int hp){
	char ch;
	bool has_punct = false; 
	for(string::size_type index=0;index!=name.size();++index){ //size_type這是一個容器(型態)裝的是字串的size   //https://www.796t.com/content/1544290802.html
		ch = name[index];
		if(ispunct(ch)){//判斷是否有標點符號
		has_punct = true; } //有標點符號且不疊加到結果中 
	}
	if(name.size()==0){cout<<"Name can't be empty."<<endl;}
	else if(has_punct==true)cout<<"Name can't be empty."<<endl;
	else Name=name;
	if(lv<1){
		cout<<"Lv setting error."<<endl;
		Lv=1;
	}
	else Lv=lv;
	if(hp<1){
		cout<<"Hp setting error."<<endl;
		HpCur=HpMax=1;
	}
	else HpCur=HpMax=hp;
}

int main()
{	
	string name;
	int i,n,lv,hp;
	cin>>n;
    Pokemon npc;
    npc.Name="Mewtwo";
    npc.HpCur=npc.HpMax=300;
    npc.Lv=30;
	Pokemon p[n];
    for(i=0;i<n;i++){
    	cin>>name>>lv>>hp;
    	p[i].setData(name,lv,hp);
	}
	
for(i=0;i<n;i++){
	cout<<"#"<<i+1<<endl;
	while(npc.HpCur!=0&&p[i].HpCur!=0){
		p[i].Attack(npc);
		npc.Attack(p[i]);
	}
	npc.ShowInfo();
	p[i].ShowInfo();
	npc.Cure();
	cout<<endl;
}
    return 0;
}
