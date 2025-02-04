#ifndef ADDRSERVICE_H_INCLUDED
#define ADDRSERVICE_H_INCLUDED

#include "addr.h"
#include <fstream>

//service:����Ͻ� ���� ����
class AddrService{
    AddrProcess pr; //���԰���
    string fname = "addr.dat"; //����Ÿ ������ ���ϸ�

public:
    //�߰�
    void add(){
        char name[20];
        char tel[20];
        cout<<"����߰�"<<endl;
        cout<<"name:";
        cin>>name;
        cout<<"tel:";
        cin>>tel;
        bool flag = pr.addMember(new Member(name, tel));
        if(flag){
            cout<<"���� ó���� "<<endl;
        }else{
            cout<<"�޸� ���� ���� "<<endl;
        }
    }

    //�˻�
    void printMember(){
        cout<<"��ȣ�� �˻�"<<endl;
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

    //����
    void editMember(){
        cout<<"����"<<endl;
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

    //����
    void delMember(){
        cout<<"����"<<endl;
        cout<<"del num:";
        int num;
        cin>>num;
        bool flag = pr.delMember(pr.getByNum(num));
        if(flag){
            cout<<"����ó����"<<endl;
        }else{
            cout<<"�������"<<endl;
        }
    }

    //��ü���
    void printAll(){
        for(int i=0;i<pr.getCnt();i++){
            Member *res = pr.getByIdx(i);
            cout<<"num:"<<res->getNum()<<endl;
            cout<<"name:"<<res->getName()<<endl;
            cout<<"tel:"<<res->getTel()<<endl;
        }
    }

    //���α׷��� �������� ���� �ѹ� ȣ��
    //���Ͽ� ����� ��ü�� �迭�� �ű�
    void start(){
        //���� �Է� ��Ʈ�� ����
        ifstream fin;

        //��Ʈ������ ���� ���� ��ο� ��带 ����
        //���̳ʸ� �б� ���
        fin.open(fname, ios_base::in |ios_base::binary);

        Member m;//���Ͽ��� ���� 1�� ��ü�� ���� ����
        int cnt = 0;
        if (fin.is_open())//������ ���� ����
        {
            //��ü�� �ִ��� 1���� �о m�� ����
            while (fin.read((char *)&m, sizeof(Member)))
            {
                //m�� ������ ��ü�� ���� �����ؼ� �迭�� �߰�
                pr.addMember(new Member(m.getNum(), m.getName(), m.getTel()));
                cnt++; //������ ��ü ������ ī����
            }
            cout<<cnt<<" ���� ��ü �迭�� ����"<<endl;

            //�߰��� �Ҵ��� ��ȣ�� �ʱⰪ�� ������ ������ ��ȣ�� �ʱ�ȭ
            Member::cnt = pr.getByIdx(pr.getCnt()-1)->getNum();

            //���� ����
            fin.close();
        }
    }

    //���α׷� ����� �ѹ� ȣ���
    void stop(){

        //���� ��� ��Ʈ�� ����
        //���� ���:fname
        //���� ��:���̳ʸ� ���� ���.
        ofstream fout(fname, ios_base::out | ios_base::binary);

        //���� ����
        if (fout.is_open())
        {

            for(int i=0;i<pr.getCnt();i++){
                //�迭���� ��ü �ϳ��� ����
                Member *res = pr.getByIdx(i);
                //���� ��ü�� ���Ͽ� ���
                fout.write((char *)res, sizeof(Member));
            }

        }else{
            cout<<"���� ���� ����"<<endl;
        }
        fout.close();
    }

};

#endif // ADDRSERVICE_H_INCLUDED
