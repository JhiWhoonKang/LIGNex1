#include "IObserver.h"
#include "ISubject.h"

class Observer : public IObserver 
{
public:
	Observer(ISubject& subject)
	{

	}
	
	~Observer() {};
	
	void Update() 
	{

	}
private:

};