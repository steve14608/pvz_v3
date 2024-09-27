#include <graphics.h>
#include "entity.h"




Entity::Entity(){}

bool Entity::sound(EntityUnit selff) {
	return false;
}
IMAGE *Entity::render(EntityUnit selff) {
	return nullptr;
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



EntityUnit::EntityUnit(Entity* refe)
{
	refer = refe;
	refresh();
}

void EntityUnit::refresh()
{
	currentHealth = (*refer).getHealth();
	val[0] = 0;
	val[1] = 0;
	val[2] = 0;
	lastAttack = GameTickControl::getTick();
	lastSkill = lastAttack;
	animeFrame = 0;
	animeType = -1;
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



bool SunPower::skill(int *a)
{
	*a += 25;
	return false;
}

bool SunPower::motion(Pool<EntityUnit> a, Table b, EntityUnit selffa)
{
	return false;
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
	if (GameTickControl::getTick() - selff.getLastSkl() > skillInterval) {

	}
}

IMAGE *Sunflower::render(EntityUnit selff)
{
	if (selff.getAnimeType() != 1) selff.setAnimeIterator(res.getPicSequence(1));
	return  &*selff.getIterator();
}


