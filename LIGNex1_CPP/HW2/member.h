#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

class Member{
    static int cnt;
    int num;
    string name;
    string tel;
public:
    Member() {}
    Member(String name, string tel)
    {
        num = ++cnt;
        this->name=name;
        this->tel=tel;
    }
    int getNum()
    {
        return num;
    }
    string getName()
    {
        return name;
    }
    string getTel()
    {
        return tel;
    }
    void setTel(string tel)
    {
        this->tel=tel;
    }
};
int Member::cnt=0;
#endif // MEMBER_H_INCLUDED
