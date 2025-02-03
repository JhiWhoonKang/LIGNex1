using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;

namespace LIGNex1_CSharp
{
    class Car
    {
        public string model;
        public int door;
        public string color;

        public Car()
        {
            model = "기본차";
            door = 3;
            color = "검정";
        }

        public Car(string model, int door, string color)
        {
            this.model = model;
            this.door = door;
            this.color = color;
        }

        public void printInfo()
        {
            Console.WriteLine("model: " + model + " / door: " + door
                + " / color: " + color);        
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Car c1 = new Car();
            c1.model = "마이카";
            c1.door = 5;
            c1.printInfo();

            Car c2 = new Car("두번째카", 4, "노랑");
            c2.printInfo();

            int[] arr = { 1, 2, 3 };
            int[] arr2 = new int[5];
            int i;
            for (i = 0; i < arr2.Length; ++i)
            {
                arr2[i] = i + 1;
            }

            for (i = 0; i < arr.Length; ++i)
            {
                Console.Write(arr[i] + "\t");
            }
            Console.WriteLine();
            
            for (i = 0; i < arr2.Length; ++i)
            {
                Console.Write(arr2[i] + "\t");
            }
            Console.WriteLine();

            string[] str = { "aaa", "bbb" };
            for (i = 0; i < str.Length; ++i)
            {
                Console.Write(str[i] + "\t");
            }
            Console.WriteLine();

            Car[] cars = new Car[3];        // 방만 만듦
            cars[0] = new Car();            // 각 방에 객체를 생성해서 참조값 할당
            cars[0].model = "sdf";
            cars[0].color = "yellow";
            cars[0].door = 3;
            cars[0].printInfo();

            cars[1] = new Car();
            cars[1].model = "sasddf";
            cars[1].color = "red";
            cars[1].door = 2;
            cars[1].printInfo();

            cars[2] = new Car();
            cars[2].model = "sdffdfd";
            cars[2].color = "black";
            cars[2].door = 1;
            cars[2].printInfo();

            Car[] cars2 = { new Car("aaa", 3, "bbb"), new Car("ccc", 4, "ddd"), new Car("eee", 5, "fff") };
            for (i = 0; i < cars.Length; ++i)
            {
                cars[i].printInfo();
            }
        }
    }
}