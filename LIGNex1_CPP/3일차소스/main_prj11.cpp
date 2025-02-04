#include <iostream>

using namespace std;
/*
//오버로딩으로 다형성 구현
class Tv{
public:
    string name;
    int price;
    int point;
    Tv(){
        name ="tv";
        price = 100;
        point = 10;
    }
};
class Computer{
public:
    string name;
    int price;
    int point;
    Computer(){
        name ="Computer";
        price = 200;
        point = 20;
    }
};
class Audio{
public:
    string name;
    int price;
    int point;
    Audio(){
        name ="Audio";
        price = 300;
        point = 30;
    }
};

class Buyer{
    int money;
    int point;
public:
    Buyer():money(1000), point(0){}
    void buy(Tv &tv){
        if(money>=tv.price){
            cout<<tv.name<<" 구매 "<<endl;
            money -= tv.price;
            point += tv.point;
        }else{
            cout<<"잔액부족"<<endl;
        }
        delete &tv;
    }
    void buy(Computer &c){
        if(money>=c.price){
            cout<<c.name<<" 구매 "<<endl;
            money -= c.price;
            point += c.point;
        }else{
            cout<<"잔액부족"<<endl;
        }
        delete &c;
    }
    void buy(Audio &a){
        if(money>=a.price){
            cout<<a.name<<" 구매 "<<endl;
            money -= a.price;
            point += a.point;
        }else{
            cout<<"잔액부족"<<endl;
        }
        delete &a;
    }
};
*/

class Product{
public:
    string name;
    int price;
    int point;
};

class Tv:public Product{
public:
    Tv(){
        name ="Tv";
        price = 100;
        point = 10;
    }
};
class Computer:public Product{
public:
    Computer(){
        name ="Computer";
        price = 200;
        point = 20;
    }
};
class Audio:public Product{
public:
    Audio(){
        name ="Audio";
        price = 300;
        point = 30;
    }
};
class Buyer{
    int money;
    int point;
public:
    Buyer():money(1000), point(0){}
    void buy(Product *p){
        if(money>=p->price){
            cout<<p->price<<" 구매 "<<endl;
            money -= p->price;
            point += p->point;
            cout<<"잔액: "<<money<<", point:"<<point<<endl;
        }else{
            cout<<"잔액부족"<<endl;
        }
    }
};
int main()
{

    Buyer b;
    Product *arr[] = {new Tv(), new Computer(), new Audio(), new Tv(), new Computer(), new Audio(),
                        new Tv(), new Computer(), new Audio()};

    for(int i=0;i<9;i++){
        b.buy(arr[i]);
    }

    for(int i=0;i<9;i++){
        delete arr[i];
    }

      /*
      //오버로딩 호출
    b.buy(*(new Tv()));
    b.buy(*(new Computer()));
    b.buy(*(new Audio()));
    b.buy(*(new Tv()));
    b.buy(*(new Computer()));
    b.buy(*(new Audio()));
    b.buy(*(new Tv()));
    b.buy(*(new Computer()));
    b.buy(*(new Audio()));
    */
    return 0;
}
