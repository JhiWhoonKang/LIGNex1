using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace LIGNex1_CSharp
{
    internal class PocketMon
    {
        protected string name;
        protected int hp, exp, lv;

        public virtual void eat()
        {
            Console.WriteLine(name + " 밥 먹음");
        }

        public virtual void sleep()
        {
            Console.WriteLine(name + " 잠잠");
        }

        public virtual bool play()
        {
            Console.WriteLine(name + " 놀기");
            return true;
        }

        public virtual bool exc()
        {
            Console.WriteLine(name + " 운동함");
            return true;
        }

        public virtual void  lvCheck()
        {
            Console.WriteLine(name + " 레벨 체크");
        }

        public virtual void printState()
        {
            Console.WriteLine(name + " 상태 확인");
            Console.WriteLine("hp: " + hp);
            Console.WriteLine("exp: " + exp);
            Console.WriteLine("lv: " + lv);
        }
    }

    class Picachu : PocketMon
    {
        public Picachu()
        {
            Console.WriteLine("피카추 생성 됨");
            name = "picachu";
            hp = 30;
            lv = 1;
            exp = 0;
        }

        public override void eat()
        {
            base.eat();
            hp += 5;
        }

        public override void sleep()
        {
            base.sleep();
            hp += 8;
        }

        public override bool play()
        {
            base.play();
            hp -= 8;
            exp += 5;
            lvCheck();
            return hp > 0;
        }

        public override void lvCheck()
        {
            base.lvCheck();
            if (exp >= 20)
            {
                lv++;
                exp -= 20;
                Console.WriteLine(name + "의 레벨 1 증가됨. lv: " + lv);
            }
        }

        public void elecAttack()
        {
            Console.WriteLine(name + "백만볼트 공격");
        }
    }

    internal class Menu
    {
        private PocketMon ch; //업케스팅


    }
}
