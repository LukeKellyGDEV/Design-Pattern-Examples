#include <iostream>
#include "CommandUndoRedo.h"
#include "CommandInputHandler.h"
#include "FlyweightTrees.h"
#include "ObserverSubject.h"
#include "ObserverGroup_User.h"
#include "PrototypeCar.h"
#include "PrototypeBullet.h"
#include <conio.h>
#include <vector>
#include <stack>
#include <memory>
#include <string>
#include <forward_list>

#define Key_UP 72
#define Key_Down 80
#define Key_Left 75
#define Key_Right 77
#define Key_RKey 'r'
#define Key_UKey 'u'
#define Key_ESC 27

bool bTesting = true;
void CommandPatternUndoRedo();
void CommandPatternInputHandler();
void FlyWeightPatternTrees();
void ObserverPatternGroupUser();
void ObserverPatternSubject();
void PrototypePatternCar();
void PrototypePatternBullet();

int main()
{
	//CommandPatternUndoRedo();
	//CommandPatternInputHandler();
	//FlyWeightPatternTrees();
	//ObserverPatternGroupUser();
	//ObserverPatternSubject();
	//PrototypePatternCar();
	PrototypePatternBullet();
	return 0;
}

void CommandPatternUndoRedo()
{
	Character luke("luke");
	std::vector<std::unique_ptr<CommandUndoRedo>> commandStack;
	std::vector<std::unique_ptr<CommandUndoRedo>> RedoStack;
	bool Undo = false;
	bool redo = false;
	std::unique_ptr<Move> move = std::make_unique<Move>();

	while (bTesting)
	{
		int dx = 0, dy = 0;
		char Key = _getch();
		switch (Key)
		{
		case Key_UP:
			Undo = false;
			redo = false;
			dy = 1;
			break;
		case Key_Down:
			Undo = false;
			redo = false;
			dy = -1;
			break;
		case Key_Left:
			Undo = false;
			redo = false;
			dx = -1;
			break;
		case Key_Right:
			Undo = false;
			redo = false;
			dx = 1;
			break;
		case Key_RKey:
			Undo = false;
			redo = true;
			break;
		case Key_UKey:
			Undo = true;
			redo = false;
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
				auto& lastcommand = commandStack.back();
				lastcommand->undo(&luke);
				RedoStack.push_back(std::move(lastcommand));
				commandStack.pop_back();
			}
		}
		else if (redo)
		{
			if (!RedoStack.empty())
			{
				auto redoCommand = std::move(RedoStack.back());
				redoCommand->redo(&luke);
				commandStack.push_back(std::move(redoCommand));
				RedoStack.pop_back();
			}
		}
		else
		{
			auto move = std::make_unique<Move>();
			move->execute(&luke, dx, dy);
			commandStack.push_back(std::move(move));
			RedoStack.clear();
		}
	}
}

void CommandPatternInputHandler()
{
	GameActor a(1);
	GameActor b(2);

	std::unique_ptr<CommandInputHandler> UpButton = std::make_unique<JumpCommand>();
	std::unique_ptr<CommandInputHandler> DownButton = std::make_unique<FireCommand>();
	std::unique_ptr<CommandInputHandler> LeftButton = std::make_unique<SwapWeaponCommand>();
	std::unique_ptr<CommandInputHandler> RightButton = std::make_unique<MeleeCommand>();
	
	while (bTesting)
	{
		char Key = _getch();
		switch (Key)
		{
		case Key_UP:
			UpButton->Execute(a);
			break;
		case Key_Down:
			DownButton->Execute(a);
			break;
		case Key_Left:
			LeftButton->Execute(b);
			break;
		case Key_Right:
			RightButton->Execute(b);
			break;
		case Key_RKey:
			UpButton = std::make_unique<FireCommand>();// this changes the UpButton to a fireCommand.
			break;
		case Key_ESC:
			bTesting = false;
			continue;
		default:
			continue;
		}
	}
}

void FlyWeightPatternTrees()
{
	Tree treeOne(1.0f, 2.0f, 3.0f);
	Tree treeTwo(4.0f, 12.0f, 13.0f);
	Tree treeThree(100.0f, 200.0f, 300.0f);

	//Model model;

	//model.DrawOperation(treeOne);
	//model.DrawOperation(treeTwo);

	FlyWeightModelFactory factory;
	
	factory.GetFlyWeight("Oak Tree")->DrawOperation(treeOne);
	factory.GetFlyWeight("Birch Tree")->DrawOperation(treeTwo);
	factory.GetFlyWeight("Oak Tree")->DrawOperation(treeThree);
}

void ObserverPatternGroupUser()
{
	Group* group = new Group;

	User* user1 = new User(1);
	User* user2 = new User(2);
	User* user3 = new User(3);

	group->subscribe(user1);
	group->subscribe(user2);
	group->subscribe(user3);

	group->notify("new msg");

	group->unsubscribe(user1);
	group->notify("Brand new msg");

}

void ObserverPatternSubject()
{
	SomeSubject subject;
	Watcher Watcher1(subject, SomeSubject::PLAYSOUND, "Watcher1");
	Watcher Watcher2(subject, SomeSubject::HANDLEPHYSICS, "Watcher2");
	Watcher Watcher3(subject, SomeSubject::LOG, "Watcher3");

	subject.NotifyAll();

	subject.Notify(SomeSubject::LOG);

	//subject.RemoveObserver(&Watcher3);

}

void PrototypePatternCar()
{
	std::vector<std::unique_ptr<Car>> cars;

	//Default
	const auto prototypeRaceCar = 
		std::make_unique<RaceCar>("", "", 0);

	//Default
	const auto prototypeFormulaOneCar =
		std::make_unique<FormulaOneCar>("", "", 0);

	auto red_Porsche = prototypeRaceCar->Clone();
	red_Porsche->CarType("Porsche", "Red", 190);

	cars.emplace_back(std::move(red_Porsche));

	auto Orange_Mustang = prototypeRaceCar->Clone();
	Orange_Mustang->CarType("Mustang", "Orange", 205);

	cars.emplace_back(std::move(Orange_Mustang));

	auto White_AstonMartin = prototypeFormulaOneCar->Clone();
	White_AstonMartin->CarType("Aston Martin", "White", 265);

	cars.emplace_back(std::move(White_AstonMartin));

	auto Green_Mercedes = prototypeRaceCar->Clone();
	Green_Mercedes->CarType("Mercedes", "Green", 175);

	cars.emplace_back(std::move(Green_Mercedes));

	for (auto& i : cars)
	{
		i->Print();
	}
}

void PrototypePatternBullet()
{
	BulletFactory bulletFactory;

	auto Bullet = bulletFactory.createBullet(STANDARD);
	Bullet->fire(90);

	cout << endl;
	
	Bullet = bulletFactory.createBullet(PIERCING);
	Bullet->fire(180);

	cout << endl;
	
	Bullet = bulletFactory.createBullet(EXPLOSIVE);
	Bullet->fire(270);
}
