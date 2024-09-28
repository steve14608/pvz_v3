#pragma once
#include"basic.hpp"

class EntityUnit;

class Entity {
public:
	Entity();
	virtual bool sound(EntityUnit selff);
	virtual IMAGE *render(EntityUnit selff);
	virtual bool attack(Pool<EntityUnit> *a, Table b, EntityUnit selff);
	virtual bool skill(Pool<EntityUnit> *a, Table b, EntityUnit selff);
	virtual bool motion(Pool<EntityUnit> *a, Table b, EntityUnit selff);
	virtual void initEntityUnit(EntityUnit& a);
	Entities getType()const;
	short getHealth()const;
	long getAttackInterval()const;
	long getSkillInterval()const;
protected:
	Entities type;
	short maxHealth;
	DWORD attackInterval;
	DWORD skillInterval;
	ResourceManager res;
};

class EntityUnit {
public:
	//EntityUnit(Entity* refe);
	//void refresh();
	void setRefer(Entity* refe);
	unsigned short getCurrentHealth()const;
	short getVal(byte index)const;
	byte getAnimeType()const;
	DWORD getLastatk()const;
	DWORD getLastSkl()const;
	void getPoi(byte* qposition,byte* qpoiInRow,byte* qrow);
	CycleLinkedList<IMAGE>::iterator getIterator();
	void changeCurHealth(short va);
	void setVal(byte index, int va);
	void setLastAck(DWORD ti);
	void setLastSkl(DWORD ti);
	void setAnimeType(byte val);
	Entity* getEntityRefer();
	void setAnimeIterator(CycleLinkedList<IMAGE>::iterator a);
	void setPoi(byte* qposition, byte* qpoiInRow, byte* qrow);
	bool changePoi(byte* qposition, byte* qpoiInRow, byte* qrow);
private:
	unsigned short currentHealth;
	short val[3];
	DWORD lastAttack;
	DWORD lastSkill;
	Entity* refer;
	byte animeFrame;
	byte animeType;
	byte row;
	byte poiInRow;
	byte position;
	CycleLinkedList<IMAGE>::iterator currentAnimeIr;
};

class Pee:public Entity {
public:
	Pee();
	bool attack(Pool<EntityUnit> *a, Table b);
};


class SunPower :public Entity {
	SunPower();
	bool skill(short *a);
	bool motion(Pool<EntityUnit> *a, Table b, EntityUnit selff);
	void initEntityUnit(EntityUnit& a);
};




class Sunflower :public Entity {
public:
	static const short cost = 50;
	Sunflower();
	bool skill(Pool<EntityUnit> *a,Table b,EntityUnit selff);
};