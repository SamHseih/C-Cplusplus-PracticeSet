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
	
	for(string::size_type index=0; index!=ans.size(); ++index) { //size_type這是一個容器(型態)裝的是字串的size   //https://www.796t.com/content/1544290802.html
		//cout<<"Index"<<index<<endl;
		if(ans[index]==gus[index]) { //位置正確a++ 
			++a;
			++check[index];
		} 
		else {
			while(find!=ans.npos) {  //當find未找到時 結束迴圈 
				//cout<<"from: "<<from<<endl;		
				find=ans.find(gus[index],from);  //從ans string 的from位置開始找尋  
				
				/*if(find!=ans.npos){   
					cout<<"find: "<<find<<endl;	
				}*/ 
				if(ans[find]==gus[find]){ //找尋b的過程中, 找到本身以配對過的A 跳過，且改變from 
				from=find+1; 
				continue;
				}
				else if(check[find]==0) {  //未被檢查過且不會撞到A 
					//cout<<"here"<<endl; 
					++check[find];
					from=0;
					++b;
					break;
				}
				else {	//找尋B過程中，沒有撞到A但是被修改過的 
					from=find+1;
					//cout<<"近來"<<endl;
				}
			}
			find=1; //防止下次無法進入迴圈 
		}
	}
	cout<<a<<"A"<<b<<"B";
}
