using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class Arr
    {
        public int[] arr = new int[10];
        public int pIdx = 0; //생산쪽 인덱스
        public int cIdx = 0; //소비쪽 인덱스
        public int cnt = 0; //데이터 수(10을 넘어서면 안됨)
        public int num = 0; //데이터 숫자
        public bool flag = false; //두 개의 컨수머 제어할 상태값 
    }
    class Work
    {
        public void pro(object o)
        {
            Arr a = ((Arr)o);
            while (true)
            {
                lock (a)
                {
                    if (a.cnt >= 3)
                    {
                        a.flag = false;
                        Monitor.PulseAll(a);
                    }
                    if (a.cnt >= 10)
                    {
                        Console.WriteLine("배열이 가득참");
                        Monitor.Wait(a);
                    }
                    else
                    {
                        a.arr[a.pIdx] = ++a.num;
                        Console.WriteLine("생산:" + a.arr[a.pIdx]);
                        a.pIdx++;
                        a.cnt++;
                        if (a.pIdx == 10)
                        {
                            a.pIdx = 0;
                        }
                    }
                }
                Thread.Sleep(1000);
            }
        }
        public void cons(object o)
        {
            Arr a = ((Arr)o);
            while (true)
            {
                lock (a)
                {
                    if (a.cnt <= 7)
                    {
                        Monitor.PulseAll(a);
                    }
                    if (a.cnt == 0 || a.flag)
                    {
                        Console.WriteLine("배열이 빔");
                        a.flag = true;
                        Monitor.Wait(a);
                    }
                    else
                    {
                        Console.WriteLine("소비1:" + a.arr[a.cIdx++]);
                        a.cnt--;
                        if (a.cIdx == 10)
                        {
                            a.cIdx = 0;
                        }
                    }

                }
                Thread.Sleep(2000);
            }
        }
        public void cons2(object o)
        {
            Arr a = ((Arr)o);
            while (true)
            {
                Console.ReadLine();
                lock (a)
                {
                    if (a.cnt <= 7)
                    {
                        Monitor.PulseAll(a);
                    }
                    if (a.cnt == 0 || a.flag)
                    {
                        a.flag = true;
                        Console.WriteLine("배열이 빔");
                        Monitor.Wait(a);
                    }
                    else
                    {
                        Console.WriteLine("소비2:" + a.arr[a.cIdx++]);
                        a.cnt--;
                        if (a.cIdx == 10)
                        {
                            a.cIdx = 0;
                        }
                    }
                }
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Arr x = new Arr();
            Work w = new Work();
            Thread t1 = new Thread(new ParameterizedThreadStart(w.pro));
            t1.Start(x);
            Thread t2 = new Thread(new ParameterizedThreadStart(w.cons));
            t2.Start(x);
            Thread t3 = new Thread(new ParameterizedThreadStart(w.cons2));
            t3.Start(x);
        }
    }

}
