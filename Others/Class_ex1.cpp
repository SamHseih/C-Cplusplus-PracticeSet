#include <iostream>
#include <string>
using namespace std;
class Person
{
public:

Person(){
	name={"NO name"};
	height=0;
	weight=0;
}

void input()
{  
cin>>name; //gets(name);  cin.getline(�����r�Ŧꪺ�ܼ�,�����r�ŭӼ�,�����r��) 
cin >> height; //scanf("%d",&height);
cin >> weight; //scanf("%d",&weight);
cin.ignore(); //fflush(stdin); ����W������J�|�z�Z��U������J!!! 
}
void output()
{
cout << "Name:" << name << endl;
cout << "Height:" << height << " cm" << endl;
cout << "Weight:" << weight << " kg" << endl;
}

string name;
int height;
int weight;
};


int main(){
	Person p1,p2;
	
	p1.input();
	p2.input();
	
	p1.output();
	p2.output();
	
	p1.name.empty();


}
