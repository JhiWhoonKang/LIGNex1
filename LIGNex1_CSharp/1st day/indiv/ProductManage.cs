using System;
using System.Collections;

namespace LIGNex1_CSharp
{
    internal class ProductManage
    {
        public static int NextProductId = 0;
        public int ProductId { get; private set; }   // 제품 번호
        public string Name { get; set; }     // 제품명
        public double Price { get; set; }    // 가격
        public int Quantity { get; set; }    // 수량

        public ProductManage(string name, double price, int quantity)
        {
            ProductId = ++NextProductId;
            Name = name;
            Price = price;
            Quantity = quantity;
        }

        public static void AddProduct(ArrayList productList)
        {
            Console.Write("제품명: ");
            string name = Console.ReadLine();
            Console.Write("가격: ");
            double price = Convert.ToDouble(Console.ReadLine());
            Console.Write("수량: ");
            int quantity = Convert.ToInt32(Console.ReadLine());

            productList.Add(new ProductManage(name, price, quantity));
            Console.WriteLine("제품이 추가되었습니다.");
        }

        public static void EditProduct(ArrayList productList)
        {
            Console.Write("수정할 제품 번호 입력: ");
            int id = Convert.ToInt32(Console.ReadLine());

            foreach (ProductManage product in productList)
            {
                if (product.ProductId == id)
                {
                    Console.Write("새로운 제품명: ");
                    product.Name = Console.ReadLine();
                    Console.Write("새로운 가격: ");
                    product.Price = Convert.ToDouble(Console.ReadLine());
                    Console.Write("새로운 수량: ");
                    product.Quantity = Convert.ToInt32(Console.ReadLine());

                    Console.WriteLine("제품 정보가 수정되었습니다.");
                    return;
                }
            }
            Console.WriteLine("해당 제품을 찾을 수 없습니다.");
        }

        public static void DeleteProduct(ArrayList productList)
        {
            Console.Write("삭제할 제품 번호 입력: ");
            int id = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < productList.Count; i++)
            {
                if (((ProductManage)productList[i]).ProductId == id)
                {
                    productList.RemoveAt(i);
                    Console.WriteLine("제품이 삭제되었습니다.");
                    return;
                }
            }
            Console.WriteLine("해당 제품을 찾을 수 없습니다.");
        }

        public static void PrintProducts(ArrayList productList)
        {
            Console.WriteLine("\n현재 제품 목록:");
            foreach (ProductManage product in productList)
            {
                product.DisplayInfo();
            }
        }

        public void DisplayInfo()
        {
            Console.WriteLine($"번호: {ProductId}, 제품명: {Name}, 가격: {Price}원, 수량: {Quantity}개");
        }        
    }  
}