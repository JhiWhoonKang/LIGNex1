#ifndef ADDR_H_INCLUDED
#define ADDR_H_INCLUDED

#include "member.h"
//dao:databases access object
class AddrProcess{

    Member *datas[10]; //Member 객체의 주소 10개 저장
    int cnt;  //데이터 개수 카운트

public:
    //생성자
    AddrProcess():cnt(0){}

    //배열 끝에 새 Member 객체를 추가
    bool addMember(Member *m){
        bool flag = true;
        if(cnt>=9){
            flag = false;
        }else{
            datas[cnt++]=m;
        }
        return flag;
    }

    //번호로 검색해서 방번호 반환
    int getByNum(int num){
        for(int i=0;i<cnt;i++){
            if(datas[i]->getNum() == num){
                return i;
            }
        }
        return -1;//not found 상수
    }

    //방번호로 찾아서 값 반환
    Member* getByIdx(int idx){
        if(idx<0){
            return NULL;
        }
        return datas[idx];
    }

    int getCnt(){
        return cnt;
    }




    //삭제
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





