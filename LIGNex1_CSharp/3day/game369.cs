using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace ConsoleApp1
{
    class Test369
    {
        public delegate void myDel();
        public myDel e;

        public void fireEvent()
        {
            e();
        }
        public void run()
        {
            for (int i = 1; i <= 100; i++)
            {
                int cnt = 0;
                string str = i + "";
                char[] arr = str.ToArray();
                for (int j = 0; j < arr.Length; j++)
                {
                    if (arr[j] == '3' || arr[j] == '6' || arr[j] == '9')
                    {
                        cnt++;
                    }
                }
                if (cnt == 0)
                {
                    Console.WriteLine(str);
                }
                else
                {
                    for (int j = 0; j < cnt; j++)
                    {
                        fireEvent();
                    }
                    Console.WriteLine();
                }
            }
        }
    }
    class Program
    {
        public static void OnEvent()
        {
            Console.Write("짝");
        }
        static void Main(string[] args)
        {
            Test369 t = new Test369();
            t.e += new Test369.myDel(OnEvent);
            t.run();
        }
    }
}

