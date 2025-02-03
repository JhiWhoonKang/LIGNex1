using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    internal class Parent
    {
        public string Nickname { get; set; }
        protected string name;
        protected int age;

        public Parent() {
            Console.WriteLine("parent 생성자");
        }
        public Parent(string nickname, string name, int age)
        {
            Nickname = nickname;
            this.name = name;
            this.age = age;
            Console.WriteLine("parent 파람 생성자");
        }

        public void method()
        {
            Console.WriteLine("nickname:"+Nickname+", name:"+name+", age:"+age);
        }

        public virtual void vmethod()
        {
            Console.WriteLine("virtual function");
            Console.WriteLine("nickname:" + Nickname + ", name:" + name + ", age:" + age);
        }
    }

    internal class Child : Parent
    {
        public string Hobby {  get; set; }

        public Child() {
            Console.WriteLine("child 생성자");
        }

        public  Child(string nickname, string name, int age, string hobby)
            :base(nickname, name, age) //base:부모객체 참조변수, base():부모생성자호출
        {
            //Nickname = nickname;
            //this.name = name;
            //this.age = age;
            Hobby = hobby;
            Console.WriteLine("child 파람생성자");
        }

        //new 재정의
        //상속받은 부모 메서드를 무시하고 새로 정의
        //호출시 무조건 객체 타입을 따라감
        new public void method()
        {
            base.method();//부모 메서드 호출
            Console.WriteLine("hobby:"+Hobby);
        }

        override public void vmethod()
        {
            Console.WriteLine("override function");
            base.method();//부모 메서드 호출
            Console.WriteLine("hobby:" + Hobby);
        }
    } 
}
