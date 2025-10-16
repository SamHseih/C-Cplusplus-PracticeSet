#include<iostream>
#include<list>
using namespace std;

void factor(int n,list<int> &lst);
char prime(int n);
void printList(list<int> &lst);
int main() {
	int value,i;
	list<int> l;
	list<int>::iterator it;
	cin>>value;
	factor(value,l);
	while(true) {
		cin>>i;
		switch(i) {
			case 1: {
				printList(l);
				break;
			}
			case 2: {
				l.reverse();
				printList(l);
				l.reverse();
				break;
			}
			case 3: {
				return 0;
				break;
			}
		}
	}
}
void factor(int n,list<int> &lst) {  //�P�_�]�ƨå[�Jlist 
	int i;
	list<int>::iterator it;
	cout<<"n: "<<n<<endl;
	cout<<"factors: ";
	for(i=1; i<=n; i++) {
		if(n%i==0) {
			lst.push_back(i);
			cout<<i;
			if(i!=n)cout<<", ";
		}
	}
	cout<<endl;
}
char prime(int n) {   //�P�_�O�_��Ʀ^��Y or N 
	int i,count=0;
	if(n==1)return 'N';
	for(i=2; i<=n; i++) {
		if(n%i==0) {
			count++;
			if(count==2)return 'N';
		}
	}
	return 'P';
}

void printList(list<int> &lst) {  //�C�L 
	list<int>::iterator it;
	if(lst.size()>0) {
		for(it=lst.begin();it!=lst.end(); it++) {
			cout<< *it<<" "<<prime(*it)<<endl;;
		}
	}
}

