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
	Subject() {}
	virtual ~Subject() {}
	// message is our 'enum' (PLAYSOUND, PHYSICSEVENT, LOG)
	void AddObserver(int message, Observer* observer)
	{
		//Search for enum
		auto it = mObservers.find(message);
		//Checks if the end, this means it didnt find it.
		if (it == mObservers.end())
		{
			mObservers[message] = ObserversList();
		}
		mObservers[message].push_front(observer);
	}
	void RemoveObserver(int message, Observer* observer)
	{
		auto it = mObservers.find(message);
		if (it != mObservers.end())
		{
			it->second.remove(observer);
			//ObserversList& list = mObservers[message];
			//for (ObserversList::iterator li = list.begin();
			//							 li != list.end();)
			//{
			//	if ((*li) == observer)
			//	{
			//		list.remove(observer);
			//	}
			//	else
			//	{
			//		++li;
			//	}
			//}
		}	
	}

	void NotifyAll()
	{
		for (ObserversMap::iterator it = mObservers.begin();
			it != mObservers.end(); ++it)
		{
			for (auto& element : mObservers[it->first])
			{
				element->OnNotify();
			}
		}
		
	}

	void Notify(int message)
	{
		auto it = mObservers.find(message);
		if (it != mObservers.end())
		{
			for (auto& element : mObservers[message])
			{
				element->OnNotify();
			}
		}
	}

private:
	  typedef std::forward_list<Observer*> ObserversList;
	  typedef std::map<int, ObserversList> ObserversMap;
	  ObserversMap mObservers;
};

class Watcher : public Observer
{
public:
	explicit Watcher(Subject& subject, int message, const std::string& name) : mSubject(subject), mMessage(message),  mName(name)
	{
		mSubject.AddObserver(mMessage, this);
	}

	~Watcher()
	{
		mSubject.RemoveObserver(mMessage, this);
	}

	void OnNotify()
	{
		std::cout << "watcher-" << mName << std::endl;
	}

private:
	std::string mName;
	int mMessage;
	Subject& mSubject;
};



class SomeSubject : public Subject
{
public:
	enum MessageTypes {
		PLAYSOUND,
		HANDLEPHYSICS,
		LOG
	};
};

