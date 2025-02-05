// See https://aka.ms/new-console-template for more information
using System.Net.Sockets;

TcpClient client = new TcpClient();
client.Connect("localhost", 1234); //ip:localhost. port:1234 서버로 연결 요청
NetworkStream stream = client.GetStream();
Console.WriteLine("클라이언트 시작");
StreamWriter writer = new StreamWriter(stream);
StreamReader reader = new StreamReader(stream);
Console.Write("id:");
string id = Console.ReadLine();
writer.WriteLine(id);
writer.Flush();

while (true)
{
    string str = Console.ReadLine();
    if (str.StartsWith("/stop"))
    {
        writer.WriteLine(str);
        writer.Flush();
        break;
    }
    writer.WriteLine(str);
    writer.Flush();
    Console.WriteLine(reader.ReadLine());
}

client.Close();
