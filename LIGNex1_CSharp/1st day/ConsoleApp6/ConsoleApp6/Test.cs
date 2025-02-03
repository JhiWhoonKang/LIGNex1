using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    internal class Test
    {
        public int x;
        public Test(int x)
        {
            this.x = x;
        }

        public override bool Equals(object obj)
        {
            if(obj != null && obj is Test)
            {
                if(this.x == ((Test)obj).x)
                    return true;
            }
            return false;
        }
    }
}
