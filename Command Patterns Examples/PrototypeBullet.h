#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;

enum BulletType
{
	STANDARD,
	PIERCING,
	EXPLOSIVE
};

class Bullet
{
protected:
	string BulletName;
	float Speed;
	float FirePower;
	float DamagePower;
	float Direction;

public:
	Bullet() {}
	Bullet(string bulletname, float speed, float firepower, float damagepower)
	: BulletName(bulletname), Speed(speed), FirePower(firepower), DamagePower(damagepower)
	{}
	virtual ~Bullet() {}
	virtual unique_ptr<Bullet> Clone() = 0;
	void fire(float direction)
	{
		Direction = direction;
		
		cout << "Name         : " << BulletName << endl
			 << "Speed        : " << Speed << endl
		     << "FirePower    : " << FirePower << endl
			 << "DamagePower  : " << DamagePower << endl
			 << "Direction    : " << Direction << endl;
	}
};

class StandardBullet : public Bullet
{
public:
	StandardBullet(string bulletname, float speed, float firepower, float damagepower)
		: Bullet(bulletname, speed, firepower, damagepower)
	{}

	unique_ptr<Bullet> Clone() override
	{
		return make_unique<StandardBullet>(*this);
	}
};

class PiercingBullet : public Bullet
{
public:
	PiercingBullet(string bulletname, float speed, float firepower, float damagepower)
		: Bullet(bulletname, speed, firepower, damagepower)
	{
	}

	unique_ptr<Bullet> Clone() override
	{
		return make_unique<PiercingBullet>(*this);
	}
};

class ExplosiveBullet : public Bullet
{
public:
	ExplosiveBullet(string bulletname, float speed, float firepower, float damagepower)
		: Bullet(bulletname, speed, firepower, damagepower)
	{
	}

	unique_ptr<Bullet> Clone() override
	{
		return make_unique<ExplosiveBullet>(*this);
	}
};

class BulletFactory
{
private:
	unordered_map<BulletType, unique_ptr<Bullet>, hash<BulletType> > mBullets;

public:
	BulletFactory()
	{
		mBullets[STANDARD] = make_unique<StandardBullet>("Standard Bullet", 50, 75, 75);
		mBullets[PIERCING] = make_unique<PiercingBullet>("Piercing Bullet", 75, 100, 60);
		mBullets[EXPLOSIVE] = make_unique<ExplosiveBullet>("Explosive Bullet", 60, 85, 90);
	}

	unique_ptr<Bullet> createBullet(BulletType BulletType)
	{
		return mBullets[BulletType]->Clone();
	}
};