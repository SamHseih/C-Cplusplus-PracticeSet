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
	//���ϥΪ̿�J�@�ƦC�A�Happend�[�Jlist��(-1�����Alist�����t-1)
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
	//1.�N��Ѥp��j�Ƨǫ�L�X
	l.sort();
	printList(l);
	//2.�p�����
	cout<<l.size()<<endl;
	//3.�p��[�`
	float sum=0;
	it=l.begin();
	while(it!=l.end()){
		sum=sum+(*it);
		it++;
	}
	cout<<sum<<endl;
	//4.�p�⥭��(�L��p���I��2��)   //http://it-easy.tw/cout-float/ �����Ʊо� 
	cout<<fixed<<setprecision(2)<<sum/l.size()<<endl;
	//5.�p��̤j�ȻP���m (�q1�_��A�Y���ۦP���A�H���ޭȤp������)
	cout<<max<<"@"<<maxp<<endl;
	//6.�p��̤p�ȻP���m (�q1�_��A�Y���ۦP���A�H���ޭȤp������)
	cout<<min<<"@"<<minp<<endl;
	//7.�L�X�쥻���g�ƧǪ�list
	printList(original);
}
