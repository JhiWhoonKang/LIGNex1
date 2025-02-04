using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LIGNex1_CSharp 
{
    internal class day2
    {
        static void Main(string[] args)
        {
            ArrayList productList = new ArrayList();

            // 제품 추가
            productList.Add(new ProductManage("노트북", 1500000, 5));
            productList.Add(new ProductManage("스마트폰", 1000000, 10));
            productList.Add(new ProductManage("태블릿", 800000, 7));

            while (true)
            {
                Console.WriteLine("\n📦 제품 관리 시스템");
                Console.WriteLine("1. 제품 추가");
                Console.WriteLine("2. 제품 수정");
                Console.WriteLine("3. 제품 삭제");
                Console.WriteLine("4. 제품 목록 출력");
                Console.WriteLine("5. 종료");
                Console.Write("선택: ");
                int choice = Convert.ToInt32(Console.ReadLine());

                switch (choice)
                {
                    case 1:
                        ProductManage.AddProduct(productList);
                        break;
                    case 2:
                        ProductManage.EditProduct(productList);
                        break;
                    case 3:
                        ProductManage.DeleteProduct(productList);
                        break;
                    case 4:
                        ProductManage.PrintProducts(productList);
                        break;
                    case 5:
                        Console.WriteLine("프로그램을 종료합니다.");
                        return;
                    default:
                        Console.WriteLine("잘못된 입력입니다. 다시 선택해주세요.");
                        break;
                }
            }
        }
    }
}
