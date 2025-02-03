// See https://aka.ms/new-console-template for more information
using ConsoleApp6;
object[] obj = { 1, 1.5, "aaa", new Test(1) };

foreach(object o in obj)
{
    if(o is Test)
    {
        Console.WriteLine("x:"+((Test)o).x);
    }
    else
    {
        Console.WriteLine(o);
    }
}

string[] str = { "aaa", "bbb", "ccc" };
foreach(string s in str)
{
    Console.WriteLine(s);
}

Test t1 = new Test(1);
Test t2 = new Test(1);
Test t3 = t1;
Console.WriteLine("t1==t2:"+(t1==t2));
Console.WriteLine("t1.Equals(t2):" + (t1.Equals(t2)));
Console.WriteLine("t1==t3:" + (t1 == t3)); //객체를 ==으로 비교하면 참조값비교
//객체의 내용을 비교: Equals()재정의
string asd = "asdf";//상수의 주소 할당
string s1 = new string("aaa");
string s2 = new string("aaa");
string s3 = new string("bbb");
Console.WriteLine("s1==s2:"+(s1==s2));
Console.WriteLine("s1==s3:" + (s1 == s3));
Console.WriteLine("s1.Equals(s2):" + (s1.Equals(s2)));



