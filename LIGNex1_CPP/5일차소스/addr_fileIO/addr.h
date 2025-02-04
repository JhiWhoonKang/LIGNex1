#ifndef ADDR_H_INCLUDED
#define ADDR_H_INCLUDED

#include "member.h"
//dao:databases access object
class AddrProcess{

    Member *datas[10]; //Member ��ü�� �ּ� 10�� ����
    int cnt;  //������ ���� ī��Ʈ

public:
    //������
    AddrProcess():cnt(0){}

    //�迭 ���� �� Member ��ü�� �߰�
    bool addMember(Member *m){
        bool flag = true;
        if(cnt>=9){
            flag = false;
        }else{
            datas[cnt++]=m;
        }
        return flag;
    }

    //��ȣ�� �˻��ؼ� ���ȣ ��ȯ
    int getByNum(int num){
        for(int i=0;i<cnt;i++){
            if(datas[i]->getNum() == num){
                return i;
            }
        }
        return -1;//not found ���
    }

    //���ȣ�� ã�Ƽ� �� ��ȯ
    Member* getByIdx(int idx){
        if(idx<0){
            return NULL;
        }
        return datas[idx];
    }

    int getCnt(){
        return cnt;
    }




    //����
    bool delMember(int idx){
        if(idx<0){
            return false;
        }
        delete datas[idx];
        for(int i=idx;i<cnt-1;i++){
            datas[i] = datas[i+1];
        }
        cnt--;
        return true;
    }

    ~AddrProcess(){
        for(int i=0;i<cnt;i++){
            delete datas[i];
        }
    }

};

#endif // ADDR_H_INCLUDED





