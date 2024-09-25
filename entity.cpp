#include "basic.hpp"
#include <graphics.h>





//Father class
class Entity {
public:
	virtual bool sound() { return false; };//to-do
	virtual bool render() { return false; };//to-do
	virtual bool attack(Pool<EntityUnit> a,Table b) { return false; };//to-do
	virtual bool skill(Pool<EntityUnit> a, Table b) { return false; };//to-do
	virtual bool motion(Pool<EntityUnit> a, Table b) { return false; };//to-do
	Entities getType() const {
		return type;
	}
	int getHealth()const {
		return maxHealth;
	}
	long getAttackInterval()const {
		return attackInterval;
	}
	long getSkillInterval()const {
		return skillInterval;
	}
protected:
	Entities type;
	int maxHealth;
	DWORD attackInterval;
	DWORD skillInterval;
}
;











//units
class EntityUnit {
public:
	EntityUnit(Entity* refe) {
		refer = refe;
		refresh();
	}
	void refresh() {
		currentHealth = (*refer).getHealth();
		val[0] = 0;
		val[1] = 0;
		val[2] = 0;
		lastAttack = GameTickControl::getTick();
		lastSkill = lastAttack;
	}
	int getCurrentHealth()const {
		return currentHealth;
	}
	int getVal(int index)const {
		return val[index];
	}
	DWORD getLastAtk()const {
		return lastAttack;
	}
	DWORD getLastSkl()const {
		return lastSkill;
	}
	void changeCurHealth(int va) {
		currentHealth += va;
	}
	void setVal(int index,int va) {
		val[index] = va;
	}
	void setLastAck(DWORD ti) {
		lastAttack = ti;
	}
	void setLastSkl(DWORD ti) {
		lastSkill = ti;
	}
	Entity* getEntityRefer() {
		return refer;
	}
private:
	int currentHealth;
	int val[3];
	DWORD lastAttack;
	DWORD lastSkill;
	Entity* refer;
};












class Sunflower : public Entity {
public:
	Sunflower() {
		maxHealth = 10;
		type = Entities::Sunflower;
		skillInterval = 30;
	}
	bool skill(Pool<EntityUnit> a, Table b,EntityUnit selff) {
		if (GameTickControl::getTick() - selff.getLastSkl() > skillInterval) {

		}
	}
};



