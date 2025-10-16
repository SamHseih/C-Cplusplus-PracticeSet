#include <iostream>
#include "Pokemon.h"
 
using namespace std;
 
int main()
{
 
    string name;
    int lv, hp;
 
    cin >> name >> lv >> hp;
    Pokemon *p1 = new Pokemon(name,lv,hp);
    p1->ShowInfo();
    delete p1;
 
    cin >> name >> lv >> hp;
    Pokemon p2(name,lv,hp);
 
    Pokemon p3;   
 
    p2.ShowInfo();
    p3.ShowInfo();
 
    return 0;
}
