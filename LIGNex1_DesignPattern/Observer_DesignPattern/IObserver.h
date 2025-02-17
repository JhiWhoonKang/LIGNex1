#pragma once
using namespace std;

class IObserver
{
public:
	virtual void update() = 0;
};