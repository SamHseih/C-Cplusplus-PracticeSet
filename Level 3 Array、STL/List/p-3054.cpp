#include<iostream>
#include<list>
#include<algorithm>
#include<iomanip>
using namespace std;

template <class T>
void printList(list<T> &lst) {
	class list<T>::iterator it;
	cout << "[";
	if(lst.size()>0) {
		it=lst.begin();
		cout <<*it;
		it++;
		for(; it!=lst.end(); it++) {
			cout << ", "<< *it  ;
		}
	}
	cout << "]\n";
}

int main(){
	
	list<int> l;
	list<int>::iterator it;
	list<int> original;
	int n,max,min;
	int maxp,minp,i=1,flag=0;
	cin>>n;
	max=n;
	min=n; 
	//讓使用者輸入一數列，以append加入list當中(-1結束，list中不含-1)
	while(n!=-1) {
		if(n==-1)break;
		l.push_back(n);
		
		if(n>max&&n!=-1)max=n; //5.
		if(n<min&&n!=-1)min=n; //6.
		cin>>n;
	}
	original=l;
	for(it=l.begin();it!=l.end();it++){ 
		if(*it==max&&flag==0){maxp=i;flag=1;}//5.
		i++;
	}
	flag=0;i=1;
	for(it=l.begin();it!=l.end();it++){ 
		if(*it==min&&flag==0){minp=i;flag=1;}//6.
		i++;
	}
	//1.將其由小到大排序後印出
	l.sort();
	printList(l);
	//2.計算長度
	cout<<l.size()<<endl;
	//3.計算加總
	float sum=0;
	it=l.begin();
	while(it!=l.end()){
		sum=sum+(*it);
		it++;
	}
	cout<<sum<<endl;
	//4.計算平均(印到小數點後2位)   //http://it-easy.tw/cout-float/ 控制位數教學 
	cout<<fixed<<setprecision(2)<<sum/l.size()<<endl;
	//5.計算最大值與其位置 (從1起算，若有相同的，以索引值小的為準)
	cout<<max<<"@"<<maxp<<endl;
	//6.計算最小值與其位置 (從1起算，若有相同的，以索引值小的為準)
	cout<<min<<"@"<<minp<<endl;
	//7.印出原本未經排序的list
	printList(original);
}
