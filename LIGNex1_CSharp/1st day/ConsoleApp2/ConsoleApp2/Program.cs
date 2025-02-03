// See https://aka.ms/new-console-template for more information
using ConsoleApp2;

Person p1 = new Person("aaa", 13);
//p1.name = "Test";
p1.Name = "bbb"; //setter 호출
//p1.age = 10;
p1.Age = 20; //setter 호출
//p1.printInfo();
Console.WriteLine("name:"+p1.Name+", age:"+p1.Age); //getter 호출

Console.WriteLine(p1);
Console.WriteLine(p1.ToString());
Console.WriteLine(p1.GetHashCode());
