// See https://aka.ms/new-console-template for more information
using System.Collections;
using ConsoleApp3;

ArrayList list = new ArrayList(); //object로 업캐스팅되어 저장됨 
list.Add("asdf");
list.Add(1);
list.Add(2.5);
list.Add(new Test());

foreach(object o in list)
{
    Console.WriteLine(o);
}

list.Insert(1, "bbb");

foreach (object o in list)
{
    Console.WriteLine(o);
}

Console.WriteLine("1이 있는가?:" + list.Contains(1));
Console.WriteLine("1의 위치:" + list.IndexOf(1));
Console.WriteLine("1삭제:");
list.Remove(1);
Console.WriteLine("1의 위치:" + list.IndexOf(1));
Console.WriteLine("0번방 삭제:");
list.RemoveAt(0);
foreach (object o in list)
{
    Console.WriteLine(o);
}
Console.WriteLine("요소 개수:"+list.Count);
Console.WriteLine("모든 요소 삭제");
list.Clear();
Console.WriteLine("요소 개수:" + list.Count);