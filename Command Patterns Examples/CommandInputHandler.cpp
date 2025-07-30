#include "CommandInputHandler.h"


void JumpCommand::Execute(GameActor& ga)
{
	ga.Jump();
}

void FireCommand::Execute(GameActor& ga)
{
	ga.FireGun();
}

void SwapWeaponCommand::Execute(GameActor& ga)
{
	ga.SwapWeapon();
}

void MeleeCommand::Execute(GameActor& ga)
{
	ga.Melee();
}
