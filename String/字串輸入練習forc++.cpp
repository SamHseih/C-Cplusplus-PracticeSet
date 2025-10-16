#include<iostream>
#include<string>
using namespace std;


int main() {
	{//1. cin 範例
		/*char s1;
		string s2;
		cin>>s1>>s2;
		cout<<s1<<endl<<s2;*/
	}
	{//2. cin.get()範例
		/*char c;
		while(true)
		{
		    c = cin.get();
		    cout << "得到字元[" << c << "]  ASCII編號 [" << (int)c << "]" << endl;
		}*/
	}
	{//3. cin.getline()範例
	/*	char s1[100];
	    while(true)
	    {
	        cin.getline(s1,101);
	        cout << "得到: " << s1 << endl;
	    }*/
	}
	{//4. getline()範例
	/*	string str;
		getline(cin,str);
		cout<<"str= "<<str<<endl;*/
	}
	{//5. cin 與 getline 的切換! 
/*1、cin.getline()屬於istream流，而getline()屬於string流，是不一樣的兩個函式
  2、當"同時"使用 cin>>, getline()時，需要注意的是，在cin>>輸入完成之後，getline()之前，需要通過
		str=”\n”;
		getline(cin,str);
的方式將return作為輸入流cin以清除快取，如果不這樣做的話，在控制檯上就不會出現getline()的輸入提示，而直接跳過，因為程式預設地將之前的變數作為輸入流。*/
	/*	int age;
    //standard input(cin)
    cout<<"Please enter an integer value as your age:";
    cin>>age;  
    cout<<"Your ager is: "<<age<<".\n";
    //cin and string
    string mystr;
    cout<<"What’s your name?"<<endl;
   	mystr="\n";		//清除快取動作 
    getline(cin,mystr);   //清除快取動作 
    
	getline(cin,mystr); //若少了以上兩個動作，此行將會被自動忽略 
    cout<<"Hello,"<<mystr<<".\n";
    char sex;
    cout<<"Please enter a F or M as your sex: ";
    cin>>sex;
    cout<<"Your sex is: "<<sex<<endl;
    cout<<"What’s your favorite team? ";
    mystr="\n";		//清除快取動作
    getline(cin,mystr);	//清除快取動作
    
	getline(cin,mystr);   //若少了以上兩個動作，此行將會被自動忽略 
    cout<<"I like "<<mystr<<".\n";

    system("pause");
    return 0;*/ 
	}
		
	/*string a;
	cin>>a;
	if(a=="-1"){ //字串!= 要用文字""  
		cout<<"HAHA";
	}
	else cout<<a;
*/
}


