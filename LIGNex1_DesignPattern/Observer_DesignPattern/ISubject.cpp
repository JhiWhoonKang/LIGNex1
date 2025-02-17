#include "ISubject.h"
#include "IObserver.h"
#include <list>

class Subject :ISubject
{
private:
	list<IObserver*> observer_list;

public:
	~Subject() {};

	void attach(IObserver *observer)
	{
		observer_list.push_back(observer);
	}
	void detach(IObserver* observer)
	{
		observer_list.remove(observer);
	}
	void notify()
	{

	}
};
