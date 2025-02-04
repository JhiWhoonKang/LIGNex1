#ifndef ADDRSERVICE_H_INCLUDED
#define ADDRSERVICE_H_INCLUDED

#include "addr.h"
#include <fstream>

//service:비즈니스 로직 구현
class AddrService{
    AddrProcess pr; //포함관계
    string fname = "addr.dat"; //데이타 저장할 파일명

public:
    //추가
    void add(){
        char name[20];
        char tel[20];
        cout<<"멤버추가"<<endl;
        cout<<"name:";
        cin>>name;
        cout<<"tel:";
        cin>>tel;
        bool flag = pr.addMember(new Member(name, tel));
        if(flag){
            cout<<"정상 처리됨 "<<endl;
        }else{
            cout<<"메모리 부족 오류 "<<endl;
        }
    }

    //검색
    void printMember(){
        cout<<"번호로 검색"<<endl;
        cout<<"num:";
        int num;
        cin>>num;
        Member *res = pr.getByIdx(pr.getByNum(num));
        if(res == NULL){
            cout<<"not found"<<endl;
        }else{
            cout<<"num:"<<res->getNum()<<endl;
            cout<<"name:"<<res->getName()<<endl;
            cout<<"tel:"<<res->getTel()<<endl;
        }
    }

    //수정
    void editMember(){
        cout<<"수정"<<endl;
        cout<<"edit num:";
        int num;
        cin>>num;
        Member *res = pr.getByIdx(pr.getByNum(num));
        if(res == NULL){
            cout<<"not found"<<endl;
        }else{
            char tel[20];
            cout<<"new tel:";
            cin>>tel;
            res->setTel(tel);
        }
    }

    //삭제
    void delMember(){
        cout<<"삭제"<<endl;
        cout<<"del num:";
        int num;
        cin>>num;
        bool flag = pr.delMember(pr.getByNum(num));
        if(flag){
            cout<<"정상처리됨"<<endl;
        }else{
            cout<<"삭제취소"<<endl;
        }
    }

    //전체출력
    void printAll(){
        for(int i=0;i<pr.getCnt();i++){
            Member *res = pr.getByIdx(i);
            cout<<"num:"<<res->getNum()<<endl;
            cout<<"name:"<<res->getName()<<endl;
            cout<<"tel:"<<res->getTel()<<endl;
        }
    }

    //프로그램이 시작하자 마자 한번 호출
    //파일에 저장된 객체를 배열로 옮김
    void start(){
        //파일 입력 스트림 생성
        ifstream fin;

        //스트림에서 읽을 파일 경로와 모드를 지정
        //바이너리 읽기 모드
        fin.open(fname, ios_base::in |ios_base::binary);

        Member m;//파일에서 읽은 1개 객체를 담을 변수
        int cnt = 0;
        if (fin.is_open())//파일이 정상 오픈
        {
            //객체가 있는한 1개씩 읽어서 m에 저장
            while (fin.read((char *)&m, sizeof(Member)))
            {
                //m과 동일한 객체를 힙에 생성해서 배열에 추가
                pr.addMember(new Member(m.getNum(), m.getName(), m.getTel()));
                cnt++; //복사한 객체 개수를 카운팅
            }
            cout<<cnt<<" 개의 객체 배열에 저장"<<endl;

            //추가시 할당할 번호의 초기값을 마지막 데이터 번호로 초기화
            Member::cnt = pr.getByIdx(pr.getCnt()-1)->getNum();

            //파일 닫음
            fin.close();
        }
    }

    //프로그램 종료시 한번 호출됨
    void stop(){

        //파일 출력 스트림 생성
        //파일 경로:fname
        //오픈 모:바이너리 쓰기 모드.
        ofstream fout(fname, ios_base::out | ios_base::binary);

        //정상 오픈
        if (fout.is_open())
        {

            for(int i=0;i<pr.getCnt();i++){
                //배열에서 객체 하나씩 읽음
                Member *res = pr.getByIdx(i);
                //읽은 객체를 파일에 출력
                fout.write((char *)res, sizeof(Member));
            }

        }else{
            cout<<"파일 오픈 에러"<<endl;
        }
        fout.close();
    }

};

#endif // ADDRSERVICE_H_INCLUDED
