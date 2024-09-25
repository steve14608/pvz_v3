#pragma once
class Entity;
class Plants {
public:
	virtual bool attack();
	virtual bool skill();
	int getHealth()const;
	long getAttackInterval()const;
	long getSkillInterval()const;
};
class Zombies;
class Bullets;
