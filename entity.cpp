#include "basic.h"
#include <graphics.h>



class EntityUnit;


//Father class
class Entity {
public:
	virtual bool attack(Pool<EntityUnit> pool ) { return false; };//to-do
	virtual bool skill() { return false; };//to-do
	virtual bool motion() { return false; };//to-do
	int getId() const {
		return id;
	}
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
	int id;
	Entities type;
	int maxHealth;
	long attackInterval;
	long skillInterval;
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
		val0 = 0;
		val1 = 0;
		val2 = 0;
		lastAttack = GetTickCount();
		lastSkill = GetTickCount();
	}
private:
	int currentHealth;
	int val0;
	int val1;
	int val2;
	long lastAttack;
	long lastSkill;
	Entity* refer;
};












class Sunflower : public Entity {
public:
	
};



