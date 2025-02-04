// See https://aka.ms/new-console-template for more information
using ConsoleApp1;

//static 멤버는 객체 생성과 상관없이 사용가능
//static 멤버는 힙이 아니라 정적메모리에 할당됨. 
//0으로 초기화됨
//static 멤버는 객체 이름이 아닌 클래스 이름으로 접근
Console.WriteLine("객체 생성 전 static a:" + StaticTest.a);

//객체 생성시 멤버변수 자동 초기화
//숫자타입:0, 객체타입은 null
StaticTest st = new StaticTest(); //힙에 객체 생성. 객체에는 b만 생성됨 b=0
StaticTest.a++;  //1
st.b++;            //1
Console.WriteLine("a:" + StaticTest.a + ", b:"+st.b);

StaticTest st2 = new StaticTest();//힙에 객체 생성. 객체에는 b만 생성됨 b=0
StaticTest.a++;//2 => static 멤버는 모든 객체가 공유. 새로 만들어지지 않음
st2.b++;  //1
Console.WriteLine("a:" + StaticTest.a + ", b:" + st2.b);

StaticTest st3 = new StaticTest();//힙에 객체 생성. 객체에는 b만 생성됨 b=0
StaticTest.a++;  //3
st3.b++;  //1
Console.WriteLine("a:" + StaticTest.a + ", b:" + st3.b);