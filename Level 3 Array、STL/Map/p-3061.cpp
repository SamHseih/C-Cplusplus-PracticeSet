#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	
	char a;
	map<char,string> dict;
	map<char,string>::iterator it;
		dict['P']="Pikachu";
		dict['M']="Mickey Mouse";
		dict['H']="Hello kitty";
	cin>>a;
	it=dict.find(a);
	cout<<(*it).second<< endl;
/*	for (it = dict.begin(); it != dict.end(); it++) {	
cout << "m['" << (*it).first << "\'] is " << (*it).second << endl;
}
cout << "m now contains " << dict.size() << " elements." << endl;*/
return 0;
}
