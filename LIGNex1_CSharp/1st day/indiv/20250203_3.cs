using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LIGNex1_CSharp
{
    internal class _20250203_3
    {
        static void Main(string[] args)
        {
            Picachu pica = new Picachu();
            pica.eat();
            pica.printState();

            int i = 3, j = 0;
            for (; i < 5; ++i, ++j);
            Console.WriteLine(i + " " + j);
        }
    }
}
