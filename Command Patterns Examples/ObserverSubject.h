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

class Watcher : public Observer
{
public:
	explicit Watcher(Subject& subject, const std::string& name) : mSubject(subject), mName(name)
	{
		mSubject.AddObserver(this);
	}

	~Watcher()
	{
		mSubject.RemoveObserver(this);
	}

	void OnNotify() override
	{
		std::cout << "watcher-" << mName << std::endl;
	}

private:
	std::string mName;
	Subject& mSubject;
};



class SomeSubject : public Subject
{

};

