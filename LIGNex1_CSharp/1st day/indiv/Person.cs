using System;

namespace LIGNex1_CSharp
{
    internal class Person
    {
        private string name;
        public string Name
        {
            set { name = value; name2 = value; }
            get { return name; }
        }
        private int age;
        public int Age
        {
            set { age = value; age2 = value; }
            get { return age; }
        }

        public int age2 { get; set; }
        public string name2 { get; set; }

        public Person() { }
        
        public Person(string name, int age)
        {
            this.name = name;
            this.age = age;

            name2 = name;
            age2 = age;
        }

        public void printInfo()
        {
            Console.WriteLine("name: " + name + ", age: " + age);
        }

        public void printInfo2()
        {
            Console.WriteLine("name: " + name2 + ", age: " + age2);
        }

        public override string ToString()
        {
            return base.ToString();
            //return "name: " + name + " / age: " + age;
        }
    }
}