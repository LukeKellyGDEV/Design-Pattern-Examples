#include "Command.h"
#include <ctime>
#include <cstdlib>

void Move::execute(Character* c, int XValue, int YValue)
{
	x = XValue;
	y = YValue;
	c->move(XValue, YValue, false);
	std::cout << c->name << " moved " << x << "," << y << std::endl;
	c->printPosition();
}

void Move::undo(Character* c)
{
	c->move(x, y , true);
	std::cout << c->name << " Undo " << -x << "," << -y << std::endl;
	c->printPosition();
}
