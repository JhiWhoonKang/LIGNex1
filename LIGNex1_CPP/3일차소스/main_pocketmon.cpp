#include <iostream>

using namespace std;

class PocketMon{
protected:
    string name;
    int hp, exp, lv;
public:
    virtual void eat(){
        cout<<name<<" 밥먹음"<<endl;
    }
    virtual void sleep(){
        cout<<name<<" 잠잠"<<endl;
    }
    virtual bool play(){
        cout<<name<<" 놀기"<<endl;
        return true;
    }
    virtual bool exc(){
        cout<<name<<" 운동함"<<endl;
        return true;
    }

    virtual void lvCheck(){
        cout<<name<<" 레벨체크"<<endl;
    }

    void printState(){
        cout<<name<<" 상태확인"<<endl;
        cout<<"hp: "<<hp<<endl;
        cout<<"exp: "<<exp<<endl;
        cout<<"lv: "<<lv<<endl;
    }
};
class Picachu:public PocketMon{
public:
    Picachu(){
        cout<<"피카추 생성됨"<<endl;
        name = "picachu";
        hp = 30;
        lv = 1;
        exp = 0;
    }
    virtual void eat(){
        PocketMon::eat();
        hp += 5;
    }
    virtual void sleep(){
        PocketMon::sleep();
        hp += 8;
    }
    virtual bool play(){
        PocketMon::play();
        hp -= 8;
        exp += 5;
        lvCheck();
        return hp>0;
    }
    virtual bool exc(){
        PocketMon::exc();
        hp -= 15;
        exp += 10;
        lvCheck();
        return hp>0;
    }

    virtual void lvCheck(){
        PocketMon::lvCheck();
        if(exp>=20){
            lv++;
            exp -= 20;
            cout<<name<<"의 레벨 1증가됨. lv:"<<lv<<endl;
        }
    }

    void elecAttack(){
        cout<<name<<" 백만볼트 공격"<<endl;
    }
};
class Gobook:public PocketMon{
public:
    Gobook(){
        cout<<"꼬부기 생성됨"<<endl;
        name = "gobook";
        hp = 40;
        lv = 1;
        exp = 0;
    }
    virtual void eat(){
        PocketMon::eat();
        hp += 8;
    }
    virtual void sleep(){
        PocketMon::sleep();
        hp += 15;
    }
    virtual bool play(){
        PocketMon::play();
        hp -= 15;
        exp += 8;
        lvCheck();
        return hp>0;
    }
    virtual bool exc(){
        PocketMon::exc();
        hp -= 25;
        exp += 15;
        lvCheck();
        return hp>0;
    }

    virtual void lvCheck(){
        PocketMon::lvCheck();
        if(exp>=40){
            lv++;
            exp -= 40;
            cout<<name<<"의 레벨 1증가됨. lv:"<<lv<<endl;
        }
    }
    void waterAttack(){
        cout<<name<<" 물대포 공격"<<endl;
    }
};
class Lee:public PocketMon{
public:
    Lee(){
        cout<<"이상해씨 생성됨"<<endl;
        name = "lee";
        hp = 10;
        lv = 1;
        exp = 0;
    }
    virtual void eat(){
        PocketMon::eat();
        hp += 3;
    }
    virtual void sleep(){
        PocketMon::sleep();
        hp += 5;
    }
    virtual bool play(){
        PocketMon::play();
        hp -= 4;
        exp += 3;
        lvCheck();
        return hp>0;
    }
    virtual bool exc(){
        PocketMon::exc();
        hp -= 8;
        exp += 7;
        lvCheck();
        return hp>0;
    }

    virtual void lvCheck(){
        PocketMon::lvCheck();
        if(exp>=10){
            lv++;
            exp -= 10;
            cout<<name<<"의 레벨 1증가됨. lv:"<<lv<<endl;
        }
    }
    void nungculAttack(){
        cout<<name<<" 넝쿨 공격"<<endl;
    }
};
class Menu{
    //업 캐스팅을 활용하여 PocketMon을 상속받는 Picachu, Gobook, Lee 들의 객체를 저장
    PocketMon *p;
    /*
    코드 노가다 넘 많음
    Picachu *p;
    Gobook *b;
    Lee *l;
    */
public:
    Menu(){
        cout<<"캐릭터 선택.\n1.피카추(기본) 2.꼬부기 3.이상해"<<endl;
        int m;
        cin>>m;
        switch(m){
        case 2:
            p = new Gobook();
            break;
        case 3:
            p = new Lee();
            break;
        default:
            p = new Picachu();
            break;
        }
    }
    void run(){
        string str = "1.밥먹기 2.잠자기 3.놀기 4.운동하기 5.상태확인 6.종료 7.특기공격";
        bool flag = true;
        int m;
        while(flag){
            cout<<str<<endl;
            cin>>m;
            switch(m){
            case 1:
                p->eat();
                break;
            case 2:
                p->sleep();
                break;
            case 3:
                flag = p->play();
                break;
            case 4:
                flag = p->exc();
                break;
            case 5:
                p->printState();
                break;
            case 6:
                flag = false;
                break;
            case 7:
                //특기공격
                break;

            }
        }
    }
    ~Menu(){
        delete p;
    }
};
int main()
{
    Menu m;
    m.run();
    return 0;
}



