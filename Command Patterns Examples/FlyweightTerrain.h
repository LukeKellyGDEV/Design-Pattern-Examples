#pragma once
enum Terrain
{
	TERRAIN_GRASS,
	TERRAIN_HILL,
	TERRAIN_RIVER
};

class World
{
private:


	float WIDTH = 100;
	float HEIGHT = 100;

	Terrain Tiles_[WIDTH][HEIGHT];
};