#pragma once
#include"basic.hpp"

class EntityUnit;

class Entity {
public:
	Entity();
	virtual bool sound(EntityUnit selff);
	virtual IMAGE *render(EntityUnit selff);
	virtual bool attack(Pool<EntityUnit> a, Table b, EntityUnit selff);
	virtual bool skill(Pool<EntityUnit> a, Table b, EntityUnit selff);
	virtual bool motion(Pool<EntityUnit> a, Table b, EntityUnit selff);
	Entities getType()const;
	int getHealth()const;
	long getAttackInterval()const;
	long getSkillInterval()const;
protected:
	Entities type;
	int maxHealth;
	DWORD attackInterval;
	DWORD skillInterval;
	ResourceManager res;
};

class EntityUnit {
public:
	EntityUnit(Entity* refe);
	void refresh();
	int getCurrentHealth()const;
	int getVal(int index)const;
	int getAnimeType()const;
	DWORD getLastatk()const;
	DWORD getLastSkl()const;
	CycleLinkedList<IMAGE>::iterator getIterator();
	void changeCurHealth(int va);
	void setVal(int index, int va);
	void setLastAck(DWORD ti);
	void setLastSkl(DWORD ti);
	void setAnimeType(int val);
	Entity* getEntityRefer();
	void setAnimeIterator(CycleLinkedList<IMAGE>::iterator a);
private:
	int currentHealth;
	int val[3];
	DWORD lastAttack;
	DWORD lastSkill;
	Entity* refer;
	int animeFrame;
	int animeType;
	CycleLinkedList<IMAGE>::iterator currentAnimeIr;
};

class Pee:public Entity {
public:
	Pee();
	bool attack(Pool<EntityUnit> a, Table b);
	IMAGE *render(EntityUnit selff);
};

class SunPower :public Entity {
	SunPower();
	bool skill(int *a);
	bool motion(Pool<EntityUnit> a, Table b, EntityUnit selffa);
};




class Sunflower :public Entity {
public:
	static const int cost = 50;
	Sunflower();
	bool skill(Pool<EntityUnit> a,Table b,EntityUnit selff);
	IMAGE *render(EntityUnit selff);
};