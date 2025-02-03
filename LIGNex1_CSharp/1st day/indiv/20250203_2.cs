using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LIGNex1_CSharp
{
    internal class _20250203_2
    {
        static void Main(string[] args)
        {
            Person person = new Person("지훈", 26);
            //person.printInfo();

            Person p1 = new Person();
            p1.Name = "bbb";
            p1.Age = 26;
            //p1.printInfo();
            //p1.printInfo2();
            //Console.WriteLine(p1);
            //Console.WriteLine(p1.ToString());

            Parent p = new Parent("랄랄", "이명화", 12);
            p.method();
            p.vmethod();           
            
            Child c = new Child("가나", "다라", 23, "마바");
            c.method();
            c.vmethod();

            Parent p2 = c;
            p2.method();        
            p2.vmethod();            
        }
    }
}