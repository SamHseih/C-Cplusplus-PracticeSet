#include<iostream>
#include<string>
using namespace std;
int main(){
	string s, result_str;
	cout << "��J�@�]�t���I�Ÿ����r��:";
	cin >> s;
	char ch;
	bool has_punct = false; //�P�_�O�_�����I�Ÿ�
	for(string::size_type index = 0; index != s.size(); ++index){ //size_type�o�O�@�Ӯe��(���A)�˪��O�r�ꪺsize   //https://www.796t.com/content/1544290802.html
		ch = s[index];
		if(ispunct(ch))
			has_punct = true;  //�����I�Ÿ��B���|�[�쵲�G�� 
		else
			result_str+=ch;   // ��r���|�[�쵲�G�� 
	}
	if(has_punct){
		cout << "�������I�Ÿ���:" << result_str << endl;
	}
	else{
		cout << "��J���r��S�����I�Ÿ�!!" << endl;
	}
	return 0;
}
