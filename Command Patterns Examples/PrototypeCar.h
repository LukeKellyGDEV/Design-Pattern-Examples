#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Car
{
public:
	Car(string model, string colour, int TopSpeed) 
		: mModel(move(model)), mColour(move(colour)), mTopSpeed(TopSpeed) {}

	virtual std::unique_ptr<Car> Clone() const = 0;

	void CarType(string Model, string Colour, int TopSpeed)
	{
		mModel = Model;
		mColour = move(Colour);
		mTopSpeed = TopSpeed;
	}

	void Print() const {
		cout << mModel << " | " << mColour << " | " << mTopSpeed << " MPH" << endl;
	}

private:
	string mModel;
	string mColour;
	int mTopSpeed;
};

class RaceCar : public Car
{
public:
	RaceCar(string model, string colour, int TopSpeed)
		: Car(move(model), move(colour), TopSpeed) {}

	virtual std::unique_ptr<Car> Clone() const override
	{
		return std::make_unique<RaceCar>(*this);
	}
};

class FormulaOneCar : public Car
{
public:
	FormulaOneCar(string model, string colour, int TopSpeed)
		: Car(move(model), move(colour), TopSpeed) {
	}

	virtual std::unique_ptr<Car> Clone() const override
	{
		return std::make_unique<FormulaOneCar>(*this);
	}
};
