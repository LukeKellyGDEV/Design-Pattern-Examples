#pragma once
#include <iostream>
#include <string>

struct Character
{
	int x;
	int y;
	std::string name;
	Character(std::string newName) : name(newName){}
	void move(int newX, int newY) 
	{
		x = newX;
		y = newY;  
	}
};

class Command
{
public :
	virtual ~Command() {}
	virtual void execute(Character& c) = 0;
	virtual void undo(Character& c) = 0;
};

class Move : public Command
{
public:
	void execute(Character& c);
	void undo(Character& c);
};

