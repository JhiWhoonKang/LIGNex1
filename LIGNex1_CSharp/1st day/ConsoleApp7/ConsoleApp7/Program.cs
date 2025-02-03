// See https://aka.ms/new-console-template for more information
using ConsoleApp7;

Ianimal[] arr = { new Dog(), new Cat(), new 고슴도치() };
ConsoleApp7.Action a = new ConsoleApp7.Action();
foreach(Ianimal b in arr)
{
    a.action(b);
}

Service service = new Service(new IDaoMysqlImpl());
service.add();
service.get();
service.edit();
service.del();