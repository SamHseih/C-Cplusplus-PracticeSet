#include <bits/stdc++.h>
#include<string>
 
using namespace std;
//建立一個結構
typedef struct data{
    char product_name[256];
    long long price;
    long long number_of_sold;
}Data;
 
typedef struct data2{
    char product_name[256];
    long long number;
}Data2;
 
 
class Old_Farmer_Market{
    private:
    //設變數
    Data Product_list[500];
    long long item_type;
    long long profit;
    long long total_item_sold;
    public:
    //把值初始化
    void business(){
        item_type=0;
        profit=0;
        total_item_sold=0;
        for(int i=0;i<500;i++){
            strcpy(Product_list[i].product_name,"");
            Product_list[i].price=0;
            Product_list[i].number_of_sold=0;
        }
    }
    //進行加入新產品
    void add(Data x){
        Product_list[item_type]=x;
        cout <<"Added. Product: "<<x.product_name<<".\nSell price: "<<x.price<<"\n";
        item_type++;
    }
    //更新產品
    void update(Data x){
        for(int i=0;i<item_type;i++){
            if(strcmp(x.product_name,Product_list[i].product_name)==0){  //找產品 
                Product_list[i].price=x.price;
                cout <<"Updated. Product: "<<x.product_name<<".\nSell Price: "<<x.price<<"\n";
                break;
            }
        }
    }
    //賣出產品
    void sell(Data2 x){
        for(int i=0;i<item_type;i++){
            if(strcmp(x.product_name,Product_list[i].product_name)==0){ //找產品 
                Product_list[i].number_of_sold+=x.number;
                cout <<"Sold. Product: "<<x.product_name<<".\nNumber of sold: "<<x.number<<"\n";
                profit+=x.number*Product_list[i].price;
                total_item_sold+=x.number;
                break;
            }
        }
    }
    //顯示目前賣出產品的數量和目前的總利潤
    void display(){
        for(int i=0;i<item_type;i++){
            cout <<"Product: "<<Product_list[i].product_name<<".\nTotal number of sold: "<<Product_list[i].number_of_sold<<"\n";
        }
        cout <<"Total product sold: "<<total_item_sold<<"\nProfit: "<<profit<<"\n";
    }
};
 
typedef class Old_Farmer_Market OFM;
 
int main(){
    OFM Old;
    Old.business();
    cout <<"Welcome to Old Farmer Market, what can I help you?\n";
    char a; 	Data x1;
    Data2 x2;
    char name[256];   int price,sold; 
while(a!='q'){
	cin>>a;
	cin.ignore();
		switch(a){
			case 'a':{
				cin.getline(name,256);
				cin>>price;  //清空輸入暫存器\n 
				cin.ignore();
				strcpy(x1.product_name,name);
				x1.price=price;
				Old.add(x1);
				break;
			}
			case 'u':{
				cin.getline(name,256);
				cin>>price;  //清空輸入暫存器\n 
				cin.ignore();
				strcpy(x1.product_name,name);
				x1.price=price;
				Old.update(x1);
				break;
			}
			case 'd':{
				Old.display();
				break;
			}
			case 's':{
				cin.getline(name,256);
				cin>>sold;  //清空輸入暫存器\n 
				cin.ignore();
				strcpy(x2.product_name,name);
				x2.number=sold;
				Old.sell(x2);
				break;
			}
			case 'q':{
				break;
			}
		}
	}
	 cout <<"Thanks for visiting Old Farmer Market. Wish you have a good day. Bye bye.\n";
return 0;
}
