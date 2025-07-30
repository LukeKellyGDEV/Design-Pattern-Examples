#pragma once
#include <iostream>
#include <string>
#include <forward_list>
class Observer
{
public:	
	virtual ~Observer() {}
	virtual void OnNotify() = 0;
};

class Watcher : public Observer
{
public:
	explicit Watcher(const std::string& name) : mName(name)
	{
	}

	void OnNotify() override
	{
		std::cout << "watcher-" << mName << std::endl;
	}

private:
	std::string mName;
};

class Subject
{
public:
	virtual ~Subject() {}

	void AddObserver(Observer* observer)
	{
		mObservers.push_front(observer);
	}
	void RemoveObserver(Observer* observer)
	{
		mObservers.remove(observer);
	}

	void NotifyAll()
	{
		for (auto& element : mObservers)
		{
			element->OnNotify();
		}
	}

private:
	std::forward_list<Observer*> mObservers;
};

class SomeSubject : public Subject
{

};

