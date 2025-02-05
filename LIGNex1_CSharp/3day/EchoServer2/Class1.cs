using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace EchoServer
{
    internal class MyServer
    {
        public void msg(object obj)
        {
            if (obj == null)
            {
                return;
            }
            TcpClient tcpClient = (TcpClient)obj;
            NetworkStream stream = tcpClient.GetStream();
            StreamReader streamReader = new StreamReader(stream);
            StreamWriter streamWriter = new StreamWriter(stream);
            string id = streamReader.ReadLine();

            while (true)
            {
                string str = streamReader.ReadLine();
                
                if (str.StartsWith("/stop"))
                {
                    Console.WriteLine(id + "님 퇴장");
                    break;
                }
                Console.WriteLine(id + "님:" + str);
                streamWriter.WriteLine(id + "님:" + str);
                streamWriter.Flush();
            }
            
            tcpClient.Close();
            Console.WriteLine("클라이언트와 연결 끊음");
        }
        
    }
}
