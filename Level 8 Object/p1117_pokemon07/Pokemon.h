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
	void operator>>(Pokemon &Tg);
	
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
	PokemonHealthCenter(string na);//�]�w���_�_�����ߪ��W�r
	void Cure(Pokemon &p);
	void operator<<(Pokemon &Tg);
	//�N�ǤJ�����_�_���^�_����
	//�æL�X�b�uxx���_�_�����ߡv��_
private:
	string Name;
};
typedef PokemonHealthCenter PC;
