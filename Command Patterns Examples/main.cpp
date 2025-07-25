#include <iostream>
#include "Command.h"
#include <vector>

int main()
{
	Character luke("luke");
	std::vector<Command*> commandStack;
	Move* mOne = new Move;
	commandStack.push_back(mOne);
	Move* mTwo = new Move;
	commandStack.push_back(mTwo);
	Move* mThree = new Move;
	commandStack.push_back(mThree);
	Move* mFour = new Move;
	commandStack.push_back(mFour);
	Move* mFive = new Move;
	commandStack.push_back(mFive);

	for (int i = 0; i < commandStack.size(); i++)
		commandStack[i]->execute(luke);

	for (int i = commandStack.size() - 1; i > -1; i--)
		commandStack[i]->undo(luke);

	return 0;
}