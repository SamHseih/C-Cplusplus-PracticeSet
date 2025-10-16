#include <bits/stdc++.h>
 
using namespace std;
//建立一個結構
 
class Player_Unknown_Battle_Ground{
    private:
    //設變數
    char Weapon[2][64];
    char Equipment[5][64];
    char Item[5][64];
    int nw,ne,ni;
    public:
    //把值初始化
    void start(){
        cout <<"GAME START!\n";
        nw=0;ne=0;ni=0;
        for(int i=0;i<2;i++){strcpy(Weapon[i],"");}
        for(int i=0;i<5;i++){strcpy(Equipment[i],"");}
        for(int i=0;i<5;i++){strcpy(Item[i],"");}
    }
    //進行撿裝備的動作
    void pickup(char type,char name[]){
        //判斷種類
        if(type=='w'){
            if(nw==2){cout << "Weapon capacity full, pickup failed.\n";}
            else{
                for(int i=0;i<2;i++){
                    if(strcmp(Weapon[i],"")==0){strcpy(Weapon[i],name);break;}
                }
                nw++;
                cout<<"Pickup weapon: "<<name<<endl;
            }
        }
        else if(type=='e'){
            if(ne==5){cout << "Equipment capacity full, pickup failed.\n";}
            else{
                for(int i=0;i<5;i++){
                    if(strcmp(Equipment[i],"")==0){strcpy(Equipment[i],name);break;}
                }
                ne++;
                cout<<"Pickup equipment: "<<name<<endl;
            }
        }
        else if(type=='i'){
            if(ni==5){cout << "Item capacity full, pickup failed.\n";}
            else{
                for(int i=0;i<5;i++){
                    if(strcmp(Item[i],"")==0){strcpy(Item[i],name);break;}
                }
                ni++;
                cout<<"Pickup item: "<<name<<endl;
            }
        }
        else{cout <<"Invalid Command\n";}
    }
    //進行丟裝備的動作
    void drop(char type,char name[]){
        //判斷種類
        if(type=='w'){
            if(nw==0){cout << "Weapon bag empty, nothing to toss.\n";}
            else{
                int sus=0;
                for(int i=0;i<2;i++){
                    if(strcmp(Weapon[i],name)==0){strcpy(Weapon[i],"");sus=1;break;}
                }
                if(!sus){cout<<"Weapon "<<name <<" doesn't exist, nothing to toss.\n";}
                else{
                    nw--;
                    cout<<"Dropped weapon: "<<name<<endl;
                }
            }
        }
        else if(type=='e'){
            if(ne==0){cout << "Equipment bag empty, nothing to toss.\n";}
            else{
                int sus=0;
                for(int i=0;i<5;i++){
                    if(strcmp(Equipment[i],name)==0){strcpy(Equipment[i],"");sus=1;break;}
                }
                if(!sus){cout<<"Equipment "<<name <<" doesn't exist, nothing to toss.\n";}
                else{
                    ne--;
                    cout<<"Dropped equipment: "<<name<<endl;
                }
            }
        }
        else if(type=='i'){
            if(ni==0){cout << "Item bag empty, nothing to toss.\n";}
            else{
                int sus=0;
                for(int i=0;i<5;i++){
                    if(strcmp(Item[i],name)==0){strcpy(Item[i],"");sus=1;break;}
                }
                if(!sus){cout<<"Item "<<name <<" doesn't exist, nothing to toss.\n";}
                else{
                    ni--;
                    cout<<"Dropped item: "<<name<<endl;
                }
            }
        }
        else{cout <<"Invalid Command\n";}
 
    }
    //顯示目前所拿的裝備
    void show(){
        cout <<"Weapon:\n";
        for(int i=0;i<2;i++){
            if(strcmp(Weapon[i],"")!=0){cout <<"\t"<<Weapon[i]<<"\n";}
        }
        cout <<"Equipment:\n";
        for(int i=0;i<5;i++){
            if(strcmp(Equipment[i],"")!=0){cout <<"\t"<<Equipment[i]<<"\n";}
        }
        cout <<"Item:\n";
        for(int i=0;i<5;i++){
            if(strcmp(Item[i],"")!=0){cout <<"\t"<<Item[i]<<"\n";}
        }
    }
    void ended(){
        cout<<"GAME OVER\n";
    }
};
 
typedef class Player_Unknown_Battle_Ground PUBG;
 
int main(){
    PUBG game;
    game.start();
    char a='z';
    char t;
	char name[64];
while(a!='q'){
	cin>>a;
	switch(a){
		case 'p':{
			cin>>t>>name;	
			game.pickup(t,name);
			
			break;
		}
		case 'd':{
			cin>>t>>name;	
			game.drop(t,name);
			break;
		}
    	case 's':{
    		game.show();
			break;
		}
		case 'q':{
			break;
		}
	}
}
    game.ended();
return 0;
}
