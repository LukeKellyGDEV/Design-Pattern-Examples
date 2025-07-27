#include <iostream>
#include "Command.h"
#include <conio.h>
#include <vector>
#include <stack>
#include <memory>

#define Key_UP 72
#define Key_Down 80
#define Key_Left 75
#define Key_Right 77
#define Key_RKey 'r'
#define Key_ESC 27

int main()
{

	Character luke("luke");
	std::vector<std::unique_ptr<Command>> commandStack;
	bool bTesting = true;
	bool Undo = false;
	std::unique_ptr<Move> move = std::make_unique<Move>();

	while (bTesting)
	{
		int dx = 0, dy = 0;
		char Key = _getch();
		switch (Key)
		{
		case Key_UP:
			Undo = false;
			dy = 1;
			break;
		case Key_Down:
			Undo = false;
			dy = -1;
			break;
		case Key_Left:
			Undo = false;
			dx = -1;
			break;
		case Key_Right:
			Undo = false;
			dx = 1;
			break;
		case Key_RKey:
			Undo = true;
			break;
		case Key_ESC:
			bTesting = false;
			continue;
		default:
			continue;
		}
		if (Undo)
		{
			if (!commandStack.empty())
			{
				commandStack.back()->undo(&luke);
				commandStack.pop_back();
			}
		}
		else
		{
			auto move = std::make_unique<Move>();
			move->execute(&luke, dx, dy);
			commandStack.push_back(std::move(move));
		}
		std::cout << commandStack.size() << std::endl;
	}
	return 0;
}