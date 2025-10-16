#include "Pokemon.h"
using namespace std;
void Pokemon::ShowInfo(){
    cout<<"Name: "<<Name<<endl;
    cout<<"Lv: "<<Lv<<endl;
    cout<<"HP: "<<HpCur<<"/"<<HpMax<<endl<<endl;
}

void Pokemon::Attack(Pokemon &Target){
	Target.HpCur=Target.HpCur-Lv;
	cout<<Name<<" Attack "<<Target.Name<<" "<<Lv<<" Points."<<endl;//Mewtwo Attack Pikachu 30 Points.
}
void Defence( int atkp ){
		
	}
void Pokemon::Cure(){
	HpCur=HpMax;
	cout<<Name<<" has restore health."<<endl;	
	}
