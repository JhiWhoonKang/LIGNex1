using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class StaticTest
    {
        public static int a;
        public int b;

        //일반 메서드. 객체 생성후 호출이 가능
        //일반 멤버변수, static 변수 사용 가능
        public void test1()
        {
            a = 1;
            b = 2;
        }

        //static 메서드는 객체 생성전에도 호출 가능.
        //객체 생성 전엔 일반 멤버 생성전이라 사용 불가능
        public static void test2()
        {
            a = 1;
            //b = 2; //에러. 
        }

        //일반 메서드 
        public void test3()
        {
            test1(); //일반 메서드 호출 가능
            test2(); //static 메서드 호출 가능
        }

        //static 메서드
        public static void test4()
        {
            //test1(); //에러 => 객체 생성 전 일반 메서드 호출 불가능 
            test2(); //static 메서드 호출 가능
        }
    }


}
