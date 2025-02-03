using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LIGNex1_CSharp
{
    internal class Parent
    {
        protected string Nickname {  get; set; }
        protected string name;
        protected int age;

        public Parent() 
        {
            Console.WriteLine("Parent 생성자");
        }
        public Parent(string Nickname, string name, int age)
        {
            this.Nickname = Nickname;
            this.name = name;
            this.age = age;
            Console.WriteLine("Parent 생성자2");
        }

        public void method()
        {
            Console.WriteLine("nickname: " + Nickname + ", name: " + name + ", age: " + age);
        }

        public virtual void vmethod() 
        {
            Console.WriteLine("virtual function");
            Console.WriteLine("nickname: " + Nickname + ", name: " + name + ", age: " + age);
        }
    }

    internal class Child : Parent
    {
        public string Hobby { get; set; }
        public Child() 
        {
            Console.WriteLine("Child 생성자");
        }
        public Child(string Nickname, string name, int age, string Hobby) : base(Nickname, name, age)
        {
            // base: 부모객체 참조변수, base(): 부모생성자호출
            this.Hobby = Hobby;
            //this.Nickname = Nickname;
            //this.name = name;
            //this.age = age;
            Console.WriteLine("child 파람 생성자");
        }

        //new 재정의
        // 상속받은 부모 메서드를 무시하고 새로 정의
        // 호출 시 무조건 객체 타입을 따라감
        new public void method() //상송 받는 부모 메소드를 무시하고 새로 재정의
        {
            base.method();//부모 객체를 참조 => 부모의 method 호출
            Console.WriteLine("Hobby: " + Hobby);

            //Console.WriteLine("nickname: " + Nickname + ", name: " + name + ", age: " + age
            //    + ", Hobby: " + Hobby);
        }

        public override void vmethod()
        {
            Console.WriteLine("override function");
            base.method();
            Console.WriteLine("Hobby: " + Hobby);
        }


        public void method2()
        {
            Console.WriteLine("nickname: " + Nickname + ", name: " + name + ", age: " + age 
                + ", Hobby: " + Hobby);
        }
    }
}