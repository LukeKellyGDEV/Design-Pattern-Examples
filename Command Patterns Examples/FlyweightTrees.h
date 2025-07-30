#pragma once
#include <iostream>
#include <map>

struct Tree
{
	//Extrinsic state
	float x, y, z;

	Tree(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {

	}
};

//This is what we want to share (Flyweight)
struct Model
{
	struct Mesh
	{
		int date = 100;
	};

	Mesh m;
	//Bark b;
	//Leaves l;

	void DrawOperation(Tree& extrinisicState)
	{
		std::cout << extrinisicState.x << ","
				  << extrinisicState.y << ","
				  << extrinisicState.z << std::endl;
	}
};

//also Known as resource manager.
struct FlyWeightModelFactory
{
	std::map<std::string, std::shared_ptr<Model>> mModelFlyweights;

	std::shared_ptr<Model> GetFlyWeight(std::string key)
	{
		auto iterator = mModelFlyweights.find(key);
		if (iterator != mModelFlyweights.end())
		{
			std::cout << "Reusing " << key << std::endl;
			return iterator->second;
		}
		else
		{
			std::shared_ptr<Model> model = std::make_shared<Model>();
			mModelFlyweights[key] = model;
			return model;
		}
	}

};
