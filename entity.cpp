#include <graphics.h>
#include "entity.h"




Entity::Entity(){}

bool Entity::sound(EntityUnit selff) {
	return false;
}
IMAGE *Entity::render(EntityUnit selff) {
	return  &*selff.getIterator();
}

bool Entity::attack(Pool<EntityUnit> a, Table b, EntityUnit selff)
{
	return false;
}

bool Entity::skill(Pool<EntityUnit> a, Table b, EntityUnit selff)
{
	return false;
}

bool Entity::motion(Pool<EntityUnit> a, Table b, EntityUnit selff)
{
	return false;
}

void Entity::initEntityUnit(EntityUnit& a)
{
	a.setAnimeType(1);
	a.setAnimeIterator(res.getPicSequence(1));
	a.setLastAck(GameRunTime::getTick());
	a.setLastSkl(GameRunTime::getTick());
}

Entities Entity::getType() const
{
	return Entities();
}
int Entity::getHealth() const
{
	return maxHealth;
}
long Entity::getAttackInterval() const
{
	return attackInterval;
}
long Entity::getSkillInterval() const
{
	return 0;
}



//EntityUnit::EntityUnit(Entity* refe)
//{
//	refer = refe;
//	refresh();
//}

//void EntityUnit::refresh()
//{
//	currentHealth = (*refer).getHealth();
//	val[0] = 0;
//	val[1] = 0;
//	val[2] = 0;
//	lastAttack = GameRunTime::getTick();
//	lastSkill = lastAttack;
//	animeFrame = 0;
//	animeType = -1;
//}

void EntityUnit::setRefer(Entity* refe)
{
	refer = refe;
	refer->initEntityUnit(*this);
}

int EntityUnit::getCurrentHealth() const
{
	return currentHealth;
}

int EntityUnit::getVal(int index) const
{
	return val[index];
}

int EntityUnit::getAnimeType() const
{
	return animeType;
}



DWORD EntityUnit::getLastatk() const
{
	return lastAttack;
}

DWORD EntityUnit::getLastSkl() const
{
	return lastSkill;
}

void EntityUnit::getPoi(int* qposition, int* qpoiInRow, int* qrow)
{
	if (qposition != NULL) *qposition = position;
	if (qpoiInRow != NULL) *qpoiInRow = poiInRow;
	if (qrow != NULL)*qrow = row;

}


CycleLinkedList<IMAGE>::iterator EntityUnit::getIterator()
{
	return currentAnimeIr++;
}

void EntityUnit::changeCurHealth(int va)
{
	currentHealth += va;
}

void EntityUnit::setVal(int index, int va)
{
	val[index] = va;
}

void EntityUnit::setLastAck(DWORD ti)
{
	lastAttack = ti;
}

void EntityUnit::setLastSkl(DWORD ti)
{
	lastAttack = ti;
}

void EntityUnit::setAnimeType(int val)
{
	animeType = val;
}

Entity* EntityUnit::getEntityRefer()
{
	return nullptr;
}

void EntityUnit::setAnimeIterator(CycleLinkedList<IMAGE>::iterator a)
{
	currentAnimeIr = a;
}

void EntityUnit::setPoi(int* qposition, int* qpoiInRow, int* qrow)
{
	if (qposition != NULL) position = *qposition;
	if (qpoiInRow!= NULL)poiInRow = *qpoiInRow;
	if (qrow != NULL) row = *qrow;
}
//to-do,加个边界检测，出界就返回false
bool EntityUnit::changePoi(int* qposition, int* qpoiInRow, int* qrow)
{
	int a=0, b=0, c = 0;
	if (qposition != NULL) a = *qposition;
	if (qpoiInRow != NULL)b = *qpoiInRow;
	if (qrow != NULL) c = *qrow;
	position += a;
	row+=c;
	if (poiInRow + c < 0)row--;
	else if (poiInRow + c > 10)row++;
	poiInRow = (poiInRow + 10 + c) % 10;
	return false;
}

Pee::Pee()
{
}

bool Pee::attack(Pool<EntityUnit> a, Table b)
{
	return false;
}


SunPower::SunPower() {
	type = Entities::SunPower;
	res.init("SunPower");
}
bool SunPower::skill(int *a)
{
	*a += 25;
	return false;
}

bool SunPower::motion(Pool<EntityUnit> a, Table b, EntityUnit selff)
{
	int z = GameRunTime::getTick() - selff.getLastSkl();
	int aa, bb;
	if (z < 12&&z%2==0) {
		aa = 1;
		bb = -2;
		selff.changePoi(&aa, &bb, NULL);
	}
	else if (z >= 12 && z < 18 && z % 2 == 0) {
		aa = 1;
		bb = 1;
		selff.changePoi(&aa, &bb, NULL);
	}
	return true;
}

void SunPower::initEntityUnit(EntityUnit& a)
{
	Entity::initEntityUnit(a);
	a.setVal(0, GameRunTime::getTick() % 2 == 0 ? 1 : -1);
}



Sunflower::Sunflower()
{
	maxHealth = 10;
	type = Entities::Sunflower;
	skillInterval = 30;
	res.init("Sunflower");
}

bool Sunflower::skill(Pool<EntityUnit> a, Table b, EntityUnit selff)
{
	if (GameRunTime::getTick() - selff.getLastSkl() > skillInterval) {
		//
	}
}



