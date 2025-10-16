#include<iostream>
#include<string>
using namespace std;
int main(){
	string s, result_str;
	cout << "輸入一包含標點符號的字串:";
	cin >> s;
	char ch;
	bool has_punct = false; //判斷是否有標點符號
	for(string::size_type index = 0; index != s.size(); ++index){ //size_type這是一個容器(型態)裝的是字串的size   //https://www.796t.com/content/1544290802.html
		ch = s[index];
		if(ispunct(ch))
			has_punct = true;  //有標點符號且不疊加到結果中 
		else
			result_str+=ch;   // 把字母疊加到結果中 
	}
	if(has_punct){
		cout << "移除標點符號後:" << result_str << endl;
	}
	else{
		cout << "輸入的字串沒有標點符號!!" << endl;
	}
	return 0;
}
