#include <iostream>
#include "Pokemon.h"
 
using namespace std;
 
int main()
{
    string Name, Item;
    int lv, hp;
 
    cin >> Name >> lv >> hp;
    Pokemon *p = new Pokemon(Name,lv,hp);
    cin >> Item;
    p->addItem(Item);
    cin >> Item;
    p->addItem(Item);
    cin >> Item;
    p->addItem(Item);
    p->ShowInfo();  
    delete p;  
    cin >> Name >> lv >> hp;
    Pokemon p1(Name,lv,hp);
    cin >> Item;
    p1.addItem(Item);
    cin >> Item;
    p1.addItem(Item);
    cin >> Item;
    p1.addItem(Item);   
    p1.ShowInfo();
 
    return 0;
}
