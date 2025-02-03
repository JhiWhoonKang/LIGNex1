using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class Person
    {
        //private string name;
        //public string Name {  //name의 속성
        //    set { name = value; }
        //    get { return name; } 
        //}
        //private int age;
        //public int Age      //age의 속성
        //{
        //    set { age = value; }
        //    get { return age; }
        //}
        public string Name { get; set; }
        public int Age { get; set; }
        public Person() { }
        public Person(string name, int age)
        {
            Name = name;
            Age = age; 
        }
        public void printInfo()
        {
            Console.WriteLine("name:" + Name + ", age:" + Age);
        }

        public override string ToString()
        {
            return "name:" + Name + " / age:" + Age;
        }
    }
}
