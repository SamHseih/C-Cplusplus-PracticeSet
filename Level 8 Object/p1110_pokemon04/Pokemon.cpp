#include "Pokemon.h"
using namespace std;
void Pokemon::ShowInfo(){
    cout<<"Name: "<<Name<<endl;
    cout<<"Lv: "<<Lv<<endl;
    cout<<"HP: "<<HpCur<<"/"<<HpMax<<endl<<endl;
}

Pokemon::Pokemon(){
	Name="No Name";
	Lv=1;
	HpCur=HpMax=1;
}
Pokemon::Pokemon(string name,int lv,int hp){
	setData(name,lv,hp);
}
void Pokemon::Attack(Pokemon &Target){
	if(HpCur==0){
		cout<<Name<<" is unable to attack."<<endl;
	}
	else if(Target.HpCur==0){
		cout<<Name<<" cannot attack fainted target "<<Target.Name<<"."<<endl;
	}
	else{
		if(Target.HpCur>Lv){
		Target.HpCur=Target.HpCur-Lv;
		cout<<Name<<" Attack "<<Target.Name<<" "<<Lv<<" Points."<<endl;//Mewtwo Attack Pikachu 30 Points.	
		}
		else {
			if(Target.HpCur>0)cout<<Name<<" Attack "<<Target.Name<<" "<<Lv<<" Points."<<endl;
			Target.HpCur=0;
			cout<<Target.Name<<" is fainted."<<endl;
		}
		
	}
	
}
void Pokemon::Defence( int n ){
		if(n>HpCur)cout<<Name<<" is fainted."<<endl;
	}
void Pokemon::Cure(){
	HpCur=HpMax;
	cout<<Name<<" has restore health."<<endl;	
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

Pokemon::~Pokemon(){
	cout<<Name<<" has returned to the nature."<<endl;
}

