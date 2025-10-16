#include <iostream>
#include<string>

using namespace std;
class Pokemon
{
public:
    Pokemon();
    Pokemon(string name,int lv,int hp);
 	string Name;
 	int Lv;
 	int HpMax;	
 	int HpCur;
	void ShowInfo();
	void Attack(Pokemon &Target);
	void Defence(int n);
	void Cure();
	void setData(string name, int lv, int hp);
	~Pokemon();
};
