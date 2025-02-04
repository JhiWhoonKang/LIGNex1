#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "addrservice.h"

class AddrMenu{
    AddrService service;
public:
    void run(){
        service.start();
        string str = "1.�߰� 2.�˻� 3.���� 4.���� 5.��ü��� 6.����";
        bool flag = true;
        int m;
        while(flag){
            cout<<str<<endl;
            cin>>m;
            switch(m){
            case 1:
                service.add();
                break;
            case 2:
                service.printMember();
                break;
            case 3:
                service.editMember();
                break;
            case 4:
                service.delMember();
                break;
            case 5:
                service.printAll();
                break;
            case 6:
                flag = false;
                break;
            }
        }
        service.stop();
    }
};


#endif // MENU_H_INCLUDED
