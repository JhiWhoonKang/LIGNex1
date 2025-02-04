using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    internal class Product
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Price { get; set; }
        public int Amount { get; set; }

        private static int cnt;

        public Product() { }
        public Product(string name, int price, int amount)
        {
            Name = name;
            Price = price;
            Amount = amount;
            Id = ++cnt;
        }
        public override string ToString()
        {
            return "id:" + Id + " / name:" + Name + " / price:" + Price
                + " / amount:" + Amount;
        }

        public override bool Equals(object obj)
        {
            if (obj != null && obj is Product)
            {
                Product p = (Product)obj;
                if (Id == p.Id && Name == p.Name)//번호와 이름이 같으면 같은 객체
                {
                    return true;
                }
            }
            return false;
        }
    }

        internal class ProductDao
        {
            private ArrayList prods;

            public ProductDao() { prods = new ArrayList(); }

            public void insert(Product p) { 
                prods.Add(p);
            }

            public Product select(Product p)
            {
                int idx = prods.IndexOf(p);
                if(idx < 0)
                {
                    return null;
                }
                return (Product)prods[idx];
            }

            public void delete(Product p)
            {
                try
                {
                    prods.Remove(p);
                }
                catch (NotSupportedException e)
                {
                    Console.WriteLine(e.Message);
                }
                
            }

            public void selectAll()
            {
                foreach (Product p in prods)
                {
                    Console.WriteLine(p);
                }
            }
        }
    internal class ProductService
    {
        private ProductDao dao;

        public ProductService() { dao = new ProductDao(); }

        public void addProd() {
            Console.WriteLine("제품등록");
            Console.Write("제품명:");
            string name = Console.ReadLine();
            Console.Write("가격:");
            int price = Int32.Parse(Console.ReadLine());
            Console.Write("수량:");
            int amount = Int32.Parse(Console.ReadLine());
            dao.insert(new Product(name, price, amount)); 
        }

        public void getProd()
        {
            Console.WriteLine("제품검색");
            Product p = new Product();
            Console.Write("검색할 제품명:");
            p.Name = Console.ReadLine();
            Console.Write("검색할 제품번호:");
            p.Id = Int32.Parse(Console.ReadLine());
            Product p2 = dao.select(p);
            if (p2 != null)
            {
                Console.WriteLine(p2);
            }
            else
            {
                Console.WriteLine("not found");
            }
        }
        public void updateProd()
        {
            Console.WriteLine("수정");
            Product p = new Product();
            Console.Write("수정할 제품명:");
            p.Name = Console.ReadLine();
            Console.Write("수정할 제품번호:");
            p.Id = Int32.Parse(Console.ReadLine());
            Product p2 = dao.select(p);
            if (p2 != null)
            {
                Console.WriteLine("수정전 상품정보");
                Console.WriteLine(p2);
                Console.Write("new가격:");
                p2.Price = Int32.Parse(Console.ReadLine());
                Console.Write("new수량:");
                p2.Amount = Int32.Parse(Console.ReadLine());
            }
            else
            {
                Console.WriteLine("not found");
            }
        }

        public void delProd()
        {
            Console.WriteLine("삭제");
            Product p = new Product();
            Console.Write("삭제할 제품명:");
            p.Name = Console.ReadLine();
            Console.Write("삭제할 제품번호:");
            p.Id = Int32.Parse(Console.ReadLine());
            dao.delete(p);
        }
        public void printAll()
        {
            dao.selectAll();
        }
    }

    internal class Menu
    {
        private ProductService service;

        public Menu()
        {
            service = new ProductService();
        }

        public void run()
        {
            
            bool flag = true;
            int m = 0;
            while (flag)
            {
                Console.WriteLine("1.추가 2.검색 3.수정 4.삭제 5.전체출력 6.종료");
                m = Int32.Parse(Console.ReadLine());
                switch (m)
                {
                    case 1:
                        service.addProd();
                        break;
                    case 2:
                        service.getProd();
                        break;
                    case 3:
                        service.updateProd();
                        break;
                    case 4:
                        service.delProd();
                        break;
                    case 5:
                        service.printAll();
                        break;
                    case 6:
                        flag = false;
                        break;
                }
            }
        }
    }
}
