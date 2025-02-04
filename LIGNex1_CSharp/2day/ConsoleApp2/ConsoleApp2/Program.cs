// See https://aka.ms/new-console-template for more information
using ConsoleApp2;

Console.WriteLine("프로그램 시작");
int x = 3, y = 0;
ExceptionTest obj = null;
int[] arr = { 1, 2, 3 };
Console.WriteLine("짝수를 입력");
int num = Int32.Parse(Console.ReadLine());
try
{
    Console.WriteLine("예외발생 전");
    //Console.WriteLine("3/0:" + (x / y));
    //obj.x = 10; 
    //for(int i = 0; i < arr.Length+1; i++) {  Console.WriteLine(arr[i]); }
    if (num % 2 == 1)
    {
        throw new MyException("짝수이어야 함");
    }
    else
    {
        Console.WriteLine("num:"+num);
    }
    Console.WriteLine("예외발생 후");
}
catch(DivideByZeroException e)
{
    Console.WriteLine(e.ToString());
}
catch (NullReferenceException e)
{
    Console.WriteLine(e.ToString());
}
catch (Exception e)
{
    Console.WriteLine(e.ToString());
}
finally // 정상, 비정상 실행에도 모두 실행됨
{
    Console.WriteLine("finally 블록");
}

Console.WriteLine("프로그램 종료");