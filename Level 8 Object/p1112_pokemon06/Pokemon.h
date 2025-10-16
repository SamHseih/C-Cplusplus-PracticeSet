#include <iostream>
#include<string>

using namespace std;
class Pokemon
{
friend class PokemonHealthCenter;
public:
    Pokemon();
    Pokemon(string name,int lv,int hp);
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
};

class PokemonHealthCenter
{
public:
	PokemonHealthCenter(string na);//設定神奇寶貝中心的名字
	void Cure(Pokemon &p);
	//將傳入的神奇寶貝回復滿血
	//並印出在「xx神奇寶貝中心」恢復
private:
	string Name;
};
typedef PokemonHealthCenter PC;
