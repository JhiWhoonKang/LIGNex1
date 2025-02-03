using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp7
{
    internal interface IDao
    {
        void select();
        void insert();
        void update();
        void delete();
    }

    class IDaoOracleImpl : IDao
    {
        public void delete()
        {
            Console.WriteLine("oracle delete");
        }

        public void insert()
        {
            Console.WriteLine("oracle insert");
        }

        public void select()
        {
            Console.WriteLine("oracle select");
        }

        public void update()
        {
            Console.WriteLine("oracle update");
        }
    }
    class IDaoMysqlImpl : IDao
    {
        public void delete()
        {
            Console.WriteLine("Mysql delete");
        }

        public void insert()
        {
            Console.WriteLine("Mysql insert");
        }

        public void select()
        {
            Console.WriteLine("Mysql select");
        }

        public void update()
        {
            Console.WriteLine("Mysql update");
        }
    }

    class Service
    {
        private IDao dao;
        public Service(IDao dao) //의존성 주입
        {
            //dao = new IDaoOracleImpl();//의존성 높음
            this.dao = dao;
        }

        public void add()
        {
            dao.insert();
        }
        public void get()
        {
            dao.select();
        }
        public void edit()
        {
            dao.update();
        }
        public void del()
        {
            dao.delete();
        }
    }
}
