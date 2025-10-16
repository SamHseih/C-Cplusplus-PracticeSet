#include <iostream>
#include<string>

using namespace std;
class Pokemon
{
public:
    Pokemon();
    Pokemon(string name,int lv,int hp);
	void addItem(string item);
	void ShowInfo();
	void Attack(Pokemon &Target);
	void Defence(int n);
	void Cure();
	~Pokemon();
	
	private:
	void setData(string name, int lv, int hp);	
	string Name;
 	int Lv;
 	int HpMax;	
 	int HpCur;
    string *items;
    int itemNum;
 	
};
