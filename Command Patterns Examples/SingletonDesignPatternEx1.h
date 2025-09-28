#pragma once
#include <iostream>

using namespace std;

class SingletonEx1
{
protected:
	SingletonEx1() = default;

public:

	int data;

	static SingletonEx1& get_instance()
	{
		static SingletonEx1 instance;
		return instance;
	}
};
