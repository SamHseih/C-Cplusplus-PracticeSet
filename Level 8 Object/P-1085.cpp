#include<iostream>
#include<string>
using namespace std;

	
	class Data{
		public:
			string scientific_name;
    		int number;
	};
	
	class Animal{
		public:
			Animal();
			void add(Data x);
			void update(Data x);
			void display();
			
		private:
			Data Animal_list[500];//�i�H���]�ʪ����������|�W�L500�ءC
			int type;// �ثeAnimal_list �ح����ʪ��ƶq�C
			int Endanger_number; // �ثe�x�{���ت��ʪ��������ƶq�C
	};
	
	Animal::Animal(){
		int i;	for(i=0;i<500;i++)Animal_list[i].number=0;
		type=0; 
		Endanger_number=0;
		}
		
	void Animal::add(Data x){
		Animal_list[type]=x;
		cout<<"Add. Animal: "<<Animal_list[type].scientific_name<<"."<<endl;
		cout<<"Number: "<<Animal_list[type].number<<endl;
		if(x.number<1000){
			++Endanger_number;
			cout<<"Endanger species: Yes"<<endl;
		}
		else cout<<"Endanger species: No"<<endl;
		++type;
	}
	
	void Animal::update(Data x){
		int i=0,flag=0;
		for(i=0;i<type;i++){
			if(x.scientific_name.compare(Animal_list[i].scientific_name)==0){
				if(	Animal_list[i].number<1000)flag++;
			Animal_list[i].number=x.number;
			break;}
			}
		cout<<"Update. Animal: "<<Animal_list[i].scientific_name<<"."<<endl;
		cout<<"Number: "<<Animal_list[i].number<<endl;
		if(x.number<1000){
			if(flag==0)++Endanger_number;
			cout<<"Endanger species: Yes"<<endl;
		}
		else {
			if(flag==1)--Endanger_number;
			cout<<"Endanger species: No"<<endl;
		}
	}
	
	void  Animal::display(){
		int i,flag=0;
		for(i=0;i<type;i++){
			if(flag==0){
				cout<<"There are "<<Endanger_number<<" animals who are endanger species"<<endl;
				flag++;}
			if(Animal_list[i].number<1000){
				cout<<"Animal: "<<Animal_list[i].scientific_name<<"."<<endl;
				cout<<"Number: "<<Animal_list[i].number<<endl;
			}
		}
	}
	
int main(){
	Data input;
	string x; int n;
	Animal Global;
	char a='z';
	while(a!='q'){
		//cout<<"a �[�J u��s d�C�X q���}"<<endl<<endl; 
		cin>>a;
		cin.ignore();
		switch(a){
			case 'a':{
				getline(cin,x);
				cin>>n;  //�M�ſ�J�Ȧs��\n 
				cin.ignore();
				input.scientific_name=x;	input.number=n;
				Global.add(input);
				break;
			}
			case 'u':{
				getline(cin,x);
				cin>>n;  //�M�ſ�J�Ȧs��\n 
				cin.ignore();
				input.scientific_name=x;	input.number=n;
				Global.update(input);
				break;
			}
			case 'd':{
				Global.display();
				break;
			}
			case 'q':{
				break;
			}
		}
	}
	cout<<"That are the endanger animal list we have now. Bye bye.";
}
