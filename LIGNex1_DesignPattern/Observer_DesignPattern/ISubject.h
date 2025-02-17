#pragma once
using namespace std;

class ISubject
{
public:
	virtual void notify();
	virtual void attach();
	virtual void detach();
};

