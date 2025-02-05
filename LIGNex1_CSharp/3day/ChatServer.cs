using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace ChatServer
{
    class NetServer
    {
        private TcpClient client;
        private NetworkStream stream;
        private StreamWriter writer;
        private StreamReader reader;

        public NetServer(TcpClient client)
        {
            Console.WriteLine("새 클라이언트 접속");
            this.client = client;
            stream = client.GetStream();
            writer = new StreamWriter(stream);
            reader = new StreamReader(stream);
        }
        public void run()
        {
            string str = "";
            while (true)
            {
                str = reader.ReadLine();
                Console.WriteLine(str);
                lock (Program.list)
                {
                    if (str.StartsWith("exit"))
                    {
                        write(str);
                        break;
                    }
                    else
                    {
                        for (int i = 0; i < Program.list.Count; i++)
                        {
                            Program.list[i].write(str);
                        }
                    }
                }

            }
            client.Close();
            lock (Program.list)
            {
                int idx = Program.list.IndexOf(this);
                Program.list.RemoveAt(idx);
            }
        }

        public void write(string str)
        {
            writer.WriteLine(str);
            writer.Flush();
        }
    }
    class Program
    {
        public static List<NetServer> list = new List<NetServer>();

        static void Main(string[] args)
        {
            IPAddress addr = new IPAddress(0);
            TcpListener server = new TcpListener(addr, 1234);
            server.Start();
            Console.WriteLine("서버시작");
            while (true)
            {
                TcpClient client = server.AcceptTcpClient();
                NetServer ns = new NetServer(client);
                lock (list)
                {
                    list.Add(ns);
                }
                Thread t = new Thread(new ThreadStart(ns.run));
                t.Start();
            }
            server.Stop();
        }
    }

}
