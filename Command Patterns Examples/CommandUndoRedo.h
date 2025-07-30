#pragma once
#include <iostream>
#include <string>

struct Character
{
	int x;
	int y;
	std::string name;
	Character(std::string newName) : name(newName), x(0), y (0){}
	void move(int newX, int newY, bool bUndo) 
	{
		if (bUndo)
		{
			x -= newX;
			y -= newY;
		}
		else
		{
			x += newX;
			y += newY;
		}
	}
	void printPosition()
	{
		std::cout << "Characters Position in the World: " << x << "," << y << std::endl;
		std::cout << "\n";
	}
};

class CommandUndoRedo
{
public :
	virtual ~CommandUndoRedo() {}
	virtual void execute(Character* c, int XValue, int YValue) = 0;
	virtual void undo(Character* c) = 0;
	virtual void redo(Character* c) = 0;
};

class Move : public CommandUndoRedo
{
public:
	void execute(Character* c, int XValue, int YValue);
	void undo(Character* c);
	void redo(Character* c);
private:
	int x;
	int y;
};

