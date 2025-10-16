#include<iostream>
#include<string>
#include<string.h>
#include<list>
using namespace std;

class stack{
	public:
		stack();
		void push(char input);
		char pop();
		void show();
		bool Isempty();
		char Top();
		char type(char x);
	private:
		list<char> s;
		list<char>::iterator top;
		int size;
};

stack::stack(){
	size=0;
}

void stack::push(char input){
	s.push_front(input);
	top=s.begin();
	size++;
}
char stack::pop(){
	if(top==s.end()){
		//cout<<"Empty stack,please push data."<<endl;
		return '\0';
	}
	else {
	char output;
	output=s.front();
	top++;                  //�ܭ��n!!!!!!!!!!!!!!!!!!!!!!!! top++���i�H�Apop.front�᭱�A���M���з|�ö]�C 
	s.pop_front();
	
	size--;
	return output;
	}
}

bool stack::Isempty(){   // �^��1 �Ū�  �^��0 �٦� 
	if(s.empty())return 1;
	return 0;
}

void stack::show(){
		for(top=s.begin();top!=s.end();top++){
			cout<<*top<<" ";
		}cout<<endl;
	}

char stack::Top(){
	if(!s.empty())return s.front();
	else return '\0';
}

char stack::type(char x){
	switch(x){
			case '(':{return 'a';}
			case ')':{return 'a';}
			case '[':{return 'b';}
			case ']':{return 'b';}
			case '{':{return 'c';}
			case '}':{return 'c';}
			case '<':{return 'd';}
			case '>':{return 'd';}
			}
		return '\0';
}

char check(string input){
	stack s;
	char next='\0'; 
	char top_type='\0';
	int	a=0,b=0,c=0,d=0;
		for(string::size_type index=0;index!=input.size();++index){   //�ѥ��ӥk���y 
		//���y�� 
			next=input[index];
			switch(next){
			case '(':{a++;  s.push(next);  top_type='a';break;}
			case ')':{if(top_type=='a'&&a>0){a--;s.pop();top_type=s.type(s.Top());break;}else{return 'N';}}
	
			case '[':{b++;  s.push(next);  top_type='b';break;}
			case ']':{if(top_type=='b'&&b>0){b--;s.pop();top_type=s.type(s.Top());break;}else{return 'N';}}
			
			case '{':{c++;  s.push(next);  top_type='c';break;}
			case '}':{if(top_type=='c'&&c>0){c--;s.pop();top_type=s.type(s.Top());break;}else{return 'N';}}
			
			case '<':{d++;  s.push(next);  top_type='d';break;}
			case '>':{if(top_type=='d'&&d>0){d--;s.pop();top_type=s.type(s.Top());break;}else{return 'N';}}
			default:{break;}
			}
		/*cout<<"Scan: "<<input[index]<<"  ";
		cout<<"Type: "<<top_type<<"  ";
		cout<<"a: "<<a<<"  ";
		cout<<"b: "<<b<<"  ";
		cout<<"c: "<<c<<"  ";
		cout<<"d: "<<d<<endl;*/
		}
		//���y���� 
		if(s.Isempty()==1&&a==0&&b==0&&c==0&&d==0)return 'Y';
		else return 'N';
	
}

int main(){
	int n,i,j;
	int a=0,b=0,c=0,d=0; // a() b[] c{} d<>
	cin>>n;
	string *s=new string[n];
	cin.ignore();
	for(i=0;i<n;i++){
	getline(cin,s[i]);
	}
	for(i=0;i<n;i++){
		cout<<check(s[i])<<endl;
	}
	

	return 0;
}
