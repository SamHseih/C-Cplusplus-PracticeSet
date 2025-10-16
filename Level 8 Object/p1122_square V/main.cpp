#include<iostream>
#include "square.h"
using namespace std;
 
int main()
{
    int n1,n2;
    cin >> n1 >> n2;
    Square s1(n1),s2(n2);
 
    cout << "s1 len=" << s1.getLen() << ", area="<<s1.area()<<endl;
    cout << "s2 len=" << s2.getLen() << ", area="<<s2.area()<<endl;
 
    if(cmpSquare(s1,s2)>0)
        cout << "1>2" << endl;
    else if(cmpSquare(s1,s2)==0)
        cout << "1==2" << endl;
    else// if(cmpSquare(s1,s2)<0)
        cout << "1<2" << endl;
 
    for(int i=0;i<450000000;i++)
        cmpSquare(s1,s2);
 
    return 0;
}
