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
            string str = streamReader.ReadLine();
            Console.WriteLine("클라이언트가 보낸 메시지:" + str);

            StreamWriter streamWriter = new StreamWriter(stream);
            streamWriter.WriteLine(str);
            streamWriter.Flush();
            tcpClient.Close();
            Console.WriteLine("클라이언트와 연결 끊음");
        }
        
    }
}
