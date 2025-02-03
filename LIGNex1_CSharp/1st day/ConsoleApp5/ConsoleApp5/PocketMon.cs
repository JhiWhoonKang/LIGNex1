using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    internal class PocketMon
    {
        protected int hp, exp, lv;
        protected string name;

        public virtual void 밥먹기()
        {
            Console.WriteLine(name + " 밥먹음");
        }
        public virtual void 잠자기()
        {
            Console.WriteLine(name + " 잠잠");
        }
        public virtual bool 놀기()
        {
            Console.WriteLine(name + " 놈");
            return true;
        }
        public virtual bool 운동하기()
        {
            Console.WriteLine(name + " 운동함");
            return true;
        }
        public virtual void lvCheck()
        {
            Console.WriteLine(name + " 레벨체크");
        }
        public void printState()
        {
            Console.WriteLine(name + " 상태");
            Console.WriteLine("hp:"+hp+" / exp:"+exp+" / lv:"+lv);
        }
    }
    internal class Picachu : PocketMon
    {
        public Picachu()
        {
            name = "피카추";
            hp = 30;
            exp = 0;
            lv = 1;
        }

        public override void 밥먹기()
        {
            base.밥먹기();
            hp += 5;
        }
        public override void 잠자기()
        {
            base.잠자기();
            hp += 10;
        }
        public override bool 놀기()
        {
            base.놀기();
            hp -= 6;
            exp += 5;
            lvCheck();
            return hp > 0; //생명유무 반환
        }
        public override bool 운동하기()
        {
            base.운동하기();
            hp -= 12;
            exp += 8;
            lvCheck();
            return hp > 0; //생명유무 반환
        }

        public override void lvCheck()
        {
            base.lvCheck();
            if(exp >= 20)
            {
                lv++;
                exp -= 20;
                Console.WriteLine(name + "의 레벨 1증가. lv:"+lv);
            }
        }
        public void 전기공격()
        {
            Console.WriteLine(name+" 전기공격");
        }
    }
    internal class Gobook : PocketMon
    {
        public Gobook()
        {
            name = "Gobook";
            hp = 40;
            exp = 0;
            lv = 1;
        }

        public override void 밥먹기()
        {
            base.밥먹기();
            hp += 2;
        }
        public override void 잠자기()
        {
            base.잠자기();
            hp += 5;
        }
        public override bool 놀기()
        {
            base.놀기();
            hp -= 5;
            exp += 3;
            lvCheck();
            return hp > 0; //생명유무 반환
        }
        public override bool 운동하기()
        {
            base.운동하기();
            hp -= 7;
            exp += 5;
            lvCheck();
            return hp > 0; //생명유무 반환
        }

        public override void lvCheck()
        {
            base.lvCheck();
            if (exp >= 25)
            {
                lv++;
                exp -= 25;
                Console.WriteLine(name + "의 레벨 1증가. lv:" + lv);
            }
        }
        public void 물대포()
        {
            Console.WriteLine(name + " 물대포공격");
        }
    }
    internal class Lee : PocketMon
    {
        public Lee()
        {
            name = "Lee";
            hp = 20;
            exp = 0;
            lv = 1;
        }

        public override void 밥먹기()
        {
            base.밥먹기();
            hp += 8;
        }
        public override void 잠자기()
        {
            base.잠자기();
            hp += 16;
        }
        public override bool 놀기()
        {
            base.놀기();
            hp -= 7;
            exp += 7;
            lvCheck();
            return hp > 0; //생명유무 반환
        }
        public override bool 운동하기()
        {
            base.운동하기();
            hp -= 12;
            exp += 12;
            lvCheck();
            return hp > 0; //생명유무 반환
        }

        public override void lvCheck()
        {
            base.lvCheck();
            if (exp >= 30)
            {
                lv++;
                exp -= 30;
                Console.WriteLine(name + "의 레벨 1증가. lv:" + lv);
            }
        }
        public void 넝쿨공격()
        {
            Console.WriteLine(name + " 넝쿨공격");
        }
    }
    internal class Menu
    {
        private PocketMon ch; //업캐스팅 

        public void run()
        {
            bool flag = true;
            int m = 0;
            Console.WriteLine("캐릭터 선택\n1.피카추(기본) 2.꼬부기 3.이상해");
            m = Convert.ToInt32(Console.ReadLine());
            switch (m)
            {
                case 2:
                    ch = new Gobook();
                    break;
                case 3:
                    ch = new Lee();
                    break;
                default:
                    ch = new Picachu();
                    break;
            }

            while (flag)
            {
                Console.WriteLine("1.밥먹기 2.잠자기 3.운동하기 4.놀기 5.종료 6.특기공격");
                m = Convert.ToInt32(Console.ReadLine());
                switch (m)
                {
                    case 1:
                        ch.밥먹기();
                        break;
                    case 2:
                        ch.잠자기();
                        break;
                    case 3:
                        flag = ch.운동하기();
                        break;
                    case 4:
                        flag = ch.놀기();
                        break;
                    case 5:
                        flag = false;
                        break;
                    case 6:
                        if(ch is Picachu)
                        {
                            ((Picachu)ch).전기공격();
                        }
                        else if (ch is Gobook)
                        {
                            ((Gobook)ch).물대포();
                        }
                        else if (ch is Lee)
                        {
                            ((Lee)ch).넝쿨공격();
                        }
                        break;
                }
                if (!flag)
                {
                    Console.WriteLine("캐릭터 사망. 게임종료");
                }
                ch.printState();
            }
        }

    }
}
