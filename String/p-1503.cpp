#include<iostream>
#include<string>
#include<string.h>
using namespace std;


int main() {
	int a=0,b=0;
	int i;
	string gus;
	string ans;
	cin>>ans>>gus;
	int check[ans.size()]= {0};
	int find=1;
	int from=0;
	 {//0123 4 5 6 7 8  index
     //1a2b 3 3 2 3 3  ans
     //1a2b 2 3 3 3 2  gus
     //1111 1 1 1 0 0  check
	// AAAA	B A B A    6A2B
	
	//0123  index
	//1231  ans
	//2217	gus
	//0000	check
	// AB	1A1B
}
	
	for(string::size_type index=0; index!=ans.size(); ++index) { //size_type�o�O�@�Ӯe��(���A)�˪��O�r�ꪺsize   //https://www.796t.com/content/1544290802.html
		//cout<<"Index"<<index<<endl;
		if(ans[index]==gus[index]) { //��m���Ta++ 
			++a;
			++check[index];
		} 
		else {
			while(find!=ans.npos) {  //��find������ �����j�� 
				//cout<<"from: "<<from<<endl;		
				find=ans.find(gus[index],from);  //�qans string ��from��m�}�l��M  
				
				/*if(find!=ans.npos){   
					cout<<"find: "<<find<<endl;	
				}*/ 
				if(ans[find]==gus[find]){ //��Mb���L�{��, ��쥻���H�t��L��A ���L�A�B����from 
				from=find+1; 
				continue;
				}
				else if(check[find]==0) {  //���Q�ˬd�L�B���|����A 
					//cout<<"here"<<endl; 
					++check[find];
					from=0;
					++b;
					break;
				}
				else {	//��MB�L�{���A�S������A���O�Q�ק�L�� 
					from=find+1;
					//cout<<"���"<<endl;
				}
			}
			find=1; //����U���L�k�i�J�j�� 
		}
	}
	cout<<a<<"A"<<b<<"B";
}
