#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class ISubscriber
{
public:
	virtual void notify(string msg) = 0;
};

class User : public ISubscriber
{
private:
	int UserId;
public:
	User(int userId)
	{
		this->UserId = userId;
	}
	void notify(string msg)
	{
		cout << "User " << UserId << " recieved msg " << msg << endl;
	}
};

class Group
{
private:
	list<ISubscriber*> subscribers;

public:
	void subscribe(ISubscriber* subscriber)
	{
		subscribers.push_back(subscriber);
	}
	void unsubscribe(ISubscriber* subscriber)
	{
		subscribers.remove(subscriber);
	}
	void notify(string msg) {
		for (auto subs : subscribers)
		{
			subs->notify(msg);
		}
	}
};

