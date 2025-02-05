// See https://aka.ms/new-console-template for more information
using System.Net.Sockets;

TcpClient client = new TcpClient();
client.Connect("localhost", 1234); //ip:localhost. port:1234 서버로 연결 요청
NetworkStream stream = client.GetStream();
Console.WriteLine("클라이언트 시작");
StreamWriter writer = new StreamWriter(stream);
writer.WriteLine("echo message");
writer.Flush();
StreamReader reader = new StreamReader(stream);
string str = reader.ReadLine();
Console.WriteLine("서버에서 받은 메시지:"+str);
client.Close();
