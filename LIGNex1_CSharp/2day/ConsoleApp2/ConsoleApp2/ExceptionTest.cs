using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class ExceptionTest
    {
        public int x;
    }

    internal class MyException : Exception { 
        public MyException(string msg):base(msg) { }
    }

}
