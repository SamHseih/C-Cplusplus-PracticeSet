#include<iostream>
#include<list>
#include<algorithm> ///�d�U���n�γo��sort �Plinklist ���ۮe 
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
	//���ϥΪ̿�J�@�ƦC�A�Happend�[�Jlist��(-1�����Alist�����t-1)
	while(n!=-1) {
		if(n==-1)break;
		l.push_back(n);
		cin>>n;
	}
	//�N��Ѥp��j�Ƨǫ�L�X
	l.sort();
	printList(l);
	//cout<<"�b�ĥ|�Ӧ�m���J�@���10��L�X(��m��1�_��)"<<endl;
	it=l.begin();
	for(i=0; i<3; ++i) {
		it++;
	}
	l.insert(it,10);
	printList(l);
	//�L�Xlist�����X�Ӿ��10
	/*int count_1;
	count_1=count(l.begin(),l.end(),10);
	cout<<count_1<<endl;*/ //���q����U�������@��Y�i 
	 cout<<count(l.begin(),l.end(),10)<<endl;
	//�N��Ѥj��p�Ƨǫ�L�X
	l.sort();
	l.reverse();
	printList(l);
}


