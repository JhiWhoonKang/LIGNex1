using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace ChatClient
{
    class Client
    {
        private NetworkStream stream;
        private StreamWriter writer;
        private StreamReader reader;
        private TcpClient client;
        public Client(TcpClient client)
        {
            this.client = client;
            stream = client.GetStream();
            writer = new StreamWriter(stream);
            reader = new StreamReader(stream);
        }

        public void read()
        {
            while (true)
            {
                string str = "";
                str = reader.ReadLine();
                Console.WriteLine(str);
                if (str.StartsWith("exit"))
                {

                    break;
                }
            }
            client.Close();
        }

        public void write()
        {
            while (true)
            {
                string str = "";
                str = Console.ReadLine();
                writer.WriteLine(str);
                writer.Flush();
                if (str.StartsWith("exit"))
                {
                    break;
                }
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {

            TcpClient client = new TcpClient();
            string serverIP = "localhost";
            client.Connect(serverIP, 1234);
            Client c = new Client(client);
            Thread t1 = new Thread(new ThreadStart(c.read));
            t1.Start();
            Thread t2 = new Thread(new ThreadStart(c.write));
            t2.Start();

        }
    }

}
