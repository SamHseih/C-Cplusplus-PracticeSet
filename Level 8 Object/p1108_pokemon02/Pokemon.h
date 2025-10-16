#include <iostream>
#include<string>
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
	void Defence( int atkp );
	void Cure();
};
