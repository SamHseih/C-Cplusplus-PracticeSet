#include <iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


struct Pokemon {
	char Name[128];
	int Lv;
	int Hp;
};


bool pkmNameCmp(Pokemon x, Pokemon y) {
	return strcmp(x.Name,y.Name)<0;
}
bool pkmLvCmp(Pokemon x, Pokemon y) {
	return x.Lv<y.Lv;
}
bool pkmHpCmp(Pokemon x, Pokemon y) {
	return x.Hp<y.Hp;
}

void print(Pokemon p){
				cout<<"Name: "<<p.Name<<endl;
				cout<<"Lv: "<<p.Lv<<endl;
				cout<<"HP: "<<p.Hp<<endl<<endl;
			
}

int main() {
	
	Pokemon p;
	char s[128];
	int i,lv,hp,n,k;
	vector<Pokemon> v;
	vector<Pokemon>::iterator it;
	it=v.begin();
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>s>>lv>>hp;
		strcpy(p.Name,s);
		p.Lv=lv;
		p.Hp=hp;
		v.push_back(p);
	}
	cin>>k;
	switch(k) {
		case 0: {
			for_each(v.begin(),v.end(),print);
			/*for ( it = v.begin( ); it != v.end( ) ; it++) {
				cout<<"Name: "<<it->Name<<endl;
				cout<<"Lv: "<<it->Lv<<endl;
				cout<<"HP: "<<it->Hp<<endl<<endl;*/  //已經縮短成一行 
			break;
		}
		case 1: {
			sort(v.begin(),v.end(),pkmNameCmp);
			for_each(v.begin(),v.end(),print);
			break;
			} 
		
		case 2: {
			sort(v.begin(),v.end(),pkmLvCmp);
			for_each(v.begin(),v.end(),print);
			break;
		}
		case 3: {
			sort(v.begin(),v.end(),pkmHpCmp);
			for_each(v.begin(),v.end(),print);
			break;
		}
	}
	
	return 0;
}
