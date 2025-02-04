#include <iostream>

using namespace std;

class PocketMon{
protected:
    string name;
    int hp, exp, lv;
public:
    virtual void eat(){
        cout<<name<<" �����"<<endl;
    }
    virtual void sleep(){
        cout<<name<<" ����"<<endl;
    }
    virtual bool play(){
        cout<<name<<" ���"<<endl;
        return true;
    }
    virtual bool exc(){
        cout<<name<<" ���"<<endl;
        return true;
    }

    virtual void lvCheck(){
        cout<<name<<" ����üũ"<<endl;
    }

    void printState(){
        cout<<name<<" ����Ȯ��"<<endl;
        cout<<"hp: "<<hp<<endl;
        cout<<"exp: "<<exp<<endl;
        cout<<"lv: "<<lv<<endl;
    }
};
class Picachu:public PocketMon{
public:
    Picachu(){
        cout<<"��ī�� ������"<<endl;
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
            cout<<name<<"�� ���� 1������. lv:"<<lv<<endl;
        }
    }

    void elecAttack(){
        cout<<name<<" �鸸��Ʈ ����"<<endl;
    }
};
class Gobook:public PocketMon{
public:
    Gobook(){
        cout<<"���α� ������"<<endl;
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
            cout<<name<<"�� ���� 1������. lv:"<<lv<<endl;
        }
    }
    void waterAttack(){
        cout<<name<<" ������ ����"<<endl;
    }
};
class Lee:public PocketMon{
public:
    Lee(){
        cout<<"�̻��ؾ� ������"<<endl;
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
            cout<<name<<"�� ���� 1������. lv:"<<lv<<endl;
        }
    }
    void nungculAttack(){
        cout<<name<<" ���� ����"<<endl;
    }
};
class Menu{
    //�� ĳ������ Ȱ���Ͽ� PocketMon�� ��ӹ޴� Picachu, Gobook, Lee ���� ��ü�� ����
    PocketMon *p;
    /*
    �ڵ� �밡�� �� ����
    Picachu *p;
    Gobook *b;
    Lee *l;
    */
public:
    Menu(){
        cout<<"ĳ���� ����.\n1.��ī��(�⺻) 2.���α� 3.�̻���"<<endl;
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
        string str = "1.��Ա� 2.���ڱ� 3.��� 4.��ϱ� 5.����Ȯ�� 6.���� 7.Ư�����";
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
                //Ư�����
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



