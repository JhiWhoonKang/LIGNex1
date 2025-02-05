using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace ConsoleApp9
{
    internal class Memo
    {
        private string path = "C:\\memo\\";

        public Memo()
        {
            DirectoryInfo di = new DirectoryInfo(path);
            if (!di.Exists)//디렉토리 존재 확인. 없으면 실행
            {
                di.Create(); //디렉토리 생성
                Console.WriteLine("memo 디렉토리 생성됨");
            }
        }

        public string readFileList()
        {
            DirectoryInfo di = new DirectoryInfo(path);
            FileInfo[] fi = di.GetFiles("*.txt");
            for (int i = 0; i < fi.Length; i++)
            {
                Console.WriteLine(i + ": " + fi[i].Name);
            }
            if (fi.Length == 0)
            {
                Console.WriteLine("읽을 파일 없음");
                return null;
            }

            Console.WriteLine("파일 번호 입력");
            int num = Int32.Parse(Console.ReadLine());
            if (num < 0 || num >= fi.Length)
            {
                Console.WriteLine("잘못된 번호. 읽기 중단");
                return null;
            }
            return fi[num].FullName;
        }

        public void read()
        {
            Console.WriteLine("파일읽기");
            string fname = readFileList();
            if (fname != null)
            {
                Console.WriteLine(File.ReadAllText(fname));
            }
            
        }

        public void write()
        {
            bool flag = false;
            int mode = 0;//0:덮어쓰기. 1:이어쓰기
            string fname = "";
            Console.WriteLine("파일쓰기");
            DirectoryInfo di = new DirectoryInfo(path);
            do
            {
                flag = false;
                Console.Write("write file name:");
                fname = Console.ReadLine();
                if (File.Exists(path + fname))
                {
                    Console.Write("1.다시입력(기본) 2.덮어쓰기 3.이어쓰기");
                    int num = Int32.Parse(Console.ReadLine());
                    switch (num)
                    {
                        case 2:
                            break;
                        case 3:
                            mode = 1;
                            break;
                        default:
                            flag = true;
                            break;
                    }
                }
            } while (flag);
            StringBuilder stringBuilder = new StringBuilder();
            Console.WriteLine("파일 내용 입력. 멈추려면 /stop입력");
            flag = true;
            string str = "";
            while (flag)
            {
                str = Console.ReadLine();
                if (str.StartsWith("/stop"))
                {
                    break;
                }
                stringBuilder.Append(str + "\n");
            }
            if (mode == 1)
            {
                File.AppendAllText(path + fname, stringBuilder.ToString());
            }
            else
            {
                File.WriteAllText(path + fname, stringBuilder.ToString());
            }
        }
        public void delete()
        {
            Console.WriteLine("파일삭제");
            string fname = readFileList();
            
            if (fname != null)
            {
                File.Delete(fname);
            }
        }
    }
}
