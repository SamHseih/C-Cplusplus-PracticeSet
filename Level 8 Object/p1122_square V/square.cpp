#include<iostream>
#include "square.h"
using namespace std;
Square::Square(){
len=0;
}
Square::Square(int n){
	if(n<1){
		cout<<"len setting error"<<endl;
		len=1;
		Area=1*1;
	}
	else {
	len=n;
	Area=n*n;
	}
}
int Square::area(){
	return Area; 
}
void Square::setLen(int n){	
	if(n<1){
		cout<<"len setting error"<<endl;
		len=1;
	}
	else len=n;
}
int Square::getLen(){
	return len;	
}
int cmpSquare(Square &q1, Square &q2){
	
	if(q1.Area<q2.Area){
		return -1;//cout<<"1<2";
	}
	else if(q1.Area==q2.Area){
		return 0;//cout<<"1==2";
	}
	else return 1;//cout<<"1>2";
}
