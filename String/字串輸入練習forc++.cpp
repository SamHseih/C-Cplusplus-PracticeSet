#include<iostream>
#include<string>
using namespace std;


int main() {
	{//1. cin �d��
		/*char s1;
		string s2;
		cin>>s1>>s2;
		cout<<s1<<endl<<s2;*/
	}
	{//2. cin.get()�d��
		/*char c;
		while(true)
		{
		    c = cin.get();
		    cout << "�o��r��[" << c << "]  ASCII�s�� [" << (int)c << "]" << endl;
		}*/
	}
	{//3. cin.getline()�d��
	/*	char s1[100];
	    while(true)
	    {
	        cin.getline(s1,101);
	        cout << "�o��: " << s1 << endl;
	    }*/
	}
	{//4. getline()�d��
	/*	string str;
		getline(cin,str);
		cout<<"str= "<<str<<endl;*/
	}
	{//5. cin �P getline ������! 
/*1�Bcin.getline()�ݩ�istream�y�A��getline()�ݩ�string�y�A�O���@�˪���Ө禡
  2�B��"�P��"�ϥ� cin>>, getline()�ɡA�ݭn�`�N���O�A�bcin>>��J��������Agetline()���e�A�ݭn�q�L
		str=��\n��;
		getline(cin,str);
���覡�Nreturn�@����J�ycin�H�M���֨��A�p�G���o�˰����ܡA�b�����i�W�N���|�X�{getline()����J���ܡA�Ӫ������L�A�]���{���w�]�a�N���e���ܼƧ@����J�y�C*/
	/*	int age;
    //standard input(cin)
    cout<<"Please enter an integer value as your age:";
    cin>>age;  
    cout<<"Your ager is: "<<age<<".\n";
    //cin and string
    string mystr;
    cout<<"What��s your name?"<<endl;
   	mystr="\n";		//�M���֨��ʧ@ 
    getline(cin,mystr);   //�M���֨��ʧ@ 
    
	getline(cin,mystr); //�Y�֤F�H�W��Ӱʧ@�A����N�|�Q�۰ʩ��� 
    cout<<"Hello,"<<mystr<<".\n";
    char sex;
    cout<<"Please enter a F or M as your sex: ";
    cin>>sex;
    cout<<"Your sex is: "<<sex<<endl;
    cout<<"What��s your favorite team? ";
    mystr="\n";		//�M���֨��ʧ@
    getline(cin,mystr);	//�M���֨��ʧ@
    
	getline(cin,mystr);   //�Y�֤F�H�W��Ӱʧ@�A����N�|�Q�۰ʩ��� 
    cout<<"I like "<<mystr<<".\n";

    system("pause");
    return 0;*/ 
	}
		
	/*string a;
	cin>>a;
	if(a=="-1"){ //�r��!= �n�Τ�r""  
		cout<<"HAHA";
	}
	else cout<<a;
*/
}


