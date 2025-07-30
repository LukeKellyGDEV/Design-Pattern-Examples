#pragma once
#include <iostream>

class GameActor
{
	int num = 0;
public:
	GameActor(int n) { num = n; }

	void Jump()
	{
		std::cout << "Jumping! " << num << std::endl;
	}

	void FireGun()
	{
		std::cout << "Firing Gun! " << num << std::endl;
	}

	void SwapWeapon()
	{
		std::cout << "Swaping Weapon! " << num << std::endl;
	}

	void Melee()
	{
		std::cout << "Melee attack! " << num << std::endl;
	}
};

class CommandInputHandler
{
public:
	virtual void Execute(GameActor& ga) = 0;
	virtual ~CommandInputHandler() {};
};

class JumpCommand : public CommandInputHandler
{
public:
	virtual void Execute(GameActor& ga) override;
};

class FireCommand : public CommandInputHandler
{
public:
	virtual void Execute(GameActor& ga) override;
};

class SwapWeaponCommand : public CommandInputHandler
{
public:
	virtual void Execute(GameActor& ga) override;
};

class MeleeCommand : public CommandInputHandler
{
public:
	virtual void Execute(GameActor& ga) override;
};
