#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	string a;
	map<string,string> dict;
	map<string,string>::iterator it;
	dict["P"]="Pikachu";
	dict["M"]="Mickey Mouse";
	dict["H"]="Hello kitty";

	while(true){
		cin>>a;
		if(a=="-1") break;
		if(a=="-2"){
			for(it=dict.begin();it!=dict.end();it++){
				cout << "dict['" << (*it).first << "\'] is " << (*it).second << endl;
			}continue;
		}
		if(a=="-3"){
			cout<<"��J�n�R�����r: ";
			cin>>a;
			if(dict.count(a)==1){
				it=dict.find(a);
				dict.erase(it);
				continue;
			}
			else{
				cout<<"key does not exist."<<endl;
				continue;
			}
		}
		if(dict.count(a)==1) {
			it=dict.find(a);  //find ����^�ǫ���
			cout<<(*it).second<< endl;
		} 
		else {
			string st;
			cout<<a<<" does not exist. Enter a new one:"<<endl;
			cin.ignore(); //�M�żȦs��
			getline(cin,st);
			dict[a]=st;
		}
}

	/*	for (it = dict.begin(); it != dict.end(); it++) {
	cout << "m['" << (*it).first << "\'] is " << (*it).second << endl;
	}
	cout << "m now contains " << dict.size() << " elements." << endl;*/
	return 0;
}
