#include<iostream>
#include<list>
#include<algorithm> ///千萬不要用這個sort 與linklist 不相容 
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


int main() {
	int i;
	list<int> l;
	list<int>::iterator it;

	int n;
	cin>>n; 
	//讓使用者輸入一數列，以append加入list當中(-1結束，list中不含-1)
	while(n!=-1) {
		if(n==-1)break;
		l.push_back(n);
		cin>>n;
	}
	//將其由小到大排序後印出
	l.sort();
	printList(l);
	//cout<<"在第四個位置插入一整數10後印出(位置由1起算)"<<endl;
	it=l.begin();
	for(i=0; i<3; ++i) {
		it++;
	}
	l.insert(it,10);
	printList(l);
	//印出list中有幾個整數10
	/*int count_1;
	count_1=count(l.begin(),l.end(),10);
	cout<<count_1<<endl;*/ //此段等於下面直接一行即可 
	 cout<<count(l.begin(),l.end(),10)<<endl;
	//將其由大到小排序後印出
	l.sort();
	l.reverse();
	printList(l);
}


