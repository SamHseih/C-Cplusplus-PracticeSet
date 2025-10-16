#include <iostream>
#include <string>
#include <bitset>

using namespace std;


class Calculator {
    public: 
        int add(int a, int b){
            a = 11;
            return a+b;
        }

        int addd(int &a ,int b ){
            a = 111;
            return a+b;
        }

        void swap_ref(int &a, int &b){
            int tmp = a;
            a = b;
            b = tmp;
        }

        void swap_p(int* a, int* b){
            int tmp = *a;
            *a = *b;
            *b = tmp;
        }

        size_t size_tmystrlen_notptr(const char* s){
            size_t count = 0;
            while( s[count]!='\0') {  
                count++;
            }
            return count;
        }

        int size_tmystrlen(const char* s){
            const char* p = s;
            cout<<"p ="<<p<<endl;
            cout<<"s ="<<s<<endl;
            while( *p !='\0') { 
                p++;
            }
            return p-s;
        }
        void reverse_nogood(int *arr, size_t n){
            int* reverse = new int[n];
            for(int i=0;i<n;++i){
                reverse[i] = arr[n-i-1];
            }
            for(int i=0;i<n;++i){
                arr[i] = reverse[i];
            }
        }
        void reverse(int *arr, size_t n){
            for(size_t i=0;i<n/2;++i){
                int tmp = arr[i];
                arr[i] = arr[n-i-1];
                arr[n-i-1] = tmp;
            }
        }
        
 
};

    int main(){

       cout<<"Hello,Word"<<std::endl; 
       int a = 5;
       int b =10;
       int &r = a;
       int &r2 = b;
       int* p = &a;
       int *q = &b;
        printf("Refference : %d",a);
       Calculator  c ;
        
       cout<<"1 "<<c.add(a,b)<<"  " << a << "  "<<b<<endl;
       cout<<"2 "<<c.addd(a,b)<<"  " << a << "  "<<b<<endl;
       cout<<"3 "<<p<<endl;
       cout<<"4 "<<*p<<endl;
       *p=*q;
       cout<<"5 "<<a << "~~" << b<< endl;
       *p = 100;
       cout<<"6 "<<a << "~~" << b<< endl;
       c.swap_ref(a,b);
       cout<<"7 "<<"  " << a << "  "<<b<<endl;
       c.swap_p(&a,&b);
       cout<<"8 "<<"  " << a << "  "<<b<<endl;
       int* p2[10]; 
       int (*p3)[10];

       const int *p4;
       int *const p5 = &a; 
       const int* const p6 = &a ; 
        


       string s = "Hello,Word";
       const char* p7 = "41";       
       auto p8 = &"41";            
       cout <<"9 "<< *p7 << endl;         
       cout <<"10 "<< (*p8)[1] << endl;    
       cout<<"11 "<<"  " << c.size_tmystrlen_notptr(p7) <<endl;
       cout<<"12 "<<"  " << c.size_tmystrlen(p7) <<endl;

       a = 2 ;
       cout<<"13 "<<a++<<endl;
       cout<<"14 "<<bitset<8>(+a)<<endl;
       int  arr[4] = {1,2,3,4};
       c.reverse(arr,4);
       cout<<"15 ";
       for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
       }cout<<endl;
       
       return 0;
    }
    

 
