// See https://aka.ms/new-console-template for more information
using System.Net;
using System.Net.Sockets;
using EchoServer;

IPAddress iPAddress = new IPAddress(0);//로컬 주소 ip 객체 생성
//localhost. 포트:1234로 리스너 생성(클라이언트의 요청 받을 준비)
TcpListener listener = new TcpListener(iPAddress, 1234);
listener.Start();//준비 완료
Console.WriteLine("서버시작");
MyServer es = new MyServer();
try
{
    while (true)
    {
        TcpClient tcpClient = listener.AcceptTcpClient();
        (new Thread(new ParameterizedThreadStart(es.msg))).Start(tcpClient);
    }
}catch(Exception e)
{
    Console.WriteLine(e.ToString());
}
finally
{
    listener.Stop();
}


Console.WriteLine("서버 종료");
