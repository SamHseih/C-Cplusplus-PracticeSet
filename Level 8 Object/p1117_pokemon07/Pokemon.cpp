#include "Pokemon.h"
using namespace std;
void Pokemon::ShowInfo(){
	int i;
    cout<<"Name: "<<Name<<endl;
    cout<<"Lv: "<<Lv<<endl;
    cout<<"HP: "<<HpCur<<"/"<<HpMax<<endl<<endl;
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
	 cout << Name << " Attack " << Target.Name << " "<< Lv << " Points." << endl;
    Target.Defence(Lv);
	}
}
void Pokemon::Defence(int atkp){
	int defp=0; //���B���m�O�L��
	HpCur-=(atkp-defp);
		if(HpCur<=0){
			cout<<Name<<" is fainted."<<endl;
			HpCur=0;	
		}
	}
void Pokemon::Cure(){
	cout<<Name<<" has restored health at ";	
	}
void Pokemon::setData(string name, int lv, int hp){
	char ch;
	bool has_punct = false; 
	for(string::size_type index=0;index!=name.size();++index){ //size_type�o�O�@�Ӯe��(���A)�˪��O�r�ꪺsize   //https://www.796t.com/content/1544290802.html
		ch = name[index];
		if(ispunct(ch)){//�P�_�O�_�����I�Ÿ�
		has_punct = true; } //�����I�Ÿ��B���|�[�쵲�G�� 
	}
	if(name.size()==0){cout<<"Name can't be empty."<<endl;Name = "No Name"; }
	else if(has_punct==true){cout<<"Name can't be empty."<<endl;Name = "No Name";}
	else Name=name;
	if(lv<1){
		cout<<"Lv setting error."<<endl;
		Lv=1;
	}
	else {
			Lv=lv;
			}
	if(hp<1){
		cout<<"Hp setting error."<<endl;
		HpCur=HpMax=1;
	}
	else HpCur=HpMax=hp;
}
Pokemon::Pokemon(){
	Name="No Name";
	Lv=1;
	HpCur=HpMax=1;
}
Pokemon::~Pokemon(){
	//cout<<Name<<" has returned to the nature."<<endl;	
}
void Pokemon::operator>>(Pokemon &Tg){
	if(HpCur==0){
		cout<<Name<<" is unable to attack."<<endl;
	}
	else if(Tg.HpCur==0){
		cout<<Name<<" cannot attack fainted target "<<Tg.Name<<"."<<endl;
	}
	else{
	 cout << Name << " Attack " << Tg.Name << " "<< Lv << " Points." << endl;
    Tg.Defence(Lv);
	}
}

PokemonHealthCenter::PokemonHealthCenter(string na){
	char ch;
	bool has_punct = false; 
	for(string::size_type index=0;index!=na.size();++index){ //size_type�o�O�@�Ӯe��(���A)�˪��O�r�ꪺsize   //https://www.796t.com/content/1544290802.html
		ch = na[index];
		if(ispunct(ch)){//�P�_�O�_�����I�Ÿ�
		has_punct = true; } //�����I�Ÿ��B���|�[�쵲�G�� 
	}
	if(na.size()==0){cout<<"Name can't be empty."<<endl;}
	else if(has_punct==true)cout<<"Name can't be empty."<<endl;
	else Name=na;
}
void PokemonHealthCenter::Cure(Pokemon &p){	
	p.HpCur=p.HpMax;
	p.Cure();
	cout<<Name<<"."<<endl;
}
void PokemonHealthCenter::operator<<(Pokemon &Tg){
	Tg.HpCur=Tg.HpMax;
	Tg.Cure();
	cout<<Name<<"."<<endl;
}
