#include <iostream>
#include "Command.h"
#include <conio.h>
#include <vector>
#include <stack>

#define Key_UP 72
#define Key_Down 80
#define Key_Left 75
#define Key_Right 77
#define Key_RKey 'r'
#define Key_ESC 27

int main()
{
	srand(time(NULL));

	Character luke("luke");
	std::stack<Command*> commandStack;
	bool bTesting = true;
	bool Undo = false;

	while (bTesting)
	{
		int dx = 0, dy = 0;
		char Key = _getch();
		Move* move = new Move();
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
			std::cout << "Poopie" << std::endl;
			break;
		case Key_ESC:
			bTesting = false;
			continue;
		default:
			continue;
		}


		if (Undo)
		{
			commandStack.pop();
			move->undo(luke);
		}
		else
		{
			commandStack.push(move);
			move->execute(luke, dx, dy);
		}
	}
	return 0;
}