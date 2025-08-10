#pragma once
#include <iostream>

using namespace std;

class Singleton
{
protected:
	Singleton() = default;

public:

	int data;

	static Singleton& get_instance()
	{
		static Singleton instance;
		return instance;
	}
};
