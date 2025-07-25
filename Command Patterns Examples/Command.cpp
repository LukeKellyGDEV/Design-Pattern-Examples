#include "Command.h"

void Move::execute(Character& c)
{
	std::cout << c.name << " moved\n";
}

void Move::undo(Character& c)
{
	std::cout << c.name << " Undo moved\n";
}
