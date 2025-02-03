using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp7
{
    internal interface Ianimal
    {
        void sound();
    }

    class Dog : Ianimal
    {
        public void sound()
        {
            Console.WriteLine("멍멍");
        }
    }
    class Cat : Ianimal
    {
        public void sound()
        {
            Console.WriteLine("야옹");
        }
    }
    class 고슴도치 : Ianimal
    {
        public void sound()
        {
            Console.WriteLine("고슴고슴");
        }
    }

    class Action
    {
        public void action(Ianimal animal) //인터페이스 활용
        {
            animal.sound();
        }
    }
}
