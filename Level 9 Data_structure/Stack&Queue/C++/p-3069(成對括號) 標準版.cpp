#include <iostream>
#include<stack>
#include <cstdlib>
#include <string>
using namespace std;
 
int main()
{
//    stack<char> c;
//    string s;
//    int n;
//    cin>>n;
//    cin.ignore();
//    bool a;
//    for(int i=0,a=false;i<n;i++){
//        int k=0,l=0,j=0,f[100]={0},g=0;
//        getline(cin,s);
//        while(j<s.size()){
//            if(s[j]=='<'||s[j]=='('||s[j]=='['||s[j]=='{'){
//                c.push(s[j]);
//                s[j]=0;
//                a=true;
//            }
//            else if(s[j]!='>'&&s[j]!=')'&&s[j]!=']'&&s[j]!='}')
//                s[j]=0;
//            if(s[j]=='>'||s[j]==')'||s[j]==']'||s[j]=='}'){
//                l++;f[g++]=j;
//                if(c.empty())
//                  break;
//            }
//            j++;
//        }
//        if(c.empty())
//            a=false;
//        else{
//            g--;
//            //j=f[g];
//            while(g>=0){
//                //if(s[j]!=0){
//                    if(abs(s[f[g--]]-c.top())>2){
//                        a=false;
//                        break;
//                    }
//                    else if(j>s.size()){
//                        a=false;
//                        break;
//                    }
//                    else {
//                        c.pop();
//                        s[j]=0;
//                        k++;
//                        //j=f[g--];
//                    }
//
//                //}
//                //else
//                    //j++;
//            }
//            if(k!=l)
//                a=false;
//        }
//        if(a)
//            cout<<'Y'<<endl;
//        else
//            cout<<'N'<<endl;
//        for(int j=0;j<c.size();j++)
//            c.pop();
//    }
    stack<char> c;
    bool a;
    int n,j;
    string s;
    cin>>n;
    cin.ignore();
    while(a=false,j=0,n--){    //默認 N開頭 達到目的在換Y 
        getline(cin,s);
        while(s.size()>j){
            if(s[j]=='<'||s[j]=='('||s[j]=='['||s[j]=='{')
                c.push(s[j]);
            else if(s[j]=='>'||s[j]==')'||s[j]==']'||s[j]=='}'){
                if(c.empty())          //右括弧跑在左括弧前 
                    break;
                if(abs(s[j]-c.top())>2)    //交錯括弧  因為ASCII 表上 成對括弧編碼 相減不會超過2     
                    break;
                c.pop();     //成對 
            }
        if(s.size()-1==j&&c.empty())    //\0為最後顧s.size()-1當作句子結尾 掃描完成檢查是否為空 
            a=true;
        j++;
        }
        cout<<(a?'Y':'N')<<endl;
        while(!c.empty())
            c.pop();
    }
    return 0;
}
