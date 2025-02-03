// See https://aka.ms/new-console-template for more information
using ConsoleApp4;

Parent p = new Parent("랄랄", "이명화", 12);
p.method();
p.vmethod();

Child c = new Child("가나", "다라", 23, "마바");
c.method();
c.vmethod();

Parent p2 = c; //업캐스팅
p2.method();
p2.vmethod();

//p2.Hobby = "adsf";
((Child)p2).Hobby = "asdf"; //다운 캐스팅
p2.vmethod();


